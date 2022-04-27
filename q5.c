/*
Listando os contatos por Profissão.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função.
void Fprofissao();

int main(){
//Chamada da função.
Fprofissao();
    return 0;
}
void Fprofissao(){
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo o arquivo para leitura.
    FILE *file = fopen("agenda.dat","r");
//Verificação do arquivo.
    if(!file){
        printf("Impossivel abrir o arquivo!\n");
    }
//Condição que percorre o arquivo completo.
    while(!feof(file)){
//Lendo o arquivo e imprimindo as profissões.
        fscanf(file,"%i %s %s %s ", &id, nome, profissao, telefone);
        printf("%s\n",profissao);
    }
}