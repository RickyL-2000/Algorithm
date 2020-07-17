#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Person {
    int _id, _m_est, _area;
    bool _isNode;   // maybe no need
};
struct Family {
    vector<int> _member;
    int _id = 9999, _num;
    double _avg_sets = 0.0, _avg_area = 0.0;
};
int n;
Person* forest[1010];
int edge[10010][10010];
vector<Family*> trees;
bool visited[10010];
bool isNode[10010];

void dfs(int root, int f_index) {
    visited[root] = true;
    trees[f_index]->_member.push_back(root);
    for (int i = 0; i < 10010; i++) {
        if (edge[root][i] != 0 && visited[i] == false) {
            dfs(i, f_index);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, fa, mo, k, m_est, area, child;
        scanf("%d %d %d %d", &id, &fa, &mo, &k);
        forest[i] = new Person;
        forest[i]->_id = id; forest[i]->_isNode = true;
        edge[id][fa] = edge[fa][id] = 1;
        edge[id][mo] = edge[mo][id] = 1;
        isNode[id] = true;
        visited[id] = visited[fa] = visited[mo] = false;
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            edge[id][child] = edge[child][id] = 1;
            visited[child] = false;
        }
        scanf("%d %d", &m_est, &area);
        forest[i]->_m_est = m_est; forest[i]->_area = area;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[forest[i]->_id] == false) {
            Family* f = new Family;
            trees.push_back(f);
            cnt++;
            dfs(forest[i]->_id, cnt-1);
            for (size_t j = 0; j < trees[cnt-1]->_member.size(); j++) {
                if (isNode[trees[cnt-1]->_member[j]]) {
                    trees[cnt-1]->_avg_area += forest[trees[cnt-1]->_member[j]]->_area;
                    trees[cnt-1]->_avg_sets += forest[trees[cnt-1]->_member[j]]->_m_est;
                    trees[cnt-1]->_num++;
                }
                if (trees[cnt-1]->_member[j] < trees[cnt-1]->_id) trees[cnt-1]->_id = trees[cnt-1]->_member[j];
            }
            trees[cnt-1]->_avg_area /= (double)trees[cnt-1]->_num;
            trees[cnt-1]->_avg_sets /= (double)trees[cnt-1]->_num;
        }
    }
    sort(trees.begin(), trees.end(), [](Family* f1, Family* f2) {
        if (f1->_avg_area > f2->_avg_area) return true;
        if (f1->_avg_sets == f2->_avg_area && f1->_id < f2->_id) return true;
        return false;
    });
    printf("%d\n", trees.size());
    for (size_t i = 0; i < trees.size(); i++) {
        printf("%d %d %.3lf %.3lf", trees[i]->_id, trees[i]->_num, trees[i]->_avg_sets, trees[i]->_avg_area);
    }
    return 0;
}