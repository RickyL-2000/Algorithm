# 05-树8 File Transfer (25point(s))

We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:
Each input file contains one test case. For each test case, the first line contains N (2≤N≤10
​4
​​ ), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

I c1 c2  
where I stands for inputting a connection between c1 and c2; or

C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:
For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:
no
no
yes
There are 2 components.
Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:
no
no
yes
yes
The network is connected.

## my sol 1     20/7/8  25 min

复习了一下并查集，所以花了点时间

0	sample 1 合并2个集合，最后不连通	
Accepted
3 ms	356 KB
1	sample 2 最后连通	
Accepted
2 ms	512 KB
2	最小N，无连通操作	
Accepted
8 ms	360 KB
3	最大N，无操作	
Accepted
4 ms	360 KB
4	最大N，递增链，卡不按大小union的	
Accepted
36 ms	896 KB
5	最大N，递减链，卡不按大小union的	
Accepted
53 ms	896 KB
6	最大N，两两合并，反复查最深结点，卡不压缩路径的	
Accepted
60 ms	1024 KB

``` C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10010];

int find(int x) {
    return parent[x] < 0 ? x : parent[x] = find(parent[x]);
}

bool merge(int x1, int x2) {
    if ((x1 = find(x1)) == (x2 = find(x2))) return false;
    if (parent[x1] < parent[x2]) {
        parent[x1] += parent[x2];
        parent[x2] = x1;
    } else {
        parent[x2] += parent[x1];
        parent[x1] = x2;
    }
    return true;
}

int main() {
    fill(parent, parent + 10010, -1);
    int n;
    scanf("%d", &n);
    char status;
    int x1, x2;
    vector<string> ans;
    while (true) {
        cin >> status;
        if (status == 'S') break;
        cin >> x1 >> x2;
        if (status == 'I') {
            merge(x1, x2);
        } else if (status == 'C') {
            if (find(x1) == find(x2)) ans.push_back("yes");
            else ans.push_back("no");
        }
    }
    for (string str : ans) {
        cout << str << endl;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) cnt++;
    }
    if (cnt == 1) cout << "The network is connected." << endl;
    else if (cnt > 1) cout << "There are " << cnt << " components." << endl;
    return 0;
}
```
