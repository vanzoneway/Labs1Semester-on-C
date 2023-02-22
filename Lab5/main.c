#include "tasks_for_lab.h"
#include <stdlib.h>
#include "goodinputs.h"
#include <stdio.h>
int main() {
    printMenu();
    int variant;
    do {
        variant = goodScanfInt();
        while (variant > 5 || variant < 1) {
            printf("You wrote an incorrect variant. Try again!\n>");
            variant = goodScanfInt();
        }
        switch (variant) {
            case 1:
                one_one();
                printMenu();
                break;
            case 2:
                two_one();
                printMenu();
                break;
            case 3:
                three_one();
                printMenu();
                break;
            case 4:
                system("cls");
                printMenu();
                break;
            default:
                printf("Lab passed. Thanks to Evgeny Valerievich!");
        }
    } while (variant != 5);
    getchar();
}

