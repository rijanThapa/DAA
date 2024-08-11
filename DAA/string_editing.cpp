#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y) {
        return (x < z) ? x : z;
    } else {
        return (y < z) ? y : z;
    }
}

int editDistance(const char *str1, const char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; ++i) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; ++i) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = editDistance(str1, str2);

    printf("Edit Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}

