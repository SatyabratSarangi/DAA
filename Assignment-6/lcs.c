#include <stdio.h>
#include <string.h>

void LCSLength(char X[], char Y[], int c[100][100], char b[100][100]) {
    int m = strlen(X);
    int n = strlen(Y);
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D';  // diagonal ↖
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U';  // up ↑
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L';  // left ←
            }
        }
    }
}


void PrintLCS(char b[100][100], char X[], int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'D') {
        PrintLCS(b, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (b[i][j] == 'U')
        PrintLCS(b, X, i - 1, j);
    else
        PrintLCS(b, X, i, j - 1);
}

int main() {
    char X[100], Y[100];
    int c[100][100];   
    char b[100][100];  

    printf("Enter first string: ");
    scanf("%s", X);   
    printf("Enter second string: ");
    scanf("%s", Y);

    LCSLength(X, Y, c, b);

    int m = strlen(X);
    int n = strlen(Y);

    printf("\nLength of LCS = %d\n", c[m][n]);
    printf("LCS = ");
    PrintLCS(b, X, m, n);
    printf("\n");

    return 0;
}
