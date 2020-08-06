#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Request{
    
    char clientName[50];
    char phone[12];
    struct Adress{
        char street[50];
        int number;
        char district[40];
        char complement[50];
    }adress;
    struct Itens{
        char flavor[30];
        char size[20];
        int amount;
    }itens;
    struct Payment{
        int payment;
        float valor;
    }payment;
}Request;

char clearString(char v[]);

int main(){

    int i, nItens;

    struct Request pedido;
    
    
    printf("Nome do cliente: ");
    fgets(pedido.clientName, 50, stdin);
    __fpurge(stdin);
    clearString(pedido.clientName);
    

    printf("Telefone: ");
    scanf("%s", pedido.phone);
    __fpurge(stdin);
    clearString(pedido.phone);

    printf("Rua: ");
    fgets(pedido.adress.street, 50 , stdin);
    __fpurge(stdin);
    clearString(pedido.adress.street);

    printf("Número da casa: ");
    scanf(" %i", &pedido.adress.number);
    __fpurge(stdin);


    printf("Bairro: ");
    fgets(pedido.adress.district, 40, stdin);
    __fpurge(stdin);
    clearString(pedido.adress.district);

    printf("Complemento: ");
    fgets(pedido.adress.complement, 50, stdin);
    __fpurge(stdin);
    clearString(pedido.adress.complement);
    

    printf("Quantos itens deseja? ");
    scanf(" %i", &nItens);
    __fpurge(stdin);


    for(i = 0; i < nItens; i++){
        printf("Sabor: ");
        fgets(pedido.itens.flavor, 30, stdin);
        __fpurge(stdin);
        clearString(pedido.itens.flavor);
        

        printf("Tamanho: ");
        fgets(pedido.itens.size, 20, stdin);
        __fpurge(stdin);
        clearString(pedido.itens.size);
        

        printf("Quantidade: ");
        scanf(" %i", &pedido.itens.amount);
        __fpurge(stdin);
    }


    printf("Forma de pagamento:");
    scanf(" %i", &pedido.payment.payment);
    __fpurge(stdin);

    printf("Valor: ");
    scanf(" %f", &pedido.payment.valor);
    __fpurge(stdin);

    //Show

    printf("\n\nPedido");
    printf("\n\n-------------------------------------------");
    printf("\n\nNome do cliente: %s", pedido.clientName);
    printf("\nTelefone: %s", pedido.phone);
    printf("\nRua: %s", pedido.adress.street);
    printf("\nNúmero: %i", pedido.adress.number);
    printf("\nBairro: %s", pedido.adress.district);
    printf("\nComplemento: %s", pedido.adress.complement);

    printf("\n\nItens");

    for(i = 0; i < nItens; i++){
        
        printf("\n-------------------------------------------\n");
        printf("\nSabor: %s", pedido.itens.flavor);
        printf("\nTamanho: %s", pedido.itens.size);
        printf("\nQuantidade: %i", pedido.itens.amount);
    }

    printf("\n\n-------------------------------------------\n");
    printf("\nForma de pagamento: %i", pedido.payment.payment);
    printf("\nValor: %.2f\n\n", pedido.payment.valor);
}

char clearString(char v[]){

    v[strcspn(v, "\n")] = 0;
    
}

