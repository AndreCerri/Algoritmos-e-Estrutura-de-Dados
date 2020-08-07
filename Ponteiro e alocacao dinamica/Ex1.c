#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Fly{
    
    int flightNumber;
    struct Date{
        int day;
        int mounth;
        int year;
    } flightDate;
    struct Horary{
        int hour;
        int minute;
    }horary;
    char startpointAirport[50];
    char endpointAirport[50];
    char route[50];
    int time;
    int passengersNumber;

};

void newFly(struct Fly *p, int pos);
void consultFly(struct Fly *v, int size);
void removeFly(struct Fly *v, int size);
void clearString(char *v);

int main(){

    int status = 1;
    int option;
    int n = 0;
    struct Fly *p;

    p = (struct Fly*)malloc(sizeof(struct Fly));

    while(status == 1){

        printf("\n\n1 - Cadastrar voo");
        printf("\n2 - Consultar voo");
        printf("\n3 - Remover voo");
        printf("\n5 - Sair\n- ");
        scanf(" %i", &option);

        if(option == 1){
            
            newFly(p, n);
            n++;
            p = (struct Fly*)realloc(p, sizeof(struct Fly)*(n + 1));
            
            if(p == NULL){
                printf("Erro ao realocar memória!");
                exit(1);
            }            
        }
        if(option == 2){
            consultFly(p, n);
        }
        if(option == 3){
            removeFly(p, n);
            n--;
        }
        if(option == 5){
            status = 0;
            exit(0);
        }

    }
    
}

void newFly(struct Fly *p, int pos){

    int i;

    printf("\nInsira o número do voo: ");
    scanf(" %i", &p[pos].flightNumber);
    
    printf("Insira o dia: ");
    scanf(" %i", &p[pos].flightDate.day);
    printf("Insira o mês: ");
    scanf(" %i", &p[pos].flightDate.mounth);
    printf("Insira o ano: ");
    scanf(" %i", &p[pos].flightDate.year);

    printf("Insira a hora: ");
    scanf(" %i", &p[pos].horary.hour);
    printf("Insira os minutos: ");
    scanf(" %i", &p[pos].horary.minute);
    __fpurge(stdin);

    printf("Insira o aeroporto de partida: ");
    fgets(p[pos].startpointAirport, 50 ,stdin);
    clearString(p[pos].startpointAirport);

    printf("Insira o aeroporto de chegada: ");
    fgets(p[pos].endpointAirport, 50, stdin);
    clearString(p[pos].endpointAirport);

    printf("Insira a rota: ");
    fgets(p[pos].route, 50, stdin);
    clearString(p[pos].route);

    printf("Insira o tempo de voo: ");
    scanf(" %i", &p[pos].time);

    printf("Insira a quantidade de passageiros: ");
    scanf(" %i", &p[pos].passengersNumber);

    
}

void consultFly(struct Fly *v, int size){

    int numFly, i;

    printf("\nInsira o número do voo: ");
    scanf(" %i", &numFly);

    for(i = 0; i < size; i++){
        if(numFly == v[i].flightNumber){
            printf("\n----------------------------------------");
            printf("\nVoo %i", v[i].flightNumber);
            printf("\n---------------------------------------\n");

            printf("Data: %i/%i/%i\n", v[i].flightDate.day, v[i].flightDate.mounth, v[i].flightDate.year);
            printf("Horário: %ih%i\n", v[i].horary.hour, v[i].horary.minute);
            printf("Aeroporto de partida: %s\n", v[i].startpointAirport);
            printf("Aeroporto de chegada: %s\n", v[i].endpointAirport);
            printf("Rota: %s\n", v[i].route);
            printf("Tempo de voo: %ih\n", v[i].time);
            printf("Número de passageiros: %i\n\n", v[i].passengersNumber);
            printf("\n---------------------------------------\n");
            break;
        }
    }
}

void removeFly(struct Fly *v, int size){

    int numFly, i, k;

    printf("Insira o voo a ser removido: ");
    scanf(" %i", &numFly);

    for(i = 0; i < size; i++){
        if(numFly == v[i].flightNumber){

            if(i < (size-1)){
                for(k = i; k < size; k++){

                    v[k-1] = v[k];
                }                
            }            
            v = (struct Fly*)realloc(v, sizeof(struct Fly)*(size - 1));            
        }
    }

}

void clearString(char *v){

    v[strcspn(v, "\n")] = 0;
}