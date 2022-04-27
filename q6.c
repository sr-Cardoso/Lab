/*
Listando os contatos por nome.
*/
#include <stdio.h>
#include <stdlib.h>
//Criando a função que recebe o id do contato que o usuário deseja apagar.
void Remover_Contato(int apagar);

int main(){
//Pedindo ao usuário o ID do contato.
int id;
printf("Informe o ID do contato para ser removido\n");
scanf("%i",&id);
//Chamada da função.
Remover_Contato(id);

    return 0;
}
void Remover_Contato(int apagar){
    //Abrindo um arquivo para escrita.
    FILE *arq1 = fopen("agendaAux.dat","w");

    int id;
    char nome[80];
    char profissao[80];
    char telefone[80];
//Abrindo um arquivo para leitura.
    FILE *arq2 = fopen("agenda.dat","r");
//Verificação do arquivo.
if(!arq2){
    printf("Impossivel abrir o arquivo\n");
}
//Condição para ler o arquivo até o fim.
while(!feof(arq2)){
    fscanf(arq2,"%i %s %s %s",&id, nome, profissao, telefone);
//Quando o ID for diferente do que foi passado para a função, o arquivo "arq1" irá escrever todos os contatos que tem esse id diferente.
    if(id != apagar){
        fprintf(arq1,"%i %s %s %s\n",id, nome, profissao, telefone);
    }
}
//Fechando os arquivos.
fclose(arq1);
fclose(arq2);
//Removendo o segundo arquivo.
remove("agenda.dat");
//Renomendo o primeirio com o nome do segundo. Assim, vai permanecer o arquivo que não tem o contato que o usuário digitou, ou seja, vai apagar o contato.
rename("agendaAux.dat","agenda.dat");
}