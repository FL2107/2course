#include <vector>
#include <iostream>
#include <queue>

using Vertex = size_t;

class IGraph { //интерфейс для любого графа
public:
	virtual ~IGraph() {}
	virtual void AddEdge(Vertex from, Vertex to) = 0;
	virtual size_t GetGraphSize() const = 0;
	virtual const std::vector<Vertex>& GetAdj(Vertex v) const = 0;
};

class UndirectedListGraph : public IGraph {
private:
	std::vector<std::vector<Vertex>> graph;
public:
	UndirectedListGraph(size_t VertexCount) : graph(VertexCount) {}
	size_t GetGraphSize() const override { return graph.size(); }
	void AddEdge(Vertex from, Vertex to) override {
		graph.at(from).push_back(to);
		graph.at(to).push_back(from);
	}
	const std::vector<Vertex>& GetAdj(Vertex v) const override { return graph.at(v); }
};

enum class Color {
	White,
	Blue,
	Red
};

bool IsTwoGendered(const IGraph& gr) {
	if (!gr.GetGraphSize())
		return true;
	std::vector<Color> colors(gr.GetGraphSize(), Color::White);
	std::queue<Vertex> q;
	q.push(0);
	colors[0] = Color::Red;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto v : gr.GetAdj(cur)) {
			if (colors[v] == colors[cur])
				return false;
			if (colors[v] == Color::White) {
				if (colors[cur] == Color::Red)
					colors[v] = Color::Blue;
				else
					colors[v] = Color::Red;
				q.push(v);
			}
		}
	}
	return true;
}

int main() {

}