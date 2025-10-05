#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num; // 填空：将ptr指向num

    printf("num的值: %d\n", *ptr); // 填空：通过指针访问num的值
    printf("num的地址: %p\n", ptr); // 填空：通过指针获取num的地址

    *ptr = 20; // 通过指针修改num的值
    printf("修改后num的值: %d\n", num);

    return 0;
}

