#include "goodinputs.h"
#include "tasks.h"
void print_menu(){
    printf("\nPress 1 if you wanna load First Task\n");
    printf("Press 2 if you wanna load Second Task\n");
    printf("Press 3 if you wanna exit\n>");
}
void choose_variant(int* variant){
    *variant = goodScanfInt();
    while(*variant>3 || *variant < 1){
        printf("You entered an incorrect variant!\nTry again\n> ");
        *variant = goodScanfInt();
    }
}
void menu(){
    print_menu();
    int variant;
    choose_variant(&variant);
    do{
        switch (variant) {
            case 1:
                task_one();
                print_menu();
                choose_variant(&variant);
                break;
            case 2:
                task_two();
                print_menu();
                choose_variant(&variant);
                break;
            default:
                printf("Bye-bye");


        }
    }while(variant !=3);

}
