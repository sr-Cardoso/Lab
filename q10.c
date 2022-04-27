//Exportaçao de um contato para outro arquivo. Esse novo arquivo recebe o nome desse contato. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Criando a função que recebe o id para buscar o contato.
void ExportaContato(int indice);

int main(){
//Pedindo o Id.
    int id;
printf("Informe o ID do contato: ");
scanf("%i",&id);
//Chamada da função.
ExportaContato(id);

    return 0;
}
void ExportaContato(int indice){
//Abrindo o arquivo para escrita.
FILE *f = fopen("agenda2.dat", "w");
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo um segundo arquivo para leitura.
    FILE *ff = fopen("agenda.dat", "r");
    if(!ff){
//Verificação.
        printf("Impossivel abrir o arquivo!\n");
    }
//Condição para ler todo o arquivo.
    while(!feof(ff)){
        fscanf(ff,"%i %s %s %s",&id, nome, profissao, telefone);
//Quando o id do usuário for igual do arquivo, um arquivo para escrita será aberto. Logo em seguida, vai ser chamado uma função para concatenar ".txt" ao nome.
        if(indice == id){
        FILE *contato = fopen("aux.dat","w");
        fprintf(contato,"%i %s %s %s",id, nome, profissao, telefone);
        strcat(nome,".txt");
//O novo arquivo vai ser renomeado para o nome que pertence ao id que o usuário digitou. Obs: vai aparecer o nome do ID mais ".txt"
            rename("aux.dat",nome);
//Fechando o arquivo.
            fclose(contato);
        }
//Depois o arquivo f vai escrever todos os contatos que são difentes do id que o usuário digitou.
        else{
            fprintf(f,"%i %s %s %s\n",id, nome, profissao, telefone);
        }
    }
//Fechando os arquivos.
    fclose(f);
    fclose(ff);
//Removendo o arquivo de leitura.
    remove("agenda.dat");
//Renomeando o arquivo de escrita com o nome do arquivo deletado. Assim, vai acontecer a exportação do contado através do id que foi solicitado.
    rename("agenda2.dat","agenda.dat");
}