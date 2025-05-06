#include<iostream>
using namespace std;

const int MAX = 4;

void add(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    add(A11, A22, T1, newSize);
    add(B11, B22, T2, newSize);
    strassen(T1, T2, M1, newSize);

    add(A21, A22, T1, newSize);
    strassen(T1, B11, M2, newSize);

    subtract(B12, B22, T1, newSize);
    strassen(A11, T1, M3, newSize);

    subtract(B21, B11, T1, newSize);
    strassen(A22, T1, M4, newSize);

    add(A11, A12, T1, newSize);
    strassen(T1, B22, M5, newSize);

    subtract(A21, A11, T1, newSize);
    add(B11, B12, T2, newSize);
    strassen(T1, T2, M6, newSize);

    subtract(A12, A22, T1, newSize);
    add(B21, B22, T2, newSize);
    strassen(T1, T2, M7, newSize);

    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];

    add(M1, M4, T1, newSize);
    subtract(T1, M5, T2, newSize);
    add(T2, M7, C11, newSize);

    add(M3, M5, C12, newSize);
    add(M2, M4, C21, newSize);

    add(M1, M3, T1, newSize);
    subtract(T1, M2, T2, newSize);
    add(T2, M6, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX] = {
        {7, 8, 0, 0},
        {2, 9, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int B[MAX][MAX] = {
        {14, 5, 0, 0},
        {5, 18, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int C[MAX][MAX] = {0};

    strassen(A, B, C, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
