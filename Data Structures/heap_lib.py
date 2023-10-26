import heapq # essa lib implementa um min_heap, ou seja, os elementos vão do menor ao maior, para implementar uma max_heap, o valor deve ser negado

heap = []

heapq.heappush(heap, 1)
heapq.heappush(heap, 2)
heapq.heappush(heap, 3)
heapq.heappush(heap, 4)
heapq.heappush(heap, 5)
heapq.heappush(heap, 6)
heapq.heappush(heap, 7)
heapq.heappush(heap, 8)

print(str(heap))

heapq.heappop(heap)
heapq.heappop(heap)
print(str(heap))

max_heap = []
heapq.heappush(max_heap, -1)
heapq.heappush(max_heap, -2)
heapq.heappush(max_heap, -3)
heapq.heappush(max_heap, -4)
heapq.heappush(max_heap, -5)
heapq.heappush(max_heap, -6)
heapq.heappush(max_heap, -7)
heapq.heappush(max_heap, -8)

print(str(max_heap)) # na hora de recolher o valor de um elemento, basta deixá-lo negativo novamente para que ele volte ao normal