#include <stdio.h>

int count(int n);

int main() {
    int n;
    scanf("%d", &n);
    // int times = 0;
    // long long temp1 = 1;
    // long long temp2 = 1;
    // long long temp3 = 1;

    // printf("%lld\n", 1);
    // while(times <= n) {
    //     printf("%d\n", temp3);
    //     temp1 = temp2;
    //     temp2 = temp3;
    //     temp3 = temp1 + temp2;
    //     times++;
    // }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", count(i));
    }
    return 0;
}

int count(int n) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }

    return count(n - 1) + count(n - 2);
}