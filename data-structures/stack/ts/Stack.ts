/**
 * @file Stack.ts
 * @description Provides Userdefined stack 
 * @author JestiferHarold
 * @created 2025-07-14
 * 
 * This File Includes:
 * - Stack
 */

import { NewNode } from "../../Node/Node";
//@ts-ignore
import { process } from "node:process";

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

    display(): void {
        let n: NewNode | null = this.head;
        for (; n?.getNextNode() != null; n = n.getNextNode())
            //@ts-ignore
            process.std.write(`${n.getValue()} -> `);
        //@ts-ignore
        process.std.write();
    }
}

export {
    Stack
}