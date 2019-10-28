#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char Dice[10][10][10] = {
    {" ----- ",
   "|     |",
   "|  o  |",
   "|     |",
    " ----- "},
    {" ----- ",
   "|o    |",
   "|     |",
   "|    o|",
    " ----- "},
    {" ----- ",
   "|o    |",
   "|  o  |",
   "|    o|",
    " ----- "},
    {" ----- ",
   "|o   o|",
   "|     |",
   "|o   o|",
    " ----- "},
    {" ----- ",
   "|o   o|",
   "|  o  |",
   "|o   o|",
    " ----- "},
    {" ----- ",
   "|o   o|",
   "|o   o|",
   "|o   o|",
    " ----- "},
};

int rand_number[21];
int dice_number[7];

int show_dice(int number, int count) {
    printf("[*] you rolled point %d\n", number);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++)
            printf("%c", Dice[number-1][i][j]);
        printf("\n");
    }
    if (dice_number[count] == number)
        return 1;
    return 0;
}

void show_tips() {
    srand((INT_MAX + INT_MIN) / 2);
    printf("--------------------------------\n");
    printf("[*] input 's' start rolling\n");
    printf("--------------------------------\n");
}

int check(int first, int second) {
    if (first != second) {
        printf("[*] wrong flag\n");
        system("pause");
        exit(1);
    }
}

int main() {
    show_tips();
    for (int i = 0; i < 20; i++) 
        rand_number[i] = rand();
    srand(time(NULL));
    int count = 0;
    dice_number[count] = rand_number[count] % 5 + 1;
    printf("[*] you need to roll point %d\n", dice_number[count]);
    printf("--------------------------------\n");
    while(1) {
        char ch = getchar();
        if (ch == 's' || ch == 'S') {
            if(!show_dice(rand() % 5 + 1, count)) {
                printf("[*] wrong point game over\n");
                system("pause");
                return 0;
            }
            printf("[*] correct point\n");
            printf("--------------------------------\n");
            count++;
            if (count == 6) {
                dice_number[count] = rand_number[count] % 5 + 1;
                break;
            }
            dice_number[count] = rand_number[count] % 5 + 1;
            printf("[*] you need to roll point %d\n", dice_number[count]);
        }
    }
    if (count == 6) {
        if(IsDebuggerPresent())
            rand_number[1] %= 127;
        count = 0;
        printf("[*] input your flag:"); 
        char flag[20];
        scanf("%s", &flag);
        for (int i = 0; i < 18; i++) {
            if (i % 3 == 0) {
                if(flag[i] != ((rand_number[i] % 56 + 60) + dice_number[count++])) {
                    printf("[*] wrong flag\n");
                    system("pause");
                    return 0;
                }
            }
            else {
                if(flag[i] != (rand_number[i] % 56 + 66)) {
                    printf("[*] wrong flag\n");
                    system("pause");
                    return 0;
                }
            }
        }
        printf("[*] correct flag\n");
    }
    system("pause");
}