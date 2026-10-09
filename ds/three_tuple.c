#include <stdio.h>

int readSparse(int A[10][10], int m, int n, int T[20][3]) {
    int k = 1, count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                T[k][0] = i; T[k][1] = j; T[k][2] = A[i][j];
                k++; count++;
            }
        }
    }
    T[0][0] = m; T[0][1] = n; T[0][2] = count;
    return k;
}

void printTuple(int T[20][3], int len) {
    printf("Row\tCol\tVal\n");
    for (int i = 0; i < len; i++)
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);
}

void transpose(int T[20][3], int Tr[20][3]) {
    Tr[0][0] = T[0][1]; Tr[0][1] = T[0][0]; Tr[0][2] = T[0][2];
    int k = 1;
    for (int j = 0; j < T[0][1]; j++)
        for (int i = 1; i <= T[0][2]; i++)
            if (T[i][1] == j) {
                Tr[k][0] = T[i][1]; Tr[k][1] = T[i][0]; Tr[k][2] = T[i][2];
                k++;
            }
}

void addSparse(int A[20][3], int B[20][3], int C[20][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) return;
    C[0][0] = A[0][0]; C[0][1] = A[0][1];
    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i <= A[0][2]) { C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++; }
    while (j <= B[0][2]) { C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++; }
    C[0][2] = k - 1;
}

int main() {
    int m, n, mat1[10][10], mat2[10][10], T1[20][3], T2[20][3], Tr[20][3], C[20][3];
    printf("Enter rows & cols: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter Matrix 1:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &mat1[i][j]);

    int k1 = readSparse(mat1, m, n, T1);
    printf("\nThree-Tuple:\n"); printTuple(T1, k1);

    transpose(T1, Tr);
    printf("\nTranspose:\n"); printTuple(Tr, T1[0][2] + 1);

    printf("\nEnter Matrix 2:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &mat2[i][j]);

    readSparse(mat2, m, n, T2);
    addSparse(T1, T2, C);
    printf("\nSum:\n"); printTuple(C, C[0][2] + 1);
    return 0;
}
