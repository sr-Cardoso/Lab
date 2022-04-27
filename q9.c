/*
Alterando o telefone do contato.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função que recebe o id do contato que o usuário deseja alterar e o novo telefone.
void NovoTelefone(int indice, char TelefoneNovo[80]);

int main(){
int id;
char telefone[80];
//Pedindo o ID.
printf("Informe O id do contato: ");
scanf("%i",&id);
//Pedindo o novo número.
printf("Digite o novo numero: ");
scanf("%s", telefone);
//Chamada da função.
NovoTelefone(id,telefone);   
    
    return 0;
}
void NovoTelefone(int indice, char TelefoneNovo[80]){
//Abrindo um arquivo para a escrita.
    FILE *f1 = fopen("agenda2.dat","w");
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo um segundo arquivo para leitura.
    FILE *f2 = fopen("agenda.dat","r");
    if(!f2){
//Verificação.
        printf("Impossivel abrir o arquivo\n");
    }
//Condição para ler o arquivo completo.
    while(!feof(f2)){
        fscanf(f2,"%i %s %s %s",&id,nome,profissao,telefone);
//Quando o id que o usuário digito for igual ao do arquivo, irá escrever o contato incluindo o novo telefone.
        if(indice == id){
            fprintf(f1,"%i %s %s %s\n",id, nome, profissao, TelefoneNovo);
        }
//Em seguida vai escrever todos os contatos com o id diferente do que o usuário digitou.
        else{
            fprintf(f1,"%i %s %s %s\n",id, nome, profissao, telefone);
        }
    }
//Fechando os arquivos.
    fclose(f1);
    fclose(f2);
//Removendo o segundo arquivo.
    remove("agenda.dat");
//Renomeando o primeiro aequivo que contém o novo número de telefone. O primeiro arquivo ganha o nome do que foi deletado.
    rename("agenda2.dat","agenda.dat");
}