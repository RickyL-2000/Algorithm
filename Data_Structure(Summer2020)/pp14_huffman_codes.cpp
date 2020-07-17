#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct Node {
    pair<Node*, Node*> child = make_pair(nullptr, nullptr);
    int weight;
    char val;
    bool isVal = false;
    Node(char v, int w) {
        weight = w;
        val = v;
        isVal = true;
    }
    Node () {}
};

void dfs(Node* root, int height, int &sum) {
    if (root->child.first && root->child.second) {
        dfs(root->child.first, height+1, sum);
        dfs(root->child.second, height+1, sum);
    } else if (root->isVal) {
        sum += height * root->weight;
    }
}

int main() {
    int n, num;
    char alpha;
    scanf("%d", &n);
    vector<pair<char, int>> nums;
    auto cmp = [](Node* a, Node* b) {
                    return a->weight > b->weight;   // 小顶堆
                };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        cin >> alpha >> num;
        nums.push_back(make_pair(alpha, num));
        pq.push(new Node(alpha, num));
    }
    // sort(nums.begin(), nums.end(), [](pair<char, int> &a, pair<char, int> &b) {
    //     return a.second > b.second;     // 降序
    // });
    while (pq.size() > 1) {
        Node *node1, *node2;
        node1 = pq.top(), pq.pop();
        node2 = pq.top(), pq.pop();
        Node* newNode = new Node();
        newNode->weight = node1->weight + node2->weight;
        newNode->child = make_pair(node1, node2);
        pq.push(newNode);
    }
    Node *root = pq.top();
    pq.pop();

    int min_sum = 0;
    dfs(root, 0, min_sum);

    int m;
    scanf("%d", &m);
    vector<string> ans;
    vector<pair<char, string>> input;
    string str;
    for (int i = 0; i < m; i++) {
        input.clear();
        for (int j = 0; j < n; j++) {
            cin >> alpha >> str;
            input.push_back(make_pair(alpha, str));
        }
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (input[j].second.length()) * nums[j].second;
        }
        if (sum > min_sum) {
            ans.push_back("No");
            continue;
        }
        sort(input.begin(), input.end(), [](pair<char, string> &a, pair<char, string> &b) {
            return a.second < b.second;     // 升序排序
        });
        bool flag = false;
        for (int j = 0; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (input[k].second.substr(0, input[j].second.length()) == input[j].second) {
                    ans.push_back("No");
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) continue;
        ans.push_back("Yes");
    }
    for (auto e : ans) {
        cout << e << endl;
    }
    return 0;
}