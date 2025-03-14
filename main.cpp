#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ifstream file("graph.txt");
    if (!file) {
        cerr << "Error: can not open <graph.txt> file!" << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;

    vector<vector<int>> edges(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        file >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int s;
    file >> s;

    vector<int> d(n, INT_MAX);

    d[s] = 0;

    std::queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : edges[v]) {
            if (d[u] == INT_MAX) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    for (int dist : d) {
        cout << dist << endl;
    }

    return 0;
}