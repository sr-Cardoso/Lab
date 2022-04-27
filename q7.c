/*
Apagando todos os contatos.
*/
#include <stdio.h>
#include <stdlib.h>
//Crando a função
void ApagarOsContatos();

int main(){
//Chamada da função.
ApagarOsContatos();

    return 0;
}
void ApagarOsContatos(){
//Abrindo um arquivo para escrita.
    FILE *file1 = fopen("agendaAux.dat","w");

    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo um arquivo para leitura.
    FILE *file2 = fopen("agenda.dat","r");
//Verificação.
    if(!file2){
        printf("Impossivel abrir o arquivo!\n");
    }
//Fechando os arquivos.
    fclose(file1);
    fclose(file2);
//Excluindo o arquivo dos contatos.
remove("agenda.dat");
//Renomeando o arquivo limpo com o nome do arquivo que tinha os contatos. Dessa forma é feita a remoção de todos os contatos.
rename("agendaAux.dat","agenda.dat");

}