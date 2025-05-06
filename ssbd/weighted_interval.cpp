#include <iostream>
#include <vector>
using namespace std;

int latestNonConflict(const vector<int>& end, const vector<int>& start, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (end[j] <= start[i]) return j;
    }
    return -1;
}

int findMaxWeight(int i, const vector<int>& start, const vector<int>& end, 
                 const vector<int>& weight, vector<int>& dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    int incl = weight[i] + findMaxWeight(latestNonConflict(end, start, i), start, end, weight, dp);
    int excl = findMaxWeight(i - 1, start, end, weight, dp);

    dp[i] = max(incl, excl);
    return dp[i];
}

void merge(vector<int>& end, vector<int>& start, vector<int>& weight, 
          vector<int>& index, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> Lend(n1), Rend(n2);
    vector<int> Lstart(n1), Rstart(n2);
    vector<int> Lweight(n1), Rweight(n2);
    vector<int> Lindex(n1), Rindex(n2);

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
}

void mergeSort(vector<int>& end, vector<int>& start, vector<int>& weight, 
               vector<int>& index, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(end, start, weight, index, l, m);
        mergeSort(end, start, weight, index, m + 1, r);
        merge(end, start, weight, index, l, m, r);
    }
}

int main() {
    vector<int> start = {1, 2, 4, 6};
    vector<int> end = {3, 5, 6, 7};
    vector<int> weight = {50, 20, 70, 60};
    int n = start.size();

    vector<int> index(n);
    for (int i = 0; i < n; i++) index[i] = i;

    mergeSort(end, start, weight, index, 0, n - 1);

    vector<int> dp(n, -1);

    int maxWeight = findMaxWeight(n - 1, start, end, weight, dp);
    cout << "Maximum weight of non-overlapping jobs: " << maxWeight << endl;

    return 0;
}
