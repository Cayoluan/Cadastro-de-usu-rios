
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Cadastro();
void Listar();


struct VarG {
    int Op;
    char Cd;

}; 

struct Cadastro {
    char Nome[50];
    char Email[50];
    char Senha[50];

}; 

FILE* DB;

struct VarG Global;
struct Cadastro Pessoa;

int main() {
	setlocale(LC_ALL,"");
    system("cls"); 
    printf("Cadastre o seu VPN\n\n");
    printf("[1] - Cadastre-se\n");
    printf("[2] - Listar os cadastros\n");
    printf("[3] - Fechar\n\n");
    printf("Operação:");
    scanf("%d", &Global.Op);
    getchar(); 
    switch (Global.Op) {
        case 1:
            Cadastro(); 
            break;
            
        case 2:
            Listar(); 
            break;
        
        case 3:
            system("cls");
            printf("# Aperte qualquer tecla para fechar o programa... #\n");
            break;
    }
    return 0;
} 

void Cadastro() {
    system("cls");
    DB = fopen("dados.txt", "a"); 

    if(DB == NULL) { 
        printf("\n Erro no Banco de Dados...\n");

    } else {
        printf(" CADASTRO\n");

        printf("\n Nome: ");
        fgets(Pessoa.Nome, 50, stdin); 
        
        printf("\n E-mail: ");
        fgets(Pessoa.Email, 50, stdin); 
        
        printf("\n Digite sua senha: ");
        fgets(Pessoa.Senha, 50, stdin); 

        system("cls");
        printf("Deseja finalizar o seu cadastro? [s/n] : ");
        scanf("%c", &Global.Cd); 

        if(Global.Cd == 's') {
            fprintf(DB, "Nome: %sE-mail: %sSenha: %s", Pessoa.Nome, Pessoa.Email, Pessoa.Senha);
            fprintf(DB, "----------------------\n"); 

            fclose(DB); 

            system("cls");
            printf("# Cadastro Concluído #\n");

            main();

        } else if(Global.Cd == 'n') {
            system("cls");
            printf("Cadastro Cancelado.\n Voltando ao Menu Principal...\n");
            fclose(DB); 
            getchar();        
            main();

        } else {
            printf("Valor inválido. Tente novamente...\n");
            fclose(DB); 
            Cadastro();

        }

    }

} 

void Listar() {
    system("cls");
    DB = fopen("dados.txt", "r"); 

    if(DB == NULL) { 
        printf("\n Erro no Banco de Dados...\n");

    } else {
        printf(" LISTAGEM DE CLIENTES\n");
        char listagem[250]; 

        while(fgets(listagem, 250, DB) != NULL) {
            printf("%s", listagem);

        } 

        fclose(DB);

        printf("\n Deseja voltar ao Menu Principal? [s/n]: ");
        scanf("%c", &Global.Cd);

        if(Global.Cd == 's') {
            main();

        } else if(Global.Cd != 's' && Global.Cd != 'n') {
            printf("Valor inválido. Voltando ao Menu Principal...\n");
            main();

        }

    }

}
