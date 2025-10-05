#include <stdio.h>

int count(int num);

int main() {
    int num;
    printf("请输入：");
    scanf("%d", &num);
    printf("%d", count(num));

    return 0;
}

int count(int num) {
    if(num == 1) {
        return 1;
    } else {
        return num * count(num - 1);
    }
}