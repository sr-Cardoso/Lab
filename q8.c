/*
Alterando o nome do contato.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função que recebe o id do contato que o usuário deseja alterar e o nome para ser substituido.
void Substituicao(int indice, char trocaNome[80]);

int main(){

int id;
char NovoNome[80];
//Pedindo o id.
printf("Informe o ID do contato: ");
scanf("%i",&id);
//Pedindo o novo nome.
printf("Digite o novo nome: ");
scanf("%s",NovoNome);
//Chamada da função.
Substituicao(id, NovoNome);

    return 0;
}
void Substituicao(int indice, char trocaNome[80]){
//Abrindo o arquivo para escrita.
    FILE *f1 = fopen("agendaAux.dat","w");
    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo o arquivo para leitura.
    FILE *f2 = fopen("agenda.dat","r");
//Verificação.
    if(!f2){
        printf("Impossivel abrir o arquivo!\n");
    }
//Condição para ler o arquivo completo.
    while(!feof(f2)){
        fscanf(f2,"%i %s %s %s", &id, nome, profissao, telefone);
    //Quando o id que o usuário digitou for igual ao do arquivo, vai ser escrito no primeiro arquivo o novo nome do contato.
        if(id == indice){
            fprintf(f1,"%i %s %s %s\n",id, trocaNome, profissao, telefone);
        }
//Logo em seguida, vai ser escrito todos os contatos que forem diferentes do que o usuário digitou.
        else{
            fprintf(f1,"%i %s %s %s\n",id, nome, profissao, telefone);
        }
    }
//Fechando os arquivos.
    fclose(f1);
    fclose(f2);
//Removendo o segundo arquivo.
    remove("agenda.dat");
//Renomendo o primeiro arquivo que contém o nome alterado pelo o usuário. O arquivo vai ser renomado com o nome do arquivo que foi deletado.
    rename("agendaAux.dat","agenda.dat");
}