#include <stdio.h>

int main(){
    float furlong;
    
    printf("Enter your value in furlongs: ");
    scanf("%f", &furlong);

    printf("%.2f furlongs is %.2f yards\n", furlong, furlong*220);
    return 0;
}