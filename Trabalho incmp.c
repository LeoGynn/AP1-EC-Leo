#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define num_clientes 100
#define num_contas 200
//Função para limpar o buffer
void cleanStdin(){
    for (int c; (c = getchar()) != EOF && c != '\n';);
}
struct Cliente {
    char codigo[10];
    char cpf[15];
    char telefone[17];
    char endereco[90];
    char nome[80];
} typedef Cliente;

Cliente clientes[100];

 struct Conta {
   char agencia[5];
   char numero[10];
   float saldo;
   Cliente clientes[100];
 } typedef Conta;
 
 Conta contas[200];

int num_clientes_cadastrados=0;
int num_contas_cadastradas=0;
//Listagem de todas funções para não precisar ter ordem na posição das funções
void menu();
void gerenciar_clientes();
void cadastrar_clientes();
void gerenciar_contas();
void listar_clientes();
void buscar_cliente();
void atualizar_cliente();
void excluir_cliente();
void cadastrar_contas();
void listar_contas();
void saque();
void deposito();
void data();
//Função para o menu principal
void menu() {
    printf("=============== Bem vindo! =================");
    printf("\nDigite um comando para prosseguir: ");
    printf("\nC - Gerenciar Clientes");
    printf("\nT - Gerenciar Contas");
    printf("\nS - Sair\n");
    fflush(stdin);
    char opcmenu = toupper(getc(stdin));
    switch (opcmenu) {
        case 'C':
            gerenciar_clientes();
        case 'T':
            gerenciar_contas();
            break;
        case 'S':
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nErro, comando invalido, tente novamente\n");
            menu();
            break;
    }
}
//Função para gerenciar clientes
void gerenciar_clientes(){
    printf("\n============ Gerenciar Clientes ============");
    printf("\nDigite um comando para prosseguir:");
    printf("\nC - Cadastrar um cliente");
    printf("\nL - Listar todos os clientes cadastrados");
    printf("\nB - Buscar cliente ja cadastrado");
    printf("\nA - Atualizar um cliente cadastrado\n");
    printf("\nE - Excluir um cliente cadastrado\n");
    printf("\nS - Sair\n");
    cleanStdin();
    char comando_gc = toupper(getc(stdin));
    switch (comando_gc) {
        case 'C':
            cadastrar_clientes();
            break;
        case 'L':
            listar_clientes();
            break;
        case 'B':
            buscar_cliente();
            break;
        case 'A':
            atualizar_cliente();
            break;
        case 'E':
            excluir_cliente();
            break;
        case 'S':
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nErro, comando invalido, tente novamente");
            gerenciar_clientes();
            break;
    }
    menu();
}
//Função para cadastrar um cliente
void cadastrar_clientes() {
    for (int i = num_clientes_cadastrados; i < num_clientes; i++) {
        printf("Digite um numero de codigo para cadastro: ");
        gets(clientes[i].nome);
        printf("\nDigite um nome para cadastro: ");
        cleanStdin();
        gets(clientes[i].nome);
        printf("\nDigite um CPF/CNPJ para cadastro: ");
        gets(clientes[i].cpf);
        printf("\nDigite um telefone para cadastro: ");
        gets(clientes[i].telefone);
        printf("\nDigite um endereco para cadastro: ");
        gets(clientes[i].endereco);
        num_clientes_cadastrados++;
        printf("\nDeseja continuar ou sair?");
        printf("\nDigite Enter para continuar ou S para sair\n");
        char sair = toupper(getc(stdin));
        if (sair == 'S') {
            printf("\nSaindo...\n");
            break;
        }
    }
    menu();
}
//Função para listar os clientes cadastrados
void listar_clientes() {
    if (num_clientes_cadastrados == 0) {
        printf("Erro: Nenhum cliente cadastrado");
    } else {
        printf("\nClientes cadastrados:\n");
        for (int i = 0; i < num_clientes_cadastrados; i++) {
            printf("Codigo: %s\n", clientes[i].codigo);
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF/CNPJ: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("\n");
        }
    }
    printf("\nAperte Enter para sair\n");
    cleanStdin();
    getchar();
    gerenciar_clientes();
}
//Função para buscar um cliente cadastrado
void buscar_cliente(){
printf("\nDigite um dos seguintes dados para buscar um cliente:");
printf("\nNome, codigo ou CPF/CNPJ: ");
int teste=0;
char buscar[80];
int i;
cleanStdin();
gets(buscar);
    for(i = 0; i < num_clientes_cadastrados; i++) {
        if ((strcmp(buscar,clientes[i].codigo) == 0) || (strcmp(buscar,clientes[i].nome)== 0) || (strcmp(buscar,clientes[i].cpf)== 0)){
            teste += 1;
            break;
        }
    }
    if(teste == 0){
        printf("\nCliente nao encontrado\n");
        gerenciar_clientes();
    }else {
        printf("\nCliente encontrado:");
        printf("\nCodigo: %s", clientes[i].codigo);
        printf("\nNome: %s", clientes[i].nome);
        printf("CPF/CNPJ: %s", clientes[i].cpf);
    }
    printf("\nDigite qualquer tecla para tentar novamente ou S para sair");
    char sair = toupper(getc(stdin));
    if (sair == 'S') {
        printf("\nSaindo...\n");
    }
    gerenciar_clientes();
}

//Função para atualizar um cliente cadastrado
void atualizar_cliente() {
    printf("\nDigite um codigo ou CPF/CNPJ do cliente cadastrado para realizar uma atualizacao do cadastro:\n");
    char buscar[15];
    cleanStdin();
    gets(buscar);
    for(int i = 0; i < num_clientes_cadastrados; i++) {
        if ((strcmp(buscar,clientes[i].codigo) == 0) || (strcmp(buscar,clientes[i].cpf)== 0)){
                    printf("Digite um numero de codigo para atualizar o cadastro: ");
                    gets(clientes[i].codigo);
                    printf("\nDigite um nome para atualizar o cadastro: ");
                    cleanStdin();
                    gets(clientes[i].nome);
                    printf("\nDigite um CPF/CNPJ para atualizar o cadastro: ");
                    gets(clientes[i].cpf);
                    printf("\nDigite um telefone para atualizar o cadastro: ");
                    gets(clientes[i].telefone);
                    printf("\nDigite um endereco para atualizar o cadastro: ");
                    gets(clientes[i].endereco);
                    printf("\nDeseja continuar ou sair?");
                    printf("\nDigite Enter para continuar ou S para sair\n");
                    char sair = toupper(getc(stdin));
                    if (sair == 'S') {
                        printf("\nSaindo...\n");
                        break;
                    }
                }
                else {
                    printf("\nCliente não encontrado");
                }
            }
    gerenciar_clientes();
}
//Função para excluir um cliente
void excluir_cliente(){
    printf("\nDigite um codigo ou CPF/CNPJ do cliente que deseja excluir:\n");
    char buscar[15];
    int i, j;
    int teste=0;
    cleanStdin();
    gets(buscar);
    for(i = 0; i < num_clientes_cadastrados; i++) {
        if ((strcmp(buscar,clientes[i].codigo) == 0) || (strcmp(buscar,clientes[i].cpf)== 0)) {
            teste=+1;
        }
    }
    if(teste == 0) {
        printf("\nCliente nao encontrado\n");
        gerenciar_clientes();
    }else {
        printf("\nCliente encontrado:");
        printf("\nCodigo: %s", clientes[i].codigo);
        printf("\nNome: %s", clientes[i].nome);
        printf("CPF/CNPJ: %s", clientes[i].cpf);
        printf("\nDeseja excluir esse cliente?\n");
        printf("\nDigite S para sim e N para nao\n");
        char comando_excluir = toupper(getc(stdin));
        switch (comando_excluir) {
            case 'S':
                for (j = i; j < num_clientes_cadastrados - 1; j++) {
                    clientes[j] = clientes[j+1];
                }
                break;
            case 'N':
                printf("\nSaindo...\n");
                gerenciar_clientes();
                break;
            default:
                printf("\nComando invalido, tente novamente\n");
                excluir_cliente();
                break;
        }
    }
    gerenciar_clientes();
}
//Função para gerenciar as contas
void gerenciar_contas() {
    printf("\n============ Gerenciar Contas ============");
    printf("\nDigite um comando para prosseguir:");
    printf("\nC - Cadastrar um conta");
    printf("\nL - Listar todas as contas cadastrados");
    printf("\nA - Realizar uma saque");
    printf("\nD - Realizar um depósito\n");
    printf("\nS - Para Sair");
    char opcmenu = toupper(getc(stdin));
    switch (opcmenu) {
        case 'C':
            cadastrar_contas();
        case 'L':
            listar_contas();
        case 'A':
            saque();
        case 'D':
            deposito();
        case 'S':
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nErro, comando invalido, tente novamente\n");
            gerenciar_contas();
            break;
    }
    gerenciar_clientes();
}
//Função para cadastrar uma conta
void cadastrar_contas() {
    printf("\nDigite um codigo ou CPF/CNPJ do cliente cadastrado para realizar uma atualizacao do cadastro:\n");
    char buscar[80];
    int teste = 0;
    cleanStdin();
    gets(buscar);
    for (int i = 0; i < num_clientes_cadastrados; i++) {
        if ((strcmp(buscar, clientes[i].codigo) == 0) || (strcmp(buscar, clientes[i].cpf) == 0)) {
            teste += 1;
            break;
        }
    }
    if (teste == 0) {
        printf("\nCliente nao encontrado\n");
        gerenciar_contas();
    } else {
        for (int i = num_contas_cadastradas; i < num_contas; i++) {
            printf("Digite um numero da conta para cadastro: ");
            gets(contas[i].numero);
            printf("\nDigite uma agência para cadastro: ");
            cleanStdin();
            gets(contas[i].agencia);
            num_contas_cadastradas++;
            printf("\nDeseja continuar ou sair?");
            printf("\nDigite Enter para continuar ou S para sair\n");
            char sair = toupper(getc(stdin));
            if (sair == 'S') {
                printf("\nSaindo...\n");
                gerenciar_contas();
                break;
            }
        }
    }
    gerenciar_contas();
}
//Função para listar as contas cadastradas
void listar_contas() {
    if (num_contas_cadastradas == 0) {
        printf("Erro: Nenhuma conta cadastrada");
    } else {
        printf("\nContas cadastradas:\n");
        for (int i = 0; i < num_contas_cadastradas; i++) {
            printf("Numero: %s\n", contas[i].numero);
            printf("Agencia: %s\n", contas[i].agencia);
            printf("\n");
        }
    }
    printf("\nAperte Enter para sair\n");
    cleanStdin();
    getchar();
    gerenciar_contas();
}

//Função para saque
void saque() {
    printf("\nInforme a agencia e o numero da conta:\n");
    char var_agencia[5];
    char var_numero[10];
    int teste=0;
    gets(var_agencia);
    gets(var_numero);
    int i;
        for (i = 0; i < num_contas_cadastradas; i++) {
            if ((strcmp(var_agencia,contas[i].agencia) == 0) || (strcmp(var_numero,contas[i].numero) == 0)) {
                teste += 1;
            }
        }
        if (teste == 0) {
            printf("\nConta nao encontrada\n");
        }else {
            printf("\nContas cadastradas:\n");
            for (i = 0; i < num_contas_cadastradas; i++) {
                printf("Numero: %s\n", contas[i].numero);
                printf("Agencia: %s\n", contas[i].agencia);
                printf("Saldo: %f\n", contas[i].saldo);
                printf("\n");
            }
        }
        float sacar_valor;
        printf("Digite o valor que deseja sacar: ");
        scanf("%f", &sacar_valor);
        if (sacar_valor < contas[i].saldo) {
            printf("Saldo insuficiente, tente novamente\n");
        }else {
            (contas[i].saldo = contas[i].saldo - sacar_valor);
            printf("\nSaque realizado com sucesso\n");
            data();
        }
    gerenciar_contas();
}
//Função para depósito
void deposito() {
    printf("Informe a agencia e o numero da conta");
    char var_agencia[5];
    char var_numero[10];
    int teste=0;
    gets(var_agencia);
    gets(var_numero);
    int i;
    for (i = 0; i < num_contas_cadastradas; i++) {
        if ((strcmp(var_agencia,contas[i].agencia) == 0) || (strcmp(var_numero,contas[i].numero) == 0)) {
            teste += 1;
            break;
}   if (teste == 0) {
        printf("\nConta nao encontrada\n");
    }else {
        printf("\nContas cadastradas:\n");
        for (i = 0; i < num_contas_cadastradas; i++) {
            printf("Numero: %s\n", contas[i].numero);
            printf("Agencia: %s\n", contas[i].agencia);
            printf("Saldo: %f\n", contas[i].saldo);
            printf("\n");
        }
        printf("\nDigite o valor que deseja depositar e uma descricao pro deposito\n");
        char descricao[100];
        float depositar_valor;
        scanf("%f", &depositar_valor);
        gets(descricao);
        contas[i].saldo = contas[i].saldo + depositar_valor;
        printf("\nValor depositado com sucesso\n");
        data();
    }

}
//Função para informar a data/dia/ano
void data() {
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nDia: %d/", data_hora_atual->tm_mday);//dia
    printf("%d/",data_hora_atual->tm_mon+1); //mês
    printf("%d",data_hora_atual->tm_year+1900); //ano
    printf("\nAperte Enter para sair\n");
    getchar();
    gerenciar_contas();
}
int main() {
    printf("///////////////////////////////////////////////////////////////////////////////\n"
           "///                          Trabalho Pratico                               ///\n"
           "///                    Universidade Federal de Goias                        ///\n"
           "///               Professores: Ronaldo Costa e Guilherme                    ///\n"
           "///              Projeto: Sistema de cadastro de clientes                   ///\n"
           "///             Developed by  Leonardo Ribeiro - Jan, 2021                  ///\n"
           "///////////////////////////////////////////////////////////////////////////////\n");
    printf("\nInsira A para iniciar o sistema\n");
    char iniciar = toupper(getc(stdin));
    if(iniciar != 'A'){
        printf("\nErro, tente novamente.\n");
        main();
    }
    menu();
    printf("\nAperte Enter para sair do sistema\n");
    getchar();
}