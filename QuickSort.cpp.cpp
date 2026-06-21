#include "quickSort.h"
#include <iostream>

QuickSort::QuickSort() : comparisons(0), swaps(0) {}

void QuickSort::loadData(const vector<int>& arr) {
    data = arr;
    comparisons = 0;
    swaps = 0;
}

int QuickSort::partition(int low, int high) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (data[j] < pivot) {
            i++;
            swap(data[i], data[j]);
            swaps++;
        }
    }
    swap(data[i + 1], data[high]);
    swaps++;
    return i + 1;
}

void QuickSort::quickSortHelper(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortHelper(low, pi - 1);
        quickSortHelper(pi + 1, high);
    }
}

void QuickSort::sort() {
    comparisons = 0;
    swaps = 0;
    if (data.size() > 0) {
        quickSortHelper(0, data.size() - 1);
    }
}

void QuickSort::printData() const {
    cout << "Tablica: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
}

void QuickSort::printSteps() {
    vector<int> temp = data;
    comparisons = 0;
    swaps = 0;

    cout << "\n╔════════════════════════════════════╗" << endl;
    cout << "║   KROKI SORTOWANIA QUICK SORT      ║" << endl;
    cout << "╚════════════════════════════════════╝" << endl;

    cout << "\nTablica przed sortowaniem: ";
    for (int num : temp) {
        cout << num << " ";
    }
    cout << "\n" << endl;

    if (temp.size() > 0) {
        quickSortHelper(0, temp.size() - 1);
    }

    cout << "\nTablica po sortowaniu: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << "\n" << endl;

    cout << "Liczba porównań: " << comparisons << endl;
    cout << "Liczba zamian: " << swaps << endl;
}

vector<int> QuickSort::getData() const {
    return data;
}

int QuickSort::getComparisons() const {
    return comparisons;
}

int QuickSort::getSwaps() const {
    return swaps;
}