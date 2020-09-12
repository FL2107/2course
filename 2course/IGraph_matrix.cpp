#include <vector>

using Vertex = int;

class IGraph {
public:
    virtual ~IGraph() {}

    virtual void AddEdge(Vertex from, Vertex to) = 0;

    virtual size_t GetGraphSize() const = 0;

    virtual const std::vector<size_t> GetAdj(Vertex vertex) const = 0;
};

class DirectedMatrixGraph : public IGraph {
private:
	std::vector<std::vector<Vertex>> graph;
public:
	DirectedMatrixGraph(size_t VertexCount) : graph(VertexCount, std::vector<Vertex>(VertexCount)) {}
	size_t GetGraphSize() const override { return graph.size(); }
	void AddEdge(Vertex from, Vertex to) override {
		if (from <= graph.size() && to <= graph.size()) {
			graph[from][to] = -1;
			graph[to][from] = 1;
		}
	}
	const std::vector<size_t> GetAdj(Vertex vertex) const override { 
		std::vector<size_t> adjacent;
		for (size_t i = 0; i < graph.size(); ++i) {
			if (graph[vertex][i] == -1)
				adjacent.push_back(i);
		}
		return adjacent;
	}
};
