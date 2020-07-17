#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> origin, partial;

void partialInsertSort(vector<int>& array, int j) {
    int key = array[j];
    int i = j-1;
    while (i >= 0 && array[i] > key) {
        array[i+1] = array[i];
        i--;
    }
    array[i+1] = key;
}

void partialMergeSort(vector<int>& array, int partlen) {
    if (partlen >= n) return;
    vector<int> cpy = array;
    int p1, p2, index;
    for (int i = 0; i < n; i += partlen) {
        p1 = i;
        p2 = i + partlen / 2;
        index = i;
        while (p1 < i + partlen / 2 && p1 < n && p2 < i + partlen && p2 < n) {
            if (cpy[p1] < cpy[p2]) {
                array[index++] = cpy[p1++];
            } else {
                array[index++] = cpy[p2++];
            }
        }
        while (p1 < i + partlen / 2 && p1 < n) {
            array[index++] = cpy[p1++];
        }
        while (p2 < i + partlen && p2 < n) {
            array[index++] = cpy[p2++];
        }
    }
}

int main() {
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        origin.push_back(temp);   
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        partial.push_back(temp);   
    }

    vector<int> tempArray = origin;

    for (int j = 1; j < n; j++) {
        partialInsertSort(tempArray, j);
        if (tempArray == partial) {
            cout << "Insertion Sort" << endl;
            partialInsertSort(tempArray, j+1);
            printf("%d", tempArray[0]);
            for (size_t i = 1; i < n; i++) {
                printf(" %d", tempArray[i]);
            }
            return 0;
        }
    }

    tempArray = origin;
    for (int len = 2; len <= n; len *= 2) {
        partialMergeSort(tempArray, len);
        if (tempArray == partial) {
            cout << "Merge Sort" << endl;
            partialMergeSort(tempArray, 2*len);
            printf("%d", tempArray[0]);
            for (size_t i = 1; i < n; i++) {
                printf(" %d", tempArray[i]);
            }
            return 0;
        }
    }

    return 0;
}