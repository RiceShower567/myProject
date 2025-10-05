#include <stdio.h>
   
int main() {
   int arr[3] = {10, 20, 30};
   int *ptr = arr;
   
   printf("%d\n", *ptr);      // 输出: 10
   printf("%d\n", *(ptr+1));  // 输出: 20
   printf("%d\n", *ptr+1);    // 输出: 11
   
   ptr++;
   printf("%d\n", *ptr);      // 输出: 20
   
   return 0;
}
