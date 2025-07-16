/**
 * @file Queue.ts
 * @description Provides Userdefined queue
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - Queue
 */

import { NewNode } from "../../Node/Node";
//@ts-ignore
import { process } from "node:process";

/**
 * Represents an abstract data type Queue using linked list 
 */
class Queue {
    
    /**
     * Pointer to the first node in the queue
     * @memberof Queue
     */
    private front: NewNode | null;

    /**
     * Initializes the Class Queue
     * @param front NewNode object that is to be the first element in the queue or null, defaulted to null
     */
    constructor (front: NewNode | null = null) {
        this.front = front;
    }

    /**
     * returns the first node without removing 
     * @returns NewNode object if the queue is not null, else null
     */
    getFront(): NewNode | null {
        return this.front;
    }

    /**
     * addes an node object at the end of the queue
     * @param node NewNode object to be added at the end of the queue
     */
    enQueue(node: NewNode): void {
        let n: NewNode | null = this.front;
        for (; n?.getNextNode() != null; n = n.getNextNode());
        node.setNextNode(null);
        n?.setNextNode(node);
    }

    /**
     * removes and returns the first element in the queue
     * @returns the front node object otherwise null
     */
    deQueue(): NewNode | null {
        if (this.front == null) {
            return null;
        }
        //@ts-ignore
        let n: NewNode = this.front;
        this.front = this.front.getNextNode();
        return n;
    }

    /**
     * counts the number of elements in the queue
     * @returns number of nodes present in the queue
     */
    size(): number {
        let i: number = 0;
        for (let n: NewNode | null = this.front; n != null; n = n.getNextNode(), i++);
        return i;
    }

    /**
     * checks if the queue is empty
     * @returns true if the front element is empty, false
     */
    isEmpty(): boolean {
        return this.front == null;
    }

    /**
     * prints the queue in the console
     */
    display(): void {
        let n: NewNode | null = this.front;
        for (; n?.getNextNode() != null; n = n.getNextNode())
            //@ts-ignore
            process.std.write(`${n.getValue()} <- `);
        //@ts-ignore
        process.std.write();
    }

}

export {
    Queue
} 