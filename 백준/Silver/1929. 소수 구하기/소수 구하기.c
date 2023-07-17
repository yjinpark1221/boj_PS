#include <stdio.h>
int arr[1000001];
int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    arr[1] = 1;
    for (int i = 2; i * i <= N; ++i) {
        for (int j = 2; j * i <= N; ++j) {
            arr[i * j] = 1;
        }
    }
    for (int i = M; i <= N; ++i) {
        if (!arr[i]) printf("%d\n", i);
    }
    printf("\n");
    return 0;
}