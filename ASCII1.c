#include <stdio.h>

int main() {
    char a = 'a';   //c语言中字符以整数的形式存储，决定'a'所代表的整数的是ASCII码
    printf("%d",a); //printf函数用%d接收变量a时，可以世界接收'a'所代表的ASCII码，也就是97

    return 0;
}
