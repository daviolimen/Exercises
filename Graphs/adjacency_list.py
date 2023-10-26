# Para implementar uma adjacency list em python, basta usar um dicionário com os vértices e as arestas

adj_list = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1, 3],
    3: [2]
}

# Também é possível fazer isso usando classes, exemplo:


class Vertex:
    def __init__(self, vertex_id):
        self.id = vertex_id
        self.adjacent_vertices = []


class Graph:
    def __init__(self):
        self.vertices = {}
    
    def add_vertex(self, vertex_id):
        new_vertex = Vertex(vertex_id)
        self.vertices[vertex_id] = new_vertex

    def add_edge(self, v1, v2):
        if v1 in self.vertices and v2 in self.vertices:
            self.vertices[v1].adjacent_vertices.append(v2)
            self.vertices[v2].adjacent_vertices.append(v1)


g = Graph()
g.add_vertex(0)
g.add_vertex(1)
g.add_vertex(2)
g.add_vertex(3)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 3)

