from collections import deque

queue = deque([1, 2, 3, 4, 5, 6, 7])
queue.append(8)
queue.append(9)
queue.popleft()
queue.popleft()
print(queue)