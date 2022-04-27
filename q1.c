/*
Listando os contatos por nome.
*/
#include <stdio.h>
#include <stdlib.h>
//criando a função.
void listaDecontatos();

int main(){
//Chamada da função.  
listaDecontatos();

    return 0;
}
void listaDecontatos(){
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Declarando um ponteiro para o arquivo. Logo em seguida, abrindo o arquivo para leitura.
    FILE *arq = fopen("agenda.dat","r");
    //verificação se o arquivo foi aberto.
    if(!arq){
        printf("Impossível abrir o arquivo!\n");
    }
    //Criando uma condição para ler até o final do arquivo.
    while(!feof(arq)){
    fscanf(arq,"%i %s %s %s",&id, nome, profissao, telefone);
    printf("%s\n",nome);
    }
//Fechando o arquivo.
    fclose(arq);
}