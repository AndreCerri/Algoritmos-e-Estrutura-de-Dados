#include<stdio.h>
#include<stdlib.h>


struct Airplane{
    char model[30];
    char producer[40];
    int passengers;
    float length;
    float height;
    int altitude;
    char motor[30];
};

int main(){

    struct Airplane aviao;

    printf("Insira o modelo do avião: ");
    scanf(" %s", aviao.model);
    

    printf("Insira o fabricante do avião: ");
    scanf(" %s", aviao.producer);
    

    printf("Insira o número de passageiros: ");
    scanf(" %i", &aviao.passengers);
    

    printf("Insira o comprimento do avião: ");
    scanf(" %f", &aviao.length);
    

    printf("Insira a altura do avião: ");
    scanf(" %f", &aviao.height);
    

    printf("Insira a altitude: ");
    scanf(" %i", &aviao.altitude);
    

    printf("Insira o motor: ");
    scanf(" %s", aviao.motor);
    


    printf("\n\nAvião\n\n---------------------------------------------------------------------\n\n");
    printf("Modelo: %s\n", aviao.model);
    printf("Fabricante: %s\n", aviao.producer);
    printf("Passageiros: %i\n", aviao.passengers);
    printf("Comprimento: %.2f\n", aviao.length);
    printf("Altura: %.2f\n", aviao.height);
    printf("Altitude: %i\n", aviao.altitude);
    printf("Motor: %s\n", aviao.motor);

}