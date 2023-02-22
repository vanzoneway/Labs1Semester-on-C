#include <stdio.h>
#include "goodinputs.h"
#include "tasks.h"

void print_menu(){
    printf("1. Start a first task\n");
    printf("2. Start a second task\n");
    printf("3.Exit\n");
}

void menu(){
    print_menu();
    printf("Choose a variant:\n>");
    int var = goodScanfInt();
    while(var>3 || var<1){
        printf("You wrote an incorrect variant! Tre again:\n>");
        var = goodScanfInt();
    }
    while(var != 3){
        switch(var)
        {
            case 1:
                first_task();
            print_menu();
            var = goodScanfInt();
            while (var > 3 || var < 1) {
                printf("You wrote an incorrect variant! Tre again:\n>");
                var = goodScanfInt();
            }
            break;
            case 2:
                second_task();
            print_menu();
            var = goodScanfInt();
            while (var > 3 || var < 1) {
                printf("You wrote an incorrect variant! Tre again:\n>");
                var = goodScanfInt();
            }
            break;
            default:
                printf("Bye-bye!\n");
            break;
        }

    }
}