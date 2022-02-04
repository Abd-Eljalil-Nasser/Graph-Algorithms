#include<iostream>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::pair;
class vertix {
	int group;
	bool visited;
	list<int>neighbours;
public:
	vertix();
	vertix(int number, bool visited);
	void SetNumber(int input);
	int  GetGroupNumber();
	void SetVisited(bool input);
	bool GetVisited();
	void SetNeighbour(int value);
	list<int>::iterator GetFirstNeighbour();
	list<int>::iterator GetLastNeighbour();
	int GetNeighboursSize();
};
vertix::vertix() : group{ 0 }, visited{ false }
{}
vertix::vertix(int num, bool visit) : group{ num }, visited{ visit }
{}
void vertix::SetNumber(int input) {
	group = input;
}
int vertix::GetGroupNumber() {
	return group;
}
void vertix::SetVisited(bool input) {
	visited = input;
}
bool vertix::GetVisited() {
	return visited;
}
void vertix::SetNeighbour(int value) {
	neighbours.push_back(value);
}
list<int>::iterator vertix::GetFirstNeighbour() {
	return neighbours.begin();
}
list<int>::iterator vertix::GetLastNeighbour()
{
	return neighbours.end();
}
int vertix::GetNeighboursSize() {
	return neighbours.size();
}
void explore(vector<vertix>& graph, vertix& V, int component) {
	V.SetVisited(true);
	V.SetNumber(component);

	for (auto Neighbours_iterator = V.GetFirstNeighbour(); Neighbours_iterator != V.GetLastNeighbour(); Neighbours_iterator++)
	{
		if (V.GetGroupNumber() != 0)
		{
			if (graph[*Neighbours_iterator].GetVisited() == false) {
				explore(graph, graph[*Neighbours_iterator], component);

			}
		}
	}
}
void DFS(vector<vertix>& graph) {
	int value = 1;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].GetVisited() == false)
		{
			explore(graph, graph[i], value);
			value++;
		}

	}
}

int main() {

	size_t n, m;
	std::cin >> n >> m;
	vector<vertix> graph(n);
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		graph[x - 1].SetNeighbour(y - 1);
		graph[y - 1].SetNeighbour(x - 1);
	}
	DFS(graph);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (graph[i].GetGroupNumber() > max)
		{
			max = graph[i].GetGroupNumber();
		}
	}
	std::cout << max;

}