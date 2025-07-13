/**
 * @file Stack.ts
 * @description Provides Userdefined stack and node
 * @author JestiferHarold
 * @created 2025-07-14
 * 
 * This File Includes:
 * - NewNode
 * - Stack
 */

/**
 * Represents a Node in a stack 
 */
class NewNode{ 

    /**
     * This is to store the value 
     * @memberof NewNode
     */
    private value: number;

    /**
     * This is to store the nextnode 
     * 
     * @memberof NewNode
     */
    private nextNode: NewNode | null;

    /**
     * Initializes a new instance of the NewNode class
     * @param value 
     * @param nextNode 
     */
    constructor (value: number, nextNode: NewNode | null) {
        this.value = value;
        this.nextNode = nextNode;
    }

    /**
     * gets the value stored by the node
     * @returns The number stored by the node
     */
    getValue(): number {
        return this.value;
    }

    /**
     * gets the nextnode
     * @returns the nextnode member, could be another newnode or null
     */
    getNextNode() : NewNode | null {
        return this.nextNode;
    }

    /**
     * sets the nextnode of the NewNode class
     * @param nextNode - an object of the NewNode or null
     * @return void
     */
    setNextNode(nextNode: NewNode | null): void {
        this.nextNode = nextNode;
    }
}

/**
 * Repesents an abstract data type Stack using Nodes
 */
class Stack {
   
    /**
     * Stores the first node of the list
     * @memberof Stack
     */
    private head: NewNode | null;

    /**
     * Stores the size of the stack
     * @memberof Stack
     */
    private size: number;

    /**
     * Initializes a new stack
     * @param head - the first node of the stack, could be null
     * @return void
     */
    constructor (head: NewNode | null = null) {
        this.head = head;
        this.size = 0;
    } 

    /**
     * gets the first node of the stack
     * @returns the top node of the stack, could be null
     */
    getHead(): NewNode | null {return this.head;}

    /**
     * gets the total number of nodes in the stack
     * @returns size of the stack
     */
    getSize(): number {return this.size;}

    /**
     * pushes a node to the top of the stack
     * @param node - the node to be pushed on top
     * @returns void
     */
    push(node: NewNode): void {
        node.setNextNode(this.head);
        this.head = node;
    }    

    /**
     * pops and returns the top node
     * @throws StackUnderflow Exception if the stack is empty
     * @returns the top node
     */
    pop(): NewNode {
        if (this.head == null) {
            throw Error("Stack UnderFlow Exception");
        }

        let poppedNode: NewNode = this.head;
        this.head = this.head.getNextNode();
        return poppedNode;
    }

    /**
     * returns the top node without removing it out of the stack
     * @throws StackUnderflow Exception if the stack is empty
     * @returns the top node of the stack
     */
    top(): NewNode {
        if (this.head == null) {
            throw Error("Stack UnderFlow Exception");
        }

        return this.head;
    }
}

export {
    NewNode,
    Stack
}