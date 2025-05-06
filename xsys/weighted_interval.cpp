#include<iostream>
using namespace std;

int latestNonConflict(int* end, int* start, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (end[j] <= start[i]) return j;
    }
    return -1;
}

int findMaxWeight(int i, int* start, int* end, int* weight, int* dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    int incl = weight[i] + findMaxWeight(latestNonConflict(end, start, i), start, end, weight, dp);
    int excl = findMaxWeight(i - 1, start, end, weight, dp);

    dp[i] = max(incl, excl);
    return dp[i];
}

void merge(int* end, int* start, int* weight, int* index, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int* Lend = new int[n1], *Rend = new int[n2];
    int* Lstart = new int[n1], *Rstart = new int[n2];
    int* Lweight = new int[n1], *Rweight = new int[n2];
    int* Lindex = new int[n1], *Rindex = new int[n2];

    for (int i = 0; i < n1; i++) {
        Lend[i] = end[l + i];
        Lstart[i] = start[l + i];
        Lweight[i] = weight[l + i];
        Lindex[i] = index[l + i];
    }
    for (int i = 0; i < n2; i++) {
        Rend[i] = end[m + 1 + i];
        Rstart[i] = start[m + 1 + i];
        Rweight[i] = weight[m + 1 + i];
        Rindex[i] = index[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (Lend[i] <= Rend[j]) {
            end[k] = Lend[i];
            start[k] = Lstart[i];
            weight[k] = Lweight[i];
            index[k++] = Lindex[i++];
        } else {
            end[k] = Rend[j];
            start[k] = Rstart[j];
            weight[k] = Rweight[j];
            index[k++] = Rindex[j++];
        }
    }

    while (i < n1) {
        end[k] = Lend[i];
        start[k] = Lstart[i];
        weight[k] = Lweight[i];
        index[k++] = Lindex[i++];
    }
    while (j < n2) {
        end[k] = Rend[j];
        start[k] = Rstart[j];
        weight[k] = Rweight[j];
        index[k++] = Rindex[j++];
    }

    delete[] Lend; delete[] Rend;
    delete[] Lstart; delete[] Rstart;
    delete[] Lweight; delete[] Rweight;
    delete[] Lindex; delete[] Rindex;
}

void mergeSort(int* end, int* start, int* weight, int* index, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(end, start, weight, index, l, m);
        mergeSort(end, start, weight, index, m + 1, r);
        merge(end, start, weight, index, l, m, r);
    }
}

int main() {
    int start[] = {1, 2, 4, 6};
    int end[] = {3, 5, 6, 7};
    int weight[] = {50, 20, 70, 60};
    int n = 4;

    int* index = new int[n];
    for (int i = 0; i < n; i++) index[i] = i;

    mergeSort(end, start, weight, index, 0, n - 1);

    int* dp = new int[n];
    for (int i = 0; i < n; i++) dp[i] = -1;

    int maxWeight = findMaxWeight(n - 1, start, end, weight, dp);
    cout << "Maximum weight of non-overlapping jobs: " << maxWeight << endl;

    delete[] dp;
    delete[] index;

    return 0;
}
