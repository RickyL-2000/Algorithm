#include <iostream>
#include <vector>
using namespace std;

int n, temp;
vector<int> origin;
vector<int> target;
vector<int> insertion_v, heap_v;

void partialInsertSort(int j) {
    if (j >= insertion_v.size()) return;
    int key = insertion_v[j];
    int i = j-1;
    while (i != -1 && insertion_v[i] >= key) {
        insertion_v[i+1] = insertion_v[i];
        i--;
    }
    insertion_v[i+1] = key;
}

void maxHeapify(int heapsize, int index) {
    int largest = index;
    if (2 * index + 1 < heapsize && heap_v[index] < heap_v[2 * index + 1]) {
        largest = 2 * index + 1;
    }
    if (2 * index + 2 < heapsize && heap_v[largest] < heap_v[2 * index + 2]) {
        largest = 2 * index + 2;
    }
    if (largest != index) {
        swap(heap_v[largest], heap_v[index]);
        maxHeapify(heapsize, largest);
    }
}

void buildMaxHeap(int heapsize) {
    for (int i = heapsize / 2; i >= 0; i--) {
        maxHeapify(heapsize, i);
    }
}

void partialHeapSort(int i) {
    if (i < 1) return;
    buildMaxHeap(i+1);
    swap(heap_v[0], heap_v[i]);
    maxHeapify(i, 0);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        origin.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        target.push_back(temp);
    }

    insertion_v = origin, heap_v = origin;
    for (int j = 1; j < insertion_v.size(); j++) {
        partialInsertSort(j);
        if (insertion_v == target) {
            printf("Insertion Sort\n");
            partialInsertSort(j+1);
            printf("%d", insertion_v[0]);
            for (size_t i = 1; i < insertion_v.size(); i++) {
                printf(" %d", insertion_v[i]);
            }
            return 0;
        }
    }

    for (int i = heap_v.size()-1; i > 0; i--) {
        partialHeapSort(i);
        if (heap_v == target) {
            printf("Heap Sort\n");
            partialHeapSort(i-1);
            printf("%d", heap_v[0]);
            for (size_t i = 1; i < heap_v.size(); i++) {
                printf(" %d", heap_v[i]);
            }
            return 0;
        }
    }
    return 0;
}