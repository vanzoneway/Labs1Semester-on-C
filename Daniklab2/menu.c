#include "goodinputs.h"
#include <stdio.h>
#include "tasks.h"
void print_menu() {
    printf("Input 1 if you wanna First Task\n");
    printf("Input 2 if you wanna Second Task\n");
    printf("Input 3 if you wanna Third Task\n");
    printf("Input 4 if you wanna exit\n>");
}


void menu(){
    print_menu();
    int var = goodScanfInt();
    while(var>4 || var<1){
        printf("You wrote an incorrect variant! Try again\n>");
        var = goodScanfInt();
    }
    while(var!=4){
        switch(var){
            case 1:
                task_one();
                print_menu();
                var = goodScanfInt();
                while(var>4 || var<1){
                    printf("You wrote an incorrect variant! Try again\n>");
                    var = goodScanfInt();
                }
                break;
            case 2:
                task_two();
                print_menu();
                var = goodScanfInt();
                while(var>4 || var<1){
                    printf("You wrote an incorrect variant! Try again\n>");
                    var = goodScanfInt();
                }
                break;
            case 3:

                task_three();
                print_menu();
                var = goodScanfInt();
                while(var>4 || var<1){
                    printf("You wrote an incorrect variant! Try again\n>");
                    var = goodScanfInt();
                }
                break;
            default:
                printf("Bye-bye");

        }
    }
}
