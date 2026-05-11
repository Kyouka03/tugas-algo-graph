#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// DFS
void dfs(int node) {

    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {

        int tetangga = graph[node][i];

        if (visited[tetangga] == false) {
            dfs(tetangga);
        }
    }
}

int main() {

    vector<vector<int>> properties = {
        {1,2},
        {1,1},
        {3,4},
        {4,5},
        {5,6},
        {7,7}
    };

    int k = 1;

    int n = properties.size();

    // Membuat graph
    graph.resize(n);

    // Membandingkan semua node
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int sama = 0;

            // cek angka yang sama
            for (int a = 0; a < properties[i].size(); a++) {

                for (int b = 0; b < properties[j].size(); b++) {

                    if (properties[i][a] == properties[j][b]) {
                        sama++;
                        break;
                    }
                }
            }

            // jika memenuhi syarat
            if (sama >= k) {

                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // semua node awalnya belum dikunjungi
    visited.resize(n, false);

    int jumlahKomponen = 0;

    // hitung connected component
    for (int i = 0; i < n; i++) {

        if (visited[i] == false) {

            dfs(i);

            jumlahKomponen++;
        }
    }

    cout << "Jumlah Connected Component = "
         << jumlahKomponen;

    return 0;
}