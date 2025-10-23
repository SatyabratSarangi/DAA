#include <stdio.h>
#include <limits.h>

int m[100][100];  
int s[100][100];  


void MatrixChainOrder(int p[], int n) {
    int i, j, k, L, q;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;  

    
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}


void PrintOptimalParens(int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        PrintOptimalParens(i, s[i][j]);
        PrintOptimalParens(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[100];
    int n, i;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions ");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    MatrixChainOrder(p, n);

    printf("Optimal Parenthesization: ");
    PrintOptimalParens(1, n);
    printf("\n");

    return 0;
}
