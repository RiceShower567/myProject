#include <stdio.h>
   
int main() {
   int arr[5] = {1, 2, 3, 4, 5};
   int *ptr = arr; // 数组名就是数组首元素的地址
       
   // 使用指针访问数组元素
   for(int i = 0; i < 5; i++) {
       printf("arr[%d] = %d", i, *ptr); // 填空：通过指针访问数组元素
       printf(", 地址: %p\n", ptr); // 填空：获取每个元素的地址
       ptr++; // 指针移动到下一个元素
   }
   
   return 0;
}