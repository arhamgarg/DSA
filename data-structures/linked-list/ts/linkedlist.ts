/**
 * @file linkedlist.ts
 * @description Provides Userdefined LinkedList
 * @author JestiferHarold
 * @created 2025-07-15
 * 
 * This File Includes:
 * - LinkedList
 */

import { NewNode } from "../../Node/Node";
//@ts-ignore
import process from "node:process";

/**
 * Represnts a abstract data type LinkedList
 */
class LinkedList {

    /**
     * Pointer to the first node in the list 
     * @memberof LinkedList
     */
    private head: NewNode | null;

    /**
     * initilizes a new LinkedList object
     * @param head the first object in the linked list
     */
    constructor(head: NewNode | null) {
        this.head = head;
    }

    /**
     * gets the head of the list without removing it
     * @returns the object of the first node in list or null if the list is empty
     */
    getHead(): NewNode | null {
        return this.head;
    }

    /**
     * 
     * @returns 
     */
    getTail(): NewNode | null {
        if (this.head == null) return null;

        let n: NewNode | null | undefined = this.head;
        for (; n?.getNextNode() != null ; n = n?.getNextNode());
        return n;
    }

    /**
     * 
     * @returns 
     */
    popFront(): NewNode | null {
        if (this.head == null) return null;

        let n: NewNode | null = this.head;
        this.head = this.head.getNextNode();
        return n;
    }

    /**
     * 
     * @returns 
     */
    popBack(): NewNode | null {
        if (this.head == null) return null;

        let n: NewNode | null | undefined= this.head;
        for (; n?.getNextNode()?.getNextNode() != null; n = n?.getNextNode());
        //@ts-ignore
        let temp: NewNode = n.getNextNode();
        //@ts-ignore
        n.setNextNode(null);
        return temp;
    }

    /**
     * 
     * @param value 
     */
    pushFront(value: number): void {
        let n: NewNode = new NewNode(value, this.head);
        this.head = n;
    }

    /**
     * 
     * @param value 
     */
    pushBack(value: number): void {
        let n: NewNode = new NewNode(value);
        let m: NewNode | null = this.head;
        for (; m?.getNextNode() != null; m = m?.getNextNode());
        m?.setNextNode(n);
    }

    /**
     * 
     * @param value 
     * @param position 
     * @returns void
     */
    insert(value: number, position: number): void {
        let n: number = this.size();
        if (position >= n || position < 0) return console.log("invalid postion");

        if (position == n - 1) return this.pushBack(value);

        if (position == 0) return this.pushFront(value);

        let nod: NewNode = new NewNode(value);
        let i: number = 0;
        let temp: NewNode | null = this.head;
        //@ts-ignore
        for (; i != position - 1 || temp != null; temp = temp.getNextNode(), i ++);
        
        if (temp == null || temp == undefined) return;

        //@ts-ignore
        temp.setNextNode(nod);
    }

    /**
     * Checks if a node with the key is present in the list
     * @param key integer value to be found  
     * @returns true if the node with the passed key is avaiable, else false
     */
    search(key: number): boolean {
        if (this.head == null) return false;

        let n: NewNode | null = this.head;
        
        for (; n != null; n = n.getNextNode()) 
            if (n.getValue() == key) return true;
        
        return false;
    }

    /**
     * prints the list in the console
     */
    printList(): void {
        for (let n: NewNode | null = this.head; n != null; n = n.getNextNode());
            //@ts-ignore
            process.std.write(`${n.getValue()} ->`);
        //@ts-ignore
        process.std.write("\n");
    }

    /**
     * gets the size of the list
     * @returns the number of nodes there in the list
     */
    size(): number {
        let i: number = 0;
        for (let node: NewNode | null = this.head; node != null; node = node.getNextNode(), i ++);
        return i;
    }

    
}

export {
    LinkedList
} 