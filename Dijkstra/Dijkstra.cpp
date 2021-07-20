#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int max_int = 2147483647;

struct dane
{
    int x, y, v;
};
bool compareX(dane d1, dane d2)
{
    return d1.x < d2.x;
}
bool compareY(dane d1, dane d2)
{
    return d1.y < d2.y;
}
class Graph
{
public:
	int V;
	list <pair<int, int>>* adj; // wierzcholek, waga
	Graph() = default;
	Graph(int V)
	{
		this->V = V;
		adj = new list<pair<int, int>>[V];
	}
	void addEdge(int v1, int v2, int weight)
	{
		adj[v1].push_back(make_pair(v2, weight));
		adj[v2].push_back(make_pair(v1, weight));
	}
	void dijkstra(int src, int dest)
	{
		/*int inf = INT_MAX;*/

		pair<int, int> temp; //wierzcholek, waga
		set<pair<int, int>> queue;
		vector<int> distances(V, max_int);
		
		queue.insert(make_pair(0, src));
		distances[src] = 0;
		
		while (!queue.empty())
		{
			temp = *(queue.begin());
			queue.erase(queue.begin());

			int u = temp.second;

			for (auto i = adj[u].begin(); i != adj[u].end(); i++)
			{
				int v = (*i).first;
				int weight = (*i).second;

				if (distances[v] > distances[u] + weight)
				{
					if (distances[v] != max_int) queue.erase(queue.find(make_pair(distances[v], v)));

					distances[v] = distances[u] + weight;
					queue.insert(make_pair(distances[v], v));
				}
			}
		}

		cout << distances[dest] << endl;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	int n, s, d;
    cin >> n;
	vector<dane> vec;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back(dane());
        vec[i].x = x;
        vec[i].y = y;
        vec[i].v = i;
    }
    cin >> s >> d;
	Graph* graph = new Graph(n);
    stable_sort(vec.begin(), vec.end(), compareX);
	for (int i = 1; i < n; i++) graph->addEdge(vec[i - 1].v, vec[i].v, abs(vec[i].x - vec[i - 1].x));
    stable_sort(vec.begin(), vec.end(), compareY);
	for (int i = 1; i < n; i++) graph->addEdge(vec[i - 1].v, vec[i].v, abs(vec[i].y - vec[i - 1].y));

	graph->dijkstra(s, d);

	/*int val = graph->getValue(1, 3);*/
	/*cout << val;*/
	delete graph;
	return 0;
}
