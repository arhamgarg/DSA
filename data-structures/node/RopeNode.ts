/**
 * @file RopeNode.ts
 * @description Provides Userdefined RopeNode
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - RopeNode
 */

/**
 * represents a node with a forward and a backward pointer
 */
class RopeNode {
    
    /**
     * Integer value stored by the node 
     * @memberof RopeNode
     */
    private value: number;

    /**
     * Pointer to the next node
     * @memberof RopeNode
     */
    private nextNode: RopeNode | null;

    /**
     * Pointer to the previous node
     * @memberof RopeNode
     */
    private previousNode: RopeNode | null;

    /**
     * Inilializes the RopeNode Object
     * @param value integer value that is to be stored in the node
     * @param nextNode object of nextnode which is to be forward pointed
     * @param previousNode object of nextnode which is to be backwards pointed
     */
    constructor(value: number, nextNode: RopeNode | null = null, previousNode: RopeNode | null = null) {
        this.value = value;
        this.nextNode = nextNode;
        this.previousNode = previousNode;
    }

    /**
     * getter for value member
     * @returns the integer value stored in the node
     */
    getValue(): number {
        return this.value;
    }

    /**
     * gives the successive node of the this ropenode
     * @returns successive ropenode object if present, else null
     */
    getNextNode(): RopeNode | null {
        return this.nextNode;
    }

    /**
     * gives the previous node of the this ropenode
     * @returns previous ropenode object if present, else null
     */
    getPreviousNode(): RopeNode | null {
        return this.previousNode;
    }

    /**
     * sets the previous node member to the passed value
     * @param node ropenode object
     */
    setNextNode(node: RopeNode | null): void {
        this.nextNode = node;
    } 

    /**
     * sets the previous node member to the passed value
     * @param node ropenode object
     */
    setPreviousNode(node: RopeNode | null): void {
        this.previousNode = node;
    }
}   

export {
    RopeNode
}