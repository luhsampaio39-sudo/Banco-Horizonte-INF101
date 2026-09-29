# Explicação e roteiro de apresentação

## Como o programa funciona

1. Inicializa todas as variáveis. Não existe conta cadastrada ao iniciar.
2. Exibe o menu dentro de um `do while`.
3. Lê e valida a opção, utilizando um `switch` para executar a operação.
4. No cadastro, solicita os campos e repete cada pergunta até receber uma entrada válida.
5. Marca a conta como cadastrada e ativa somente depois de validar todos os campos.
6. Retorna ao menu após cada operação. A opção 6 encerra a repetição.

`getline` lê a linha completa, inclusive nomes com espaços. Para números, `istringstream` tenta converter a linha e verifica se todo o conteúdo foi consumido. Isso impede que uma entrada como `12abc` seja aceita como `12`. A falha fica no fluxo temporário de leitura, permitindo repetir a pergunta normalmente.

## Resposta ao desafio: como cadastrar até cinco contas?

Dentro da restrição de utilizar variáveis individuais, uma solução possível é declarar cinco conjuntos dos campos da conta: `numeroConta1`, `nomeCliente1`, `cpf1`, `tipoConta1`, `saldo1` e `contaAtiva1`, repetindo esse conjunto até o sufixo 5.

Essa solução está implementada em [desafio_cinco_contas.cpp](../desafio_cinco_contas.cpp). `quantidadeContas` controla a capacidade e indica a próxima posição de cadastro. Como não existe exclusão de contas, as posições são preenchidas sequencialmente. Desativar uma conta não libera sua posição.

Para consultar ou modificar uma conta, o programa compara o número informado com os cinco números armazenados. O número zero identifica posições ainda vazias e nunca é aceito na entrada. Um `switch` carrega a conta encontrada nas variáveis de trabalho. Após cadastro, alteração de tipo ou mudança de situação, outro `switch` copia os campos de volta para o conjunto correspondente.

**Limitação:** a solução repete declarações e atribuições. Para cem contas, ela seria extensa e difícil de manter. Nas próximas etapas, arrays podem representar as coleções de dados e funções podem reunir tarefas repetidas. Aqui a repetição é intencional para manter a proposta didática da Etapa 1.

## Decisões complementares

- Não foram adicionados campos pessoais desnecessários. Foram acrescentadas apenas variáveis de controle.
- O enunciado não detalha quais operações dependem de conta ativa. Neste projeto, consulta de saldo e alteração de tipo dependem; consulta cadastral e ativação não dependem. A regra está explícita no README e no código.
- O CPF é armazenado como texto porque não é uma quantidade e pode começar com zero. O mesmo CPF pode ter mais de uma conta; o identificador único é o número da conta.
- A mudança de tipo não altera o saldo. Desativação e reativação também preservam os dados.
- `fixed` e `setprecision(2)` controlam a apresentação do saldo.
- `isfinite` rejeita valores não finitos, além da verificação de saldo não negativo.
- As contas são armazenadas somente em memória, respeitando a progressão para persistência em etapas posteriores.

## Roteiro para demonstrar no laboratório

1. Compile e execute `banco_horizonte.cpp`.
2. Antes de cadastrar, escolha 2 ou 3 e mostre o aviso de ausência de conta.
3. Cadastre a conta 101, nome `Cliente Demonstracao`, CPF fictício `00000000000`, tipo 1 e saldo 250.50.
4. Demonstre uma entrada inválida: número zero, tipo 3 ou saldo negativo. Explique por que a pergunta se repete.
5. Consulte a conta e confira nome, tipo, situação e saldo.
6. Altere o tipo para 2 e consulte novamente.
7. Desative a conta, tente consultar o saldo e tente alterar o tipo.
8. Consulte os dados cadastrais da conta inativa e observe a ocultação do saldo.
9. Reative a conta e confira que o saldo continua igual.
10. Saia com 6. Compile e execute `desafio_cinco_contas.cpp` separadamente.
11. Cadastre cinco contas com números distintos. Consulte a primeira e a quinta.
12. Altere ou desative apenas uma delas e confira que as outras não mudaram.
13. Tente cadastrar uma sexta conta e mostre a mensagem de limite.

## Pontos para estudar antes da apresentação

Explique a diferença entre `contaCadastrada` e `contaAtiva`, o papel do `break` no `switch`, por que o menu usa `do while`, por que CPF usa `string` e como os cinco conjuntos de variáveis mantêm contas independentes. Execute o roteiro para se familiarizar com cada decisão do código.
