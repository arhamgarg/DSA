#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct QNode
{
    TreeNode *data;
    struct QNode *next;
} QNode;

typedef struct
{
    QNode *head, *tail;
    int count;
} Queue;

/* ---------- Queue (linked-list) ---------- */
void q_init(Queue *q)
{
    q->head = q->tail = NULL;
    q->count = 0;
}

int q_is_empty(Queue *q) { return q->count == 0; }

void q_enqueue(Queue *q, TreeNode *node)
{
    QNode *n = (QNode *)malloc(sizeof(QNode));
    n->data = node;
    n->next = NULL;
    if (q->count == 0)
    {
        q->head = q->tail = n;
    }
    else
    {
        q->tail->next = n;
        q->tail = n;
    }
    q->count++;
}

TreeNode *q_dequeue(Queue *q)
{
    if (q->count == 0)
        return NULL;
    QNode *h = q->head;
    TreeNode *val = h->data;
    q->head = h->next;
    free(h);
    q->count--;
    if (q->count == 0)
        q->tail = NULL;
    return val;
}

/* ---------- Tree helpers ---------- */
TreeNode *new_node(int d)
{
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    n->data = d;
    n->left = n->right = NULL;
    return n;
}

// Build from preorder array with -1 as null sentinel
TreeNode *build_tree(int *arr, int n, int *idx)
{
    (*idx)++;
    if (*idx >= n || arr[*idx] == -1)
        return NULL;
    TreeNode *node = new_node(arr[*idx]);
    node->left = build_tree(arr, n, idx);
    node->right = build_tree(arr, n, idx);
    return node;
}

void pre_order(TreeNode *r)
{
    if (!r)
        return;
    printf("%d ", r->data);
    pre_order(r->left);
    pre_order(r->right);
}

void post_order(TreeNode *r)
{
    if (!r)
        return;
    post_order(r->left);
    post_order(r->right);
    printf("%d ", r->data);
}

void in_order(TreeNode *r)
{
    if (!r)
        return;
    in_order(r->left);
    printf("%d ", r->data);
    in_order(r->right);
}

void level_order(TreeNode *r)
{
    if (!r)
    {
        printf("\n");
        return;
    }
    Queue q;
    q_init(&q);
    q_enqueue(&q, r);
    while (!q_is_empty(&q))
    {
        TreeNode *n = q_dequeue(&q);
        printf("%d ", n->data);
        if (n->left)
            q_enqueue(&q, n->left);
        if (n->right)
            q_enqueue(&q, n->right);
    }
    printf("\n");
}

int height(TreeNode *r)
{
    if (!r)
        return 0;
    int lh = height(r->left), rh = height(r->right);
    return (lh > rh ? lh : rh) + 1;
}

int depth(TreeNode *r, int value)
{
    if (!r)
        return -1;
    if (r->data == value)
        return 0;
    int left = depth(r->left, value);
    if (left != -1)
        return left + 1;
    int right = depth(r->right, value);
    if (right != -1)
        return right + 1;
    return -1;
}

TreeNode *find_node(TreeNode *r, int value)
{
    if (!r)
        return NULL;
    if (r->data == value)
        return r;
    TreeNode *L = find_node(r->left, value);
    if (L)
        return L;
    return find_node(r->right, value);
}

int add_child(TreeNode *r, int parent, int child)
{
    TreeNode *p = find_node(r, parent);
    if (!p)
        return 0;
    TreeNode *c = new_node(child);
    if (!p->left)
    {
        p->left = c;
        return 1;
    }
    if (!p->right)
    {
        p->right = c;
        return 1;
    }
    free(c);
    return 0;
}

int find_height_subtree(TreeNode *r, int value)
{
    TreeNode *n = find_node(r, value);
    return n ? height(n) : -1;
}

TreeNode *find_common_ancestor(TreeNode *r, int a, int b)
{
    if (!r)
        return NULL;
    if (r->data == a || r->data == b)
        return r;
    TreeNode *L = find_common_ancestor(r->left, a, b);
    TreeNode *R = find_common_ancestor(r->right, a, b);
    if (L && R)
        return r;
    return L ? L : R;
}

int check_complete_tree(TreeNode *r)
{
    if (!r)
        return 0;
    Queue q;
    q_init(&q);
    q_enqueue(&q, r);
    int end = 0;
    while (!q_is_empty(&q))
    {
        TreeNode *n = q_dequeue(&q);
        if (n->left)
        {
            if (end)
                return 0;
            q_enqueue(&q, n->left);
        }
        else
        {
            end = 1;
        }
        if (n->right)
        {
            if (end)
                return 0;
            q_enqueue(&q, n->right);
        }
        else
        {
            end = 1;
        }
    }
    return 1;
}

// Delete node by value; replace with deepest (last in level order)
TreeNode *delete_node(TreeNode *root, int value)
{
    if (!root)
        return NULL;
    if (!root->left && !root->right)
    {
        if (root->data == value)
        {
            free(root);
            return NULL;
        }
        return root;
    }

    Queue q;
    q_init(&q);
    q_enqueue(&q, root);

    TreeNode *node_to_delete = NULL;
    TreeNode *last = NULL;
    TreeNode *parent_of_last = NULL;

    while (!q_is_empty(&q))
    {
        last = q_dequeue(&q);
        if (last->data == value)
            node_to_delete = last;

        if (last->left)
        {
            parent_of_last = last;
            q_enqueue(&q, last->left);
        }
        if (last->right)
        {
            parent_of_last = last;
            q_enqueue(&q, last->right);
        }
    }

    if (!node_to_delete)
    {
        printf("Value not found in tree\n");
        return root;
    }

    // Replace value
    node_to_delete->data = last->data;

    // Remove deepest child from its parent
    if (parent_of_last)
    {
        if (parent_of_last->left == last)
        {
            parent_of_last->left = NULL;
        }
        else if (parent_of_last->right == last)
        {
            parent_of_last->right = NULL;
        }
    }
    // free the detached deepest node
    free(last);

    return root;
}

/* ---------- Demo ---------- */
int main(void)
{
    // Python arr: [1,2,3,4,5,None,8,None,6,None,None,None,9,None,None,7,None]
    // Use -1 for None
    int arr[] = {1, 2, 3, 4, 5, -1, 8, -1, 6, -1, -1, -1, 9, -1, -1, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx = -1;
    TreeNode *root = build_tree(arr, n, &idx);

    printf("Pre-order:\n");
    pre_order(root);
    printf("\n");
    printf("Post-order:\n");
    post_order(root);
    printf("\n");
    printf("In-order:\n");
    in_order(root);
    printf("\n");
    printf("Level order:\n");
    level_order(root);

    root = delete_node(root, 2);

    printf("After deletion of 2:\n");
    level_order(root);

    printf("Height of Tree: %d\n", height(root));
    printf("Depth of 9: %d\n", depth(root, 9));

    TreeNode *f5 = find_node(root, 5);
    printf("Find Node 5: %s\n", f5 ? "5" : "Not found");

    printf("Add child 10 under 3: %s\n", add_child(root, 3, 10) ? "true" : "false");
    level_order(root);

    printf("Height of subtree rooted at 3: %d\n", find_height_subtree(root, 3));

    TreeNode *anc = find_common_ancestor(root, 6, 9);
    printf("Lowest Common Ancestor of 6 and 9: %s\n", anc ? "value printed below" : "None");
    if (anc)
        printf("%d\n", anc->data);

    printf("Is tree complete? %s\n", check_complete_tree(root) ? "true" : "false");

    return 0;
}
