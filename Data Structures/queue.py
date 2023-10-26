# para as Queues, nós podemos usar o .append() e o pop(0), para seguir o princípio FIFO, assim, a implementação é bem simples e pode ser feita só com a lista
# entretanoto, como as listas são feitas para serem rápidas no final, usar pop(0) não é muito eficiente, assim, podemos usar a lib collections import deque
class Queue:

    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)
    
    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)
    
    def display(self):
        print(self.queue)

    def size(self):
        return len(self.queue)

q = Queue()
for i in range(4):
    q.enqueue(i)
q.display()
q.dequeue()
q.dequeue()
q.display()