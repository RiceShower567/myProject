#include <stdio.h>

void change(int* a, int* b);

int main() {
    int a, b;

    printf("请输入：");
    scanf("%d %d", &a, &b);

    printf("a = %d, b = %d\n", a, b);

    change(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void change(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}