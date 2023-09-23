#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int left, right;
    int parent;
    int depth;
    int order;
};

int n, node_num = 1;
vector<Node> tree;
vector<int> level_min, level_max;

void inorder(int node, int depth) {
    if (tree[node].left != -1) {
        inorder(tree[node].left, depth + 1);
    }
    tree[node].order = node_num++;
    tree[node].depth = depth;
    if (tree[node].right != -1) {
        inorder(tree[node].right, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    tree.resize(n + 1);
    level_min.resize(n + 1, n);
    level_max.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int node, left, right;
        cin >> node >> left >> right;
        tree[node].left = left;
        tree[node].right = right;
        if (left != -1) {
            tree[left].parent = node;
        }
        if (right != -1) {
            tree[right].parent = node;
        }
    }

    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0) {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    for (int i = 1; i <= n; i++) {
        int depth = tree[i].depth;
        int order = tree[i].order;
        level_min[depth] = min(level_min[depth], order);
        level_max[depth] = max(level_max[depth], order);
    }

    int width_max = 0, width_max_level = 0;
    for (int i = 1; i <= n; i++) {
        int level_width = level_max[i] - level_min[i] + 1;
        if (width_max < level_width) {
            width_max = level_width;
            width_max_level = i;
        }
    }

    cout << width_max_level << ' ' << width_max << '\n';

    return 0;
}