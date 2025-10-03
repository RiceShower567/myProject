#include <stdio.h>;
#include <stdlib.h>;
#include <time.h>;

#define SHITOU 1
#define JIANDAO 2
#define BU 3

int enemyPlay();
int myPlay();
int judge(int myChoice,int enemyChoice);

int main() {

    printf("请选择：\n1.石头\n2.剪刀\n3.布\n请输入：");

    int flag = 0;

    while(flag == 0) {
        int myChoice = myPlay();
        int enemyChoice = enemyPlay();
        flag = judge(myChoice,enemyChoice);
    }

    return 0;
}

//对手出拳
int enemyPlay() {
    srand(time(NULL));
    return rand() % 3 + 1;

}

//玩家出拳
int myPlay() {
    int choice;
    while(1) {
        scanf("%d",&choice);
        if(choice >= 1 || choice <= 3) {
            break;
        } else {
            printf("无效，请重新选择！\n1.石头\n2.剪刀\n3.布\n请输入：");
            while(getchar() != '\n');   //清除错误输入
        }
    }
    return choice;

}    

//判断输赢
int judge(int myChoice,int enemyChoice) {

    switch(myChoice) {

        //玩家出石头
        case SHITOU:
            switch(enemyChoice) {
                case SHITOU:
                    printf("平局");
                    return 0;
                case JIANDAO:
                    printf("胜利！");
                    return 1;
                case BU:
                    printf("你输了！");
                    return 0;
            }

        //玩家出剪刀
        case JIANDAO:
            switch(enemyChoice) {
                case SHITOU:
                    printf("你输了！");
                    return 0;
                case JIANDAO:
                    printf("平局");
                    return 0;
                case BU:
                    printf("胜利！");
                    return 1;
            }

        //玩家出布
        case BU:
            switch(enemyChoice) {
                case SHITOU:
                    printf("胜利！");
                    return 1;
                case JIANDAO:
                    printf("你输了！");
                    return 0;
                case BU:
                    printf("平局");
                    return 0;
            }
        
    }

}

