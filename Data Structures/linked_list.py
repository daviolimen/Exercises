# aqui, nós mesmos criamos nossa própria LinkedList, entretanto, Python tem uma lib que já faz isso, basta usar from collections import deque, o método deque cria uma
# LinkedList, em que podem ser feitas operações tanto na direita quanto na esquerda

class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def push_front(self, new_data):
        new_node = Node(new_data, self.head)
        self.head = new_node

    def insert_after(self, prev_node, new_data):
        if prev_node == None:
            # that means the node is not in the LinkedList, so:
            return
        new_node = Node(new_data, prev_node.next)
        prev_node.next = new_node

    def push_back(self, new_data):
        new_node = Node(new_data)
        if self.head == None:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
    
    def pop_front(self):
        self.head = self.head.next
    
    def pop_back(self):
        last = self.head
        while last.next.next:
            last = last.next
        last.next = None
    
    def exclude(self, position):
        itr = self.head
        for i in range(2, position):
            if itr.next:
                itr = itr.next
        itr.next = itr.next.next

    def reverse(self):
        prev = None
        current = self.head
        next = None
        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev
        

    def print(self):
        current = self.head
        llstr = ''
        while current:
            llstr += str(current.data) + '-->'
            current = current.next
        print(llstr)


if __name__ == '__main__':
    ll = LinkedList()
    ll.push_back(1)
    ll.push_back(2)
    ll.push_back(3)
    ll.push_front(5)
    ll.push_front(6)
    ll.push_front(7)
    ll.print()
    ll.pop_front()
    ll.pop_back()
    ll.exclude(3)
    ll.print()
    ll.reverse()
    ll.print()