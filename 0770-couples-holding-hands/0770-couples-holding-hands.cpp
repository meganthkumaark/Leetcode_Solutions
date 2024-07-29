class UnionFind {
public:
    UnionFind(int n) : count(n), parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionByRank(int u, int v) {
        int i = find(u);
        int j = find(v);
        if (i != j) {
            if (rank[i] < rank[j]) {
                swap(i, j);
            }
            parent[j] = i;
            if (rank[i] == rank[j]) {
                rank[i]++;
            }
            count--;
        }
    }

    int getCount() const {
        return count;
    }

private:
    int count;
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        const int n = row.size() / 2;
        UnionFind uf(n);

        for (int i = 0; i < n; ++i) {
            const int a = row[2 * i];
            const int b = row[2 * i + 1];
            uf.unionByRank(a / 2, b / 2);
        }

        return n - uf.getCount();
    }
};
