#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
using namespace std;

class QuickSort {
private:
    vector<int> data;
    int comparisons;
    int swaps;

    int partition(int low, int high);
    void quickSortHelper(int low, int high);

public:
    QuickSort();
    void loadData(const vector<int>& arr);
    void sort();
    void printData() const;
    void printSteps();
    vector<int> getData() const;
    int getComparisons() const;
    int getSwaps() const;
};

#endif#pragma once
