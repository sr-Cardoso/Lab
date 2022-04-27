/*
Acessando um contato através do indice.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função que vai receber o ID.
void contatoId(int indice);

int main(){
//Pedindo ao usuário o ID.
int indice;
printf("Digite o id do contato: ");
scanf("%i",&indice);
//Chamando a função com o id digitado pelo usuário.
contatoId(indice);

    return 0;
}
void contatoId(int indice){
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo o arquivo para leitura.
FILE *file = fopen("agenda.dat","r");
//Verificação do arquivo.
if(!file){
    printf("Impossivel abrir o arquivo\n");
}
//Condição para ler o arquivo completo.
while(!feof(file)){
     fscanf(file,"%i %s %s %s", &id, nome, profissao, telefone);
//Quando o id que o usuário digitou for igual ao do arquivo, irá imprir o contato.
        if(id == indice){
            printf("%i - %s - Profissão: %s contato: %s\n)",id, nome, profissao, telefone);
        }
}
}