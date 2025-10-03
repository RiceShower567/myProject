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

    int flag = 0;
    int game = 0;

    while(flag == 0) {
        game++;
        printf("\n第%d局开始\n请选择：\n1.石头\n2.剪刀\n3.布\n请输入：",game);
        int myChoice = myPlay();
        int enemyChoice = enemyPlay();
        flag = judge(myChoice, enemyChoice);
    }
    printf("\n游戏结束");

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
        if(choice >= 1 && choice <= 3) {
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
                    printf("对面出石头，平局。\n");
                    return 0;
                case JIANDAO:
                    printf("对面出剪刀，胜利！\n");
                    return 1;
                case BU:
                    printf("对面出布，你输了！\n");
                    return 0;
            }

        //玩家出剪刀
        case JIANDAO:
            switch(enemyChoice) {
                case SHITOU:
                    printf("对面出石头，你输了！\n");
                    return 0;
                case JIANDAO:
                    printf("对面出剪刀，平局。\n");
                    return 0;
                case BU:
                    printf("对面出布，胜利！\n");
                    return 1;
            }

        //玩家出布
        case BU:
            switch(enemyChoice) {
                case SHITOU:
                    printf("对面出石头，胜利！\n");
                    return 1;
                case JIANDAO:
                    printf("对面出剪刀，你输了！\n");
                    return 0;
                case BU:
                    printf("对面出布，平局。\n");
                    return 0;
            }
        
    }

}

