/**
 * @file Node.ts
 * @description Provides User defined node
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - Node
 */

/**
 * Represents a Node
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
    constructor (value: number, nextNode: NewNode | null  = null) {
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

export {
    NewNode
}