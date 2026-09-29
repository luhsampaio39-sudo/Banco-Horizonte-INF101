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

        switch (opcao) {
            case 1: {
                if (contaCadastrada) {
                    cout << "Ja existe uma conta cadastrada. Dados preservados.\n";
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
                        entradaValida = leitura.eof() && (numeroConta > 0);
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
    } while (opcao != 6);

    return 0;
}
