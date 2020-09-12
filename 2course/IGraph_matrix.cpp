#include <vector>

using Vertex = int;

class IGraph {  //Интерфейс графа
public:
    virtual ~IGraph() {}    //Виртуальный деструктор чтобы при удалении по указателю не было утечки памяти

    //Добавить ребро выходящее из вершины from и ведущее в вершину to
    virtual void AddEdge(Vertex from, Vertex to) = 0;   //чисто виртуальная функция (не имеет реализации в этом классе

    //получить кол-во вершин в графе
    virtual size_t GetGraphSize() const = 0;

    //Получить вектор всех вершин в которые можно попасть по ребру из вершины vertex
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
