#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr, int N) {
    int i;
    for (i = 0; i < N; i++) {
        cout << arr[i];
        if (i != N-1) cout << ' ';
    }
    cout << endl;
}

int main() {
    int N, M;
    cin >> N >> M;
    M = M % N;
    vector<int> arr(100);
    int num, temp;
    int i, j;
    for (i = 0; i < N; i++) {
        cin >> num;
        arr[i] = num;
    }

    if (M == 0) {
        printArr(arr, N);
        return 0;
    }

    // printArr(arr, N);  //FIXME

    for (i = 0; i < N - M; i++) {
        temp = arr[N-M-1-i];
        for (j = 0; j < M; j++) {
            arr[N-M-1-i+j] = arr[N-M-i+j];
        }
        arr[N-i-1] = temp;
    }

    printArr(arr, N);

    return 0;
}