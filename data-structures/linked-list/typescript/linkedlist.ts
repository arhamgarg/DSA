class LLNode {
    
    private value: number;
    private nextNode: LLNode | null;
 
    constructor(value: number, nextNode: LLNode | null) {
        this.value = value;
        this.nextNode = nextNode;
    }

    getValue(): number {
        return this.value;
    }

    getNextNode(): LLNode | null {
        return this.nextNode;
    }

    setValue(value: number): void {
        this.value = value;
    }

    setNextNode(node: LLNode): void {
        this.nextNode = node;
    }
}

class LinkedList {
    private head: LLNode | null;

    constructor(head: LLNode | null) {
        this.head = head;
    }

    getHead(): LLNode | null {
        return this.head;
    }

    size(): number {
        let i: number = 0;
        for (let node: LLNode | null = this.head; node != null; node = node.getNextNode(), i ++);
        return i;
    }

    
}