#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    // DFS untuk mencari semua node yang terhubung
    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (int tetangga : graph[node]) {

            if (!visited[tetangga]) {
                dfs(tetangga, graph, visited);
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {

        int n = properties.size();

        // adjacency list graph
        vector<vector<int>> graph(n);

        // Membuat edge antar node
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                unordered_set<int> s;

                // simpan isi properties[i]
                for (int x : properties[i]) {
                    s.insert(x);
                }

                int sama = 0;

                // hitung angka yang sama
                for (int x : properties[j]) {

                    if (s.count(x)) {
                        sama++;
                    }
                }

                // jika angka sama >= k
                // hubungkan node
                if (sama >= k) {

                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);

        int jumlahKomponen = 0;

        // Hitung connected component
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                dfs(i, graph, visited);

                jumlahKomponen++;
            }
        }

        return jumlahKomponen;
    }
};

int main() {

    vector<vector<int>> properties = {
        {1,2},
        {1,1},
        {3,4},
        {4,5},
        {5,6},
        {7,7}
    };

    int k = 2;

    Solution s;

    cout << "Jumlah Connected Component: "
         << s.numberOfComponents(properties, k);

    return 0;
}