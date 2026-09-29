# Banco Horizonte

**Sistema de Registro e Gestão de Contas Bancárias — Etapa 1**

Projeto acadêmico em C++ para a disciplina **INF101 — Programação de Computadores I**, do **Centro Universitário de Viçosa — UNIVIÇOSA**.

| Informação | Descrição |
|---|---|
| Identificação | [luhsampaio39-sudo](https://github.com/luhsampaio39-sudo) |
| Professores | Anderson R. Lamas e Vanderlea Queiroz |
| Etapa | Variáveis individuais e estruturas de controle |
| Entrega prevista no enunciado | 30/09/2026 |
| Linguagem | C++11 ou superior |

## Apresentação

O Banco Horizonte permite cadastrar uma conta, consultar seus dados, verificar o saldo, alterar seu tipo e controlar sua situação. O menu permanece em execução até a opção **6 — Sair**.

A versão principal implementa uma conta com as seis variáveis obrigatórias. O desafio amplia a capacidade para cinco contas, mantendo conjuntos de variáveis individuais. Cada arquivo é um programa independente e possui seu próprio `main`.

## Arquivos

| Arquivo | Conteúdo |
|---|---|
| [banco_horizonte.cpp](banco_horizonte.cpp) | Versão principal: cadastro e gestão de uma conta |
| [desafio_cinco_contas.cpp](desafio_cinco_contas.cpp) | Desafio implementado: até cinco contas independentes |
| [docs/EXPLICACAO.md](docs/EXPLICACAO.md) | Decisões, resposta ao desafio e roteiro para apresentação |
| [docs/TESTES.md](docs/TESTES.md) | Casos de teste e resultados |
| [tests/testar.py](tests/testar.py) | Testes automatizados dos programas compilados |

## Como compilar e executar

É necessário um compilador C++ com suporte a C++11, como GCC/MinGW. Execute os comandos na pasta do projeto. **Compile um arquivo por vez**, pois ambos contêm `main`.

### Windows — PowerShell

```powershell
g++ -std=c++11 -Wall -Wextra -Wpedantic banco_horizonte.cpp -o banco_horizonte.exe
.\banco_horizonte.exe

g++ -std=c++11 -Wall -Wextra -Wpedantic desafio_cinco_contas.cpp -o desafio_cinco_contas.exe
.\desafio_cinco_contas.exe
```

### Linux ou macOS com GCC instalado

```bash
g++ -std=c++11 -Wall -Wextra -Wpedantic banco_horizonte.cpp -o banco_horizonte
./banco_horizonte

g++ -std=c++11 -Wall -Wextra -Wpedantic desafio_cinco_contas.cpp -o desafio_cinco_contas
./desafio_cinco_contas
```

Em uma IDE ou compilador on-line, abra apenas o arquivo da versão desejada e escolha C++11 ou superior. Os programas usam exclusivamente a biblioteca padrão, sem bibliotecas externas.

## Menu

```text
========================================
             BANCO HORIZONTE
          INF101 - ETAPA 1
========================================
1 - Cadastrar conta
2 - Consultar conta
3 - Verificar saldo
4 - Alterar tipo da conta
5 - Ativar/Desativar conta
6 - Sair
```

Na versão do desafio, as opções 2 a 5 solicitam o número da conta que será utilizada.

## Variáveis obrigatórias

| Variável | Tipo | Uso |
|---|---|---|
| `numeroConta` | `int` | Número positivo da conta |
| `nomeCliente` | `string` | Nome completo do titular |
| `cpf` | `string` | CPF, preservando zeros iniciais |
| `tipoConta` | `int` | 1 para corrente; 2 para poupança |
| `saldo` | `double` | Saldo inicial não negativo |
| `contaAtiva` | `bool` | Situação da conta |

`contaCadastrada` distingue uma conta ainda não criada de uma conta cadastrada e desativada.

## Regras e validações

- O número da conta deve ser um inteiro positivo. No desafio, números repetidos são recusados.
- O nome não pode estar vazio nem conter apenas espaços ou tabulações.
- O CPF deve conter exatamente 11 algarismos, sem pontuação. A validação é de **formato**, sem cálculo dos dígitos verificadores.
- O tipo aceita somente 1 ou 2.
- O saldo aceita valores finitos maiores ou iguais a zero. Use **ponto** como separador decimal, por exemplo `125.50`.
- Uma conta recém-cadastrada fica ativa.
- Verificar saldo e alterar tipo exigem conta ativa. A consulta cadastral e a reativação continuam disponíveis quando a conta está inativa; o saldo fica oculto na consulta de conta inativa.
- Entradas como letras em campos numéricos, `1abc`, `1.5` em campos inteiros e valores fora da faixa são rejeitadas sem travar o menu.
- Um segundo cadastro não sobrescreve a conta na versão básica. No desafio, a sexta conta é recusada e as cinco existentes são preservadas.
- O encerramento da entrada também termina o programa com segurança, inclusive durante o cadastro.

## Exemplo de utilização

Dados fictícios para demonstração, sem CPF real:

```text
Escolha: 1
Numero da nova conta: 101
Nome do titular: Cliente Demonstracao
CPF (11 digitos, sem pontuacao): 00000000000
Tipo (1 = Corrente; 2 = Poupanca): 1
Saldo inicial (use ponto nos centavos): R$ 250.50
Conta cadastrada com sucesso e ativada.

Escolha: 3
Saldo atual: R$ 250.50
```

## Limites desta etapa

Os dados existem somente durante a execução. Não há depósitos, saques, transferências, autenticação ou gravação em arquivos, pois essas funções não fazem parte do enunciado da Etapa 1. O saldo usa `double` conforme solicitado e é apresentado com duas casas decimais. As mensagens do terminal usam caracteres sem acento para compatibilidade entre ambientes.

O código não utiliza arrays, vetores, `struct`, classes próprias ou funções auxiliares. `string` representa os campos textuais exigidos; `istringstream` auxilia a validação da linha digitada. A repetição de variáveis no desafio evidencia por que arrays e funções serão úteis nas etapas seguintes.

## Verificação

Depois de compilar os dois programas, execute:

```powershell
python tests/testar.py ./banco_horizonte.exe ./desafio_cinco_contas.exe
```

No Linux/macOS, use os nomes dos executáveis sem `.exe`. Consulte [os testes](docs/TESTES.md) e [o roteiro de apresentação](docs/EXPLICACAO.md).
