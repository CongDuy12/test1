#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream infile("Graph1.txt"); // m? file d? d?c d? li?u

    int n; // s? d?nh
    infile >> n;

    vector<vector<int> > adj_matrix(n, vector<int>(n)); // ma tr?n k?
    vector<int> in_degree(n, 0); // b?c vào c?a các d?nh
    vector<int> out_degree(n, 0); // b?c ra c?a các d?nh

    // d?c d? li?u ma tr?n k? t? file vào ma tr?n k? và tính b?c vào/ra c?a các d?nh
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> adj_matrix[i][j];
            if (adj_matrix[i][j] == 1) {
                out_degree[i]++;
                in_degree[j]++;
            }
        }
    }

    // in ra ma tr?n k? và b?c vào/ra c?a các d?nh
    cout << "Adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "In-degrees of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i+1 << ": " << in_degree[i] << endl;
    }

    cout << "Out-degrees of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i+1 << ": " << out_degree[i] << endl;
    }

    infile.close(); // dóng file
    return 0;
}

