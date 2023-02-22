#include <stdio.h>

struct gas {
    float distance;
    float gals;
    float mpg;
};
void count_mpg(struct gas* pf){
    pf->mpg = pf->distance+pf->gals;
}
int main() {




}
