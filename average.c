#include <stdio.h>

int judge(int gradeCount[20], int grade, int num, int* key);
int find(int num, int gradeCount[20]);
void print(int gradeCount[20], int count[20]);

int main() {

    printf("\n请输入学生人数：");
    int num;
    do {
        scanf("%d", &num);
        if(num < 0 || num > 20) {
            printf("\n\n无效，请重新输入：");
            while(getchar() != '\n');
        }
    } while(num < 0 || num > 20);


    int gradeSum = 0;   //记录总成绩之和
    int allGrade[20]; //记录所有分数
    int gradeCount[20]; //记录出现过的分数
    int count[20] = {0}; //记录每个分数的出现次数

    for(int i = 0; i < 19; i++) {
        gradeCount[i] = -1;
    }
    for(int i = 0; i < 19; i++) {
        allGrade[i] = -1;
    }

    for(int i = 1; i <= num; i++) {
        int grade;
        printf("\n\n请输入第%d个学生的成绩:", i);
        do {
            scanf("%d", &grade);
            if(grade < 0 || grade >= 100) {
                printf("\n\n无效，请重新输入第%d名学生的成绩：", i);
                while(getchar() != '\n');
            }
        } while(grade < 0 || grade > 100);
        allGrade[i - 1] = grade;
        gradeSum += grade;
    }

    int flag = 0;   //记录一个分数在gradeCount中是否存在
    int key = 0;    //记录当前所在位置
    for(int i = 0; i < num; i++) {
        if(allGrade[i] == -1) {
            continue;;
        }
        flag = judge(gradeCount, allGrade[i], num, &key);
        if(flag == 1) {
            count[key]++;
        } else {
            int temp = find(num, gradeCount);
            gradeCount[temp] = allGrade[i];
            count[temp] = 1;
        }
    }


    printf("\n%d个学生的平均分是%.2f", num, gradeSum / (float)num);
    print(gradeCount, count);

    return 0;
}

//判断一个分数在gradeCount中是否存在
int judge(int gradeCount[20], int grade, int num, int* key) {
    for(int x = 0; x < num; x++) {
        if(grade == gradeCount[x]) {
            (*key) = x;
            return 1;
        }
    }
    return 0;
}

//找到gradeCount中第一个没有赋值的位置
int find(int num, int gradeCount[20]) {
    for(int i = 0; i < num; i++) {
        if(gradeCount[i] == -1) {
            return i;
        }
    }
    return 0;
}

//输出统计结果
void print(int gradeCount[20], int count[20]) {
    printf("分数分布统计\n分数\t人数\n============");
    for(int i = 0; i < 20; i++) {
        if(count[i] != 0) {
            printf("\n%d\t%d", gradeCount[i], count[i]);
        }
    }
}
