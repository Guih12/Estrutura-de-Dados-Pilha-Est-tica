/*Codifique, compile e execute um programa que seja capaz de ler do usuário diversos
números e, para cada um destes, realizar as seguintes operações:
a. se positivo, inserir na pilha P;
b. se negativo, inserir na pilha N;
c. se zero, retirar um elemento de cada pilha.
Obs: Devem ser declaradas duas pilhas N e P que sejam capazes de armazenar
valores positivos e negativos, respectivamente.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Stacks{
    int values[MAX];
    int top;
}array_stacks;

void start_stack(array_stacks *N, array_stacks *P){//inicia o topo das lista em -1;
    N->top = -1;
    P->top = -1;
}

int empty_stackN(array_stacks *N){ //verifica se a pilha N esta vazia
    if(N->top-1){
        printf("Erro a pilha esta vazia");
        return 1;
    }
    return 0;
}
int empty_stackP(array_stacks *P){ //verifica se a pilha P esta vazia
    if(P->top-1){
        printf("Erro a pilha esta vazia");
        return 1;
    }
    return 0;
}
int full_stackN(array_stacks *N){ //verifica se a pilha N esta cheia
    if(N->top == MAX -1){
        printf("Erro a pilha esta cheia");
        return 1;
    }
    return 0;
}
int full_stackP(array_stacks *P){ //verifica se a pilha P esta cheia
    if(P->top == MAX -1){
        printf("Erro a pilha esta cheia");
        return 1;
    }
    return 0;
}

void push_stackN(array_stacks *N, int value){//Função que impilha valores na pillha N
    if(full_stackN(N)){
        return;
    }
    else{
        ++N->top;
        N->values[N->top]=value;
    }
}
void push_stackP(array_stacks *P, int value){//função que impilha valores na pilha P
    if(full_stackN(P)){
        return;
    }
    else{
        ++P->top;
        P->values[P->top]=value;
    }
}

int pop_stackN(array_stacks *N){//função que desimpilha um valor da pilha N
    int aux;
    if(empty_stackN(N)){
        return -1;
    }
    else{
        aux = N->values[N->top];
        N->top--;
        return aux;
    }
}
int pop_stackP(array_stacks *P){//função que desimpilha um valor da pilha N
    int aux;
    if(empty_stackP(P)){
        return -1;
    }
    else{
        aux = P->values[P->top];
        P->top--;
    }
}

void insert_elements(array_stacks *N, array_stacks *P, int value){
    if(value > 0){
        push_stackP(P, value);
    }
    else if(value < 0){
        push_stackN(N, value);
    }
    else if(value == 0){
        pop_stackP(P);
        pop_stackN(N);
    }
}
int stacktop_N(array_stacks *N){
    
        return N->values[N->top];
    
}
int stacktop_P(array_stacks *P){
    

        return P->values[P->top];
    
}
int main(){
    int options, value;
    array_stacks *N;
    array_stacks *P;
    N = (array_stacks*)malloc(sizeof(array_stacks));
    P = (array_stacks*)malloc(sizeof(array_stacks));
    start_stack(N, P);

    do{
        printf("1 - inserir elementos na pilha\n");
        printf("0 - sair do programa\n");
        printf("Escolha: ");
        scanf("%d", &options);
        switch(options){
            case 1:
                    printf("Insira o valor esperado..: ");
                    scanf("%d", &value);
                    insert_elements(N, P, value);
                break;
        }
    }while(options!=0);
    printf("Ultimo elemento da pilha N: %d\n", stacktop_N(N));
    printf("Ultimo elemento da pilha P: %d\n", stacktop_P(P));
}