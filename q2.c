/*
Listando os contatos por nome e telefone.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função.
void Contatos_Telef();

int main(){
//Chamada da função.
Contatos_Telef();

    return 0;
}
void Contatos_Telef(){
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo o arquivo para leitura.
    FILE *file = fopen("agenda.dat", "r");
//Verificando se o arquivo foi aberto.
    if(!file){
        printf("Impossivel abrir o arquivo!\n");
    }
//Cndição para ler o arquivo até o seu fim.
    while(!feof(file)){
        fscanf(file,"%i %s %s %s",&id, nome, profissao, telefone);
        printf("%s - Telefone (%s)\n",nome,telefone);
    }
}