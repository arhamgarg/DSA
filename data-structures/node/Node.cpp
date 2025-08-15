class Node {
private:
    int value;     // Node's value
    Node* nextNode; // Pointer to the next node

public:
    // Constructor
    Node(int val, Node* next = nullptr) {
        value = val;
        nextNode = next;
    }

    // Getter for value
    int getValue() const {
        return value;
    }

    // Getter for next node
    Node* getNextNode() const {
        return nextNode;
    }

    // Setter for next node
    void setNextNode(Node* next) {
        nextNode = next;
    }
};