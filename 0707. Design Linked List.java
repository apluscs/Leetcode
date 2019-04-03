class MyLinkedList {
    Node head, tail; //easy to append
    int length; //easy for checking out of bounds stuff
    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = new Node(-1);
        tail = head;
        length = 0; //head is a dummy
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int ind) {
        Node curr = head.next;
        int i = 0;
        while (i < ind && curr != null) {
            curr = curr.next;
            i++;
        }
        if (curr == null) return -1;
        return curr.val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        Node curr = new Node(val);
        curr.next = head.next;
        head.next = curr;
        if (curr.next == null) tail = curr;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        Node curr = new Node(val);
        tail.next = curr;
        tail = curr;
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int ind, int val) {
        if (ind == length) {
            addAtTail(val);
            return;
        }
        if (ind > length) return;
        Node curr = head;
        for (int i = 0; i != ind; i++) curr = curr.next;
        Node temp = new Node(val);
        temp.next = curr.next;
        curr.next = temp; //curr is node right before node to add
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int ind) {
        if (ind >= length) return;
        Node curr = head;
        for (int i = 0; i != ind; i++) curr = curr.next;
        if (curr.next.next == null) tail = curr; //deleted last node, second to last becomes tail
        curr.next = curr.next.next; //curr is the node right before node to delete
        length--;
    }
    class Node {
        int val;
        Node next;
        public Node(int val) {
            this.val = val;
            next = null;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
