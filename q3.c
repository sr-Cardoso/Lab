/*
Apresentando os contatos por uma letra expecífica.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função que vai receber a letra.
void contato(char letra);

int main(){
//Pedindo ao usuário a letra que ele deseja que os contatos apareçam 
char letra;
printf("Digite a inicial do contato que voce procura: ");
scanf("%c",&letra);
//Chamada da função. 
contato(letra);

    return 0;
}
void contato(char letra){
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo um arquivo para leitura.
    FILE *file = fopen("agenda.dat","r");
//Verificação do arquivo.
    if(!file){
        printf("Erro, não é possivel abrir o arquivo\n");
    }
//Condição para ler o arquivo até o fim.
    while(!feof(file)){
        fscanf(file,"%i %s %s %s",&id, nome, profissao,telefone);
//Condição para verificar se a primeira letra do nome é igual a o caractere digitado pelo usuário.
        if(nome[0] == letra) {
            printf("%s - Telefone: %s\n",nome,telefone);
//Se a primeira letra foi igual ao caractere, a lista será imprimida apenas com os nomes que comecem com a letra expecífica e o telefone.
        }
    }
}