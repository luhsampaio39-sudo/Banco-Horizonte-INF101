// Banco Horizonte | INF101 - Etapa 1 | luhsampaio39-sudo
// Dados somente em memoria; sem arrays, structs ou funcoes auxiliares.
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Campos exigidos pelo enunciado. Na versao de cinco contas,
    // estes campos tambem representam a conta selecionada para operacao.
    int numeroConta = 0;
    string nomeCliente;
    string cpf;
    int tipoConta = 0;
    double saldo = 0.0;
    bool contaAtiva = false;
    bool contaCadastrada = false;
    int opcao = 0;
    string entrada;
    bool entradaValida = false;
    int quantidadeContas = 0;
    int posicao = 0;
    int numeroBusca = 0;
    // Conjunto independente de variaveis para a conta 1.
    int numeroConta1 = 0;
    string nomeCliente1, cpf1;
    int tipoConta1 = 0;
    double saldo1 = 0.0;
    bool contaAtiva1 = false;
    // Conjunto independente de variaveis para a conta 2.
    int numeroConta2 = 0;
    string nomeCliente2, cpf2;
    int tipoConta2 = 0;
    double saldo2 = 0.0;
    bool contaAtiva2 = false;
    // Conjunto independente de variaveis para a conta 3.
    int numeroConta3 = 0;
    string nomeCliente3, cpf3;
    int tipoConta3 = 0;
    double saldo3 = 0.0;
    bool contaAtiva3 = false;
    // Conjunto independente de variaveis para a conta 4.
    int numeroConta4 = 0;
    string nomeCliente4, cpf4;
    int tipoConta4 = 0;
    double saldo4 = 0.0;
    bool contaAtiva4 = false;
    // Conjunto independente de variaveis para a conta 5.
    int numeroConta5 = 0;
    string nomeCliente5, cpf5;
    int tipoConta5 = 0;
    double saldo5 = 0.0;
    bool contaAtiva5 = false;

    cout << fixed << setprecision(2);
    // O menu reaparece ate a escolha de 6; EOF tambem encerra com seguranca.
    do {
        cout << "\n========================================\n"
             << "             BANCO HORIZONTE\n"
             << "          INF101 - ETAPA 1\n"
             << "========================================\n"
             << "1 - Cadastrar conta\n"
             << "2 - Consultar conta\n"
             << "3 - Verificar saldo\n"
             << "4 - Alterar tipo da conta\n"
             << "5 - Ativar/Desativar conta\n"
             << "6 - Sair\n";
        cout << "Contas cadastradas: " << quantidadeContas << "/5\n";
        do {
            cout << "Escolha: ";
            if (!getline(cin, entrada)) {
                cout << "\nEntrada encerrada. Programa finalizado.\n";
                return 0;
            }
            istringstream leitura(entrada);
            entradaValida = static_cast<bool>(leitura >> opcao);
            if (entradaValida) {
                leitura >> ws;
                entradaValida = leitura.eof() && (opcao >= 1 && opcao <= 6);
            }
            if (!entradaValida) cout << "Opcao invalida. Digite um inteiro de 1 a 6.\n";
        } while (!entradaValida);

        // As operacoes 2 a 5 localizam uma conta pelo numero.
        if (opcao >= 2 && opcao <= 5) {
            if (quantidadeContas == 0) {
                cout << "Nenhuma conta cadastrada. Use a opcao 1.\n";
                continue;
            }
            do {
                cout << "Numero da conta: ";
                if (!getline(cin, entrada)) {
                    cout << "\nEntrada encerrada. Programa finalizado.\n";
                    return 0;
                }
                istringstream leitura(entrada);
                entradaValida = static_cast<bool>(leitura >> numeroBusca);
                if (entradaValida) {
                    leitura >> ws;
                    entradaValida = leitura.eof() && (numeroBusca > 0);
                }
                if (!entradaValida) cout << "Informe um numero inteiro positivo.\n";
            } while (!entradaValida);
            posicao = 0;
            if (numeroBusca == numeroConta1) posicao = 1;
            else if (numeroBusca == numeroConta2) posicao = 2;
            else if (numeroBusca == numeroConta3) posicao = 3;
            else if (numeroBusca == numeroConta4) posicao = 4;
            else if (numeroBusca == numeroConta5) posicao = 5;
            if (posicao == 0) {
                cout << "Conta nao encontrada.\n";
                continue;
            }
            // Carrega os campos da conta escolhida, sem arrays ou ponteiros.
            switch (posicao) {
                case 1:
                    numeroConta = numeroConta1;
                    nomeCliente = nomeCliente1;
                    cpf = cpf1;
                    tipoConta = tipoConta1;
                    saldo = saldo1;
                    contaAtiva = contaAtiva1;
                    break;
                case 2:
                    numeroConta = numeroConta2;
                    nomeCliente = nomeCliente2;
                    cpf = cpf2;
                    tipoConta = tipoConta2;
                    saldo = saldo2;
                    contaAtiva = contaAtiva2;
                    break;
                case 3:
                    numeroConta = numeroConta3;
                    nomeCliente = nomeCliente3;
                    cpf = cpf3;
                    tipoConta = tipoConta3;
                    saldo = saldo3;
                    contaAtiva = contaAtiva3;
                    break;
                case 4:
                    numeroConta = numeroConta4;
                    nomeCliente = nomeCliente4;
                    cpf = cpf4;
                    tipoConta = tipoConta4;
                    saldo = saldo4;
                    contaAtiva = contaAtiva4;
                    break;
                case 5:
                    numeroConta = numeroConta5;
                    nomeCliente = nomeCliente5;
                    cpf = cpf5;
                    tipoConta = tipoConta5;
                    saldo = saldo5;
                    contaAtiva = contaAtiva5;
                    break;
            }
            contaCadastrada = true;
        }

        switch (opcao) {
            case 1: {
                if (quantidadeContas == 5) {
                    cout << "Limite de cinco contas atingido.\n";
                    break;
                }
                do {
                    cout << "Numero da nova conta: ";
                    if (!getline(cin, entrada)) {
                        cout << "\nEntrada encerrada. Programa finalizado.\n";
                        return 0;
                    }
                    istringstream leitura(entrada);
                    entradaValida = static_cast<bool>(leitura >> numeroConta);
                    if (entradaValida) {
                        leitura >> ws;
                        entradaValida = leitura.eof() && (numeroConta > 0 && numeroConta != numeroConta1 && numeroConta != numeroConta2 && numeroConta != numeroConta3 && numeroConta != numeroConta4 && numeroConta != numeroConta5);
                    }
                    if (!entradaValida) cout << "Numero invalido ou ja cadastrado. Use um inteiro positivo e unico.\n";
                } while (!entradaValida);
                // getline preserva espacos no nome completo.
                do {
                    cout << "Nome do titular: ";
                    if (!getline(cin, nomeCliente)) {
                        cout << "\nEntrada encerrada. Cadastro nao concluido.\n";
                        return 0;
                    }
                    entradaValida = nomeCliente.find_first_not_of(" \t\r") != string::npos;
                    if (!entradaValida) cout << "O nome nao pode ficar vazio.\n";
                } while (!entradaValida);

                // Validacao de formato: 11 digitos. Nao valida digitos verificadores.
                do {
                    cout << "CPF (11 digitos, sem pontuacao): ";
                    if (!getline(cin, cpf)) {
                        cout << "\nEntrada encerrada. Cadastro nao concluido.\n";
                        return 0;
                    }
                    entradaValida = cpf.size() == 11;
                    for (char digito : cpf) {
                        if (digito < '0' || digito > '9') entradaValida = false;
                    }
                    if (!entradaValida) cout << "Informe exatamente 11 digitos numericos.\n";
                } while (!entradaValida);
                do {
                    cout << "Tipo (1 = Corrente; 2 = Poupanca): ";
                    if (!getline(cin, entrada)) {
                        cout << "\nEntrada encerrada. Programa finalizado.\n";
                        return 0;
                    }
                    istringstream leitura(entrada);
                    entradaValida = static_cast<bool>(leitura >> tipoConta);
                    if (entradaValida) {
                        leitura >> ws;
                        entradaValida = leitura.eof() && (tipoConta == 1 || tipoConta == 2);
                    }
                    if (!entradaValida) cout << "Tipo invalido. Digite 1 ou 2.\n";
                } while (!entradaValida);
                do {
                    cout << "Saldo inicial (use ponto nos centavos): R$ ";
                    if (!getline(cin, entrada)) {
                        cout << "\nEntrada encerrada. Programa finalizado.\n";
                        return 0;
                    }
                    istringstream leitura(entrada);
                    entradaValida = static_cast<bool>(leitura >> saldo);
                    if (entradaValida) {
                        leitura >> ws;
                        entradaValida = leitura.eof() && (isfinite(saldo) && saldo >= 0.0);
                    }
                    if (!entradaValida) cout << "Saldo invalido. Use um numero finito nao negativo, como 150.50.\n";
                } while (!entradaValida);
                // O cadastro so se conclui depois da validacao de todos os campos.
                contaAtiva = true;
                contaCadastrada = true;
                ++quantidadeContas;
                posicao = quantidadeContas;
                cout << "Conta cadastrada com sucesso e ativada.\n";
                break;
            }
            case 2:
                if (!contaCadastrada) {
                    cout << "Nenhuma conta cadastrada. Use a opcao 1.\n";
                    break;
                }
                // A consulta cadastral continua disponivel para contas inativas.
                cout << "\n--- DADOS DA CONTA ---\n"
                     << "Numero: " << numeroConta << '\n'
                     << "Titular: " << nomeCliente << '\n'
                     << "CPF: " << cpf << '\n'
                     << "Tipo: " << (tipoConta == 1 ? "Corrente" : "Poupanca") << '\n'
                     << "Situacao: " << (contaAtiva ? "Ativa" : "Inativa") << '\n';
                if (contaAtiva) cout << "Saldo: R$ " << saldo << '\n';
                else cout << "Saldo indisponivel: ative a conta para consultar.\n";
                break;
            case 3:
                if (!contaCadastrada) cout << "Nenhuma conta cadastrada. Use a opcao 1.\n";
                else if (!contaAtiva) cout << "Conta inativa. Ative-a para verificar o saldo.\n";
                else cout << "Saldo atual: R$ " << saldo << '\n';
                break;
            case 4: {
                if (!contaCadastrada) {
                    cout << "Nenhuma conta cadastrada. Use a opcao 1.\n";
                    break;
                }
                if (!contaAtiva) {
                    cout << "Conta inativa. Ative-a antes de alterar o tipo.\n";
                    break;
                }
                int novoTipo = 0;
                do {
                    cout << "Novo tipo (1 = Corrente; 2 = Poupanca): ";
                    if (!getline(cin, entrada)) {
                        cout << "\nEntrada encerrada. Programa finalizado.\n";
                        return 0;
                    }
                    istringstream leitura(entrada);
                    entradaValida = static_cast<bool>(leitura >> novoTipo);
                    if (entradaValida) {
                        leitura >> ws;
                        entradaValida = leitura.eof() && (novoTipo == 1 || novoTipo == 2);
                    }
                    if (!entradaValida) cout << "Tipo invalido. Digite 1 ou 2.\n";
                } while (!entradaValida);
                if (novoTipo == tipoConta) cout << "A conta ja possui esse tipo.\n";
                else {
                    tipoConta = novoTipo;
                    cout << "Tipo da conta alterado com sucesso.\n";
                }
                break;
            }
            case 5:
                if (!contaCadastrada) {
                    cout << "Nenhuma conta cadastrada. Use a opcao 1.\n";
                    break;
                }
                // Uma conta inativa pode ser reativada; seus dados sao preservados.
                contaAtiva = !contaAtiva;
                cout << (contaAtiva ? "Conta ativada.\n" : "Conta desativada.\n");
                break;
            case 6:
                cout << "Banco Horizonte encerrado. Obrigado!\n";
                break;
        }
        // Grava de volta somente as operacoes que podem modificar uma conta.
        if (contaCadastrada && (opcao == 1 || opcao == 4 || opcao == 5)) {
            switch (posicao) {
                case 1:
                    numeroConta1 = numeroConta;
                    nomeCliente1 = nomeCliente;
                    cpf1 = cpf;
                    tipoConta1 = tipoConta;
                    saldo1 = saldo;
                    contaAtiva1 = contaAtiva;
                    break;
                case 2:
                    numeroConta2 = numeroConta;
                    nomeCliente2 = nomeCliente;
                    cpf2 = cpf;
                    tipoConta2 = tipoConta;
                    saldo2 = saldo;
                    contaAtiva2 = contaAtiva;
                    break;
                case 3:
                    numeroConta3 = numeroConta;
                    nomeCliente3 = nomeCliente;
                    cpf3 = cpf;
                    tipoConta3 = tipoConta;
                    saldo3 = saldo;
                    contaAtiva3 = contaAtiva;
                    break;
                case 4:
                    numeroConta4 = numeroConta;
                    nomeCliente4 = nomeCliente;
                    cpf4 = cpf;
                    tipoConta4 = tipoConta;
                    saldo4 = saldo;
                    contaAtiva4 = contaAtiva;
                    break;
                case 5:
                    numeroConta5 = numeroConta;
                    nomeCliente5 = nomeCliente;
                    cpf5 = cpf;
                    tipoConta5 = tipoConta;
                    saldo5 = saldo;
                    contaAtiva5 = contaAtiva;
                    break;
            }
        }
    } while (opcao != 6);

    return 0;
}
