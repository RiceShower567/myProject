#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHITOU 1
#define JIANDAO 2
#define BU 3

int enemyPlay();
int enemyPlay2(int myChoice);
int myPlay();
void judge(int myChoice, int enemyChoice, int* myWin, int* enemyWin);

int main() {

    int myWin = 0;  //记录玩家赢下的局数 
    int enemyWin = 0;   //记录敌人赢下的局数 
    int game = 0;   //记录局数

    srand(time(NULL));

<<<<<<< HEAD
    while(myWin != 2 && enemyWin != 2 && game != 3) {
=======
    //选择游戏模式
    char mode[10];
    do {
        printf("\n你要进入的游戏模式是：\n1.正常模式（aaa）\n2.作弊模式（zzz）\n请输入：\n");
        scanf("%s", &mode);
        if(strcmp(mode,"aaa") != 0 && strcmp(mode,"zzz") != 0) {
            printf("\n无效输入，请重新选择！\n");
            while(getchar() != '\n');
        }
    } while(strcmp(mode,"aaa") != 0 && strcmp(mode,"zzz") != 0);

    if(strcmp(mode,"aaa") == 0) {
        printf("\n进入正常模式\n");
    } else if(strcmp(mode,"zzz") == 0) {
        printf("\n进入作弊模式\n");
    }

    //开始游戏
    while(myWin != 3 && enemyWin != 3 && game != 5) {
>>>>>>> B
        game++;
        printf("\n第%d局开始\n请选择：\n1.石头\n2.剪刀\n3.布\n请输入：",game);
        int myChoice = myPlay();
        int enemyChoice;

        //判断游戏模式
        if(strcmp(mode,"aaa") == 0) {
            enemyChoice = enemyPlay();
        } else if(strcmp(mode,"zzz") == 0) {
            enemyChoice = enemyPlay2(myChoice);
        }

        judge(myChoice, enemyChoice, &myWin, &enemyWin);
    }

    
    if(myWin > enemyWin) {
        printf("\n比分为 %d : %d ,你赢了!\n",myWin,enemyWin);
    } else if(myWin < enemyWin) {
        printf("\n比分为 %d : %d ,你输了\n!",myWin,enemyWin);
    } else if(myWin == enemyWin) {
        printf("\n比分为 %d : %d ,平局。\n",myWin,enemyWin);
    }
    printf("\n游戏结束");

    return 0;
}

//正常模式下对手出拳
int enemyPlay() {
    return rand() % 3 + 1;

}

//作弊模式下对手出拳
int enemyPlay2(int myChoice) {
    switch(myChoice) {
        case SHITOU:
            return JIANDAO;
        case JIANDAO:
            return BU;
        case BU:
            return SHITOU;
    }

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
void judge(int myChoice, int enemyChoice, int* myWin, int* enemyWin) {

    switch(myChoice) {

        //玩家出石头
        case SHITOU:
            switch(enemyChoice) {
                case SHITOU:
                    printf("对面出石头，平局。\n");
                    return;
                case JIANDAO:
                    printf("对面出剪刀，胜利！\n");
                    (*myWin)++;
                    return;
                case BU:
                    printf("对面出布，你输了！\n");
                    (*enemyWin)++;
                    return;
            }

        //玩家出剪刀
        case JIANDAO:
            switch(enemyChoice) {
                case SHITOU:
                    printf("对面出石头，你输了！\n");
                    (*enemyWin)++;
                    return;
                case JIANDAO:
                    printf("对面出剪刀，平局。\n");
                    return;
                case BU:
                    printf("对面出布，胜利！\n");
                    (*myWin)++;
                    return;
            }

        //玩家出布
        case BU:
            switch(enemyChoice) {
                case SHITOU:
                    printf("对面出石头，胜利！\n");
                    (*myWin)++;
                    return;
                case JIANDAO:
                    printf("对面出剪刀，你输了！\n");
                    (*enemyWin)++;
                    return;
                case BU:
                    printf("对面出布，平局。\n");
                    return;
            }
    }

}

