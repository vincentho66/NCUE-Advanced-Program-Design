#include <stdio.h>
#include <stdlib.h>

int d[10][10];

void prt(int R, int C) {
    for(int i = 0; i < R; i++) {
        printf("%d", d[i][0]);
        for(int j = 1; j < C; j++)
            printf(" %d", d[i][j]);
        printf("\n");
    }
}

// 逆時針方向旋轉
// 旋轉後的 r'，等於轉換前的 c。
// 旋轉後的 c'，等於 原本矩陣行數(C)-j-1。
void rotate(int R, int C) {
    int b[10][10];
    int i, j;

    for(i = 0; i < R; ++i)
        for(j = 0; j < C; ++j)
            b[C-1-j][i] = d[i][j];

    //printf("\n\n");
    for(i = 0; i < C; i++)
        for(j = 0; j < R; j++)
            d[i][j] = b[i][j];

    //prt(d, C, R);
    //printf("\n\n");
}

// 上下翻轉
// 翻轉後的 r'，等於原本矩陣列數(R)-i-1。
// 翻轉後的 c'，等於c。
void flip(int R, int C) {
    int b[10][10];
    int i, j;

    for(i = 0; i < R; ++i)
        for(j = 0; j < C; ++j)
            b[R-1-i][j] = d[i][j];

    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            d[i][j] = b[i][j];

    //prt(d, R, C);
    //printf("\n\n");
}

int main(void) {
    int R, C, M, op[10];

    while (scanf("%d%d%d",&R, &C, &M) != EOF ) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                scanf("%d", &d[i][j]);
        }

        for(int i = 0; i < M; i++) {
            scanf("%d", &op[i]);
        }

        for(int i = M - 1; i >= 0; i--) {
            if(op[i] == 0) {
                rotate(R, C);
                int t = R;
                R = C;
                C = t;
            }
            else
                flip(R, C);
        }

        printf("%d %d\n", R, C);
        prt(R, C);

    }

    return 0;
}