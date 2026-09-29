# Verificação do Banco Horizonte

## Resultado

As duas versões foram compiladas e executadas em Windows em **29/09/2026**, com **GCC 16.2.0 (w64devkit)**, usando C++11 e os parâmetros `-Wall -Wextra -Wpedantic -Werror`.

**Compilação sem erros nem avisos. Todos os 19 grupos de testes automatizados passaram.** Os testes incluem seis pontos de encerramento da entrada por versão e cinco verificações separadas de isolamento entre contas.

## Casos verificados

| Caso | Resultado esperado | Resultado |
|---|---|---|
| Menu com letras, sufixos, decimal, zero e opção 7 | Recusar e solicitar outra opção | Aprovado nas duas versões |
| Consultar, verificar saldo, alterar tipo e ativar sem cadastro | Informar que não existe conta | Aprovado nas duas versões |
| Número negativo, zero, texto, decimal ou acima de `int` | Recusar sem concluir cadastro | Aprovado nas duas versões |
| Nome vazio ou composto de espaços | Solicitar nome novamente | Aprovado nas duas versões |
| Nome com espaços internos | Preservar nome completo | Aprovado nas duas versões |
| CPF curto ou com letras | Recusar | Aprovado nas duas versões |
| CPF de 11 dígitos começando com zero | Preservar os 11 dígitos | Aprovado nas duas versões |
| Tipo 0 ou 3 | Recusar | Aprovado nas duas versões |
| Saldo negativo, texto, infinito, estouro ou vírgula decimal | Recusar | Aprovado nas duas versões |
| Saldo zero e saldo com centavos | Aceitar e mostrar duas casas decimais | Aprovado nas duas versões |
| Fim de entrada no menu e em cada campo do cadastro | Encerrar sem laço infinito nem cadastro parcial | Aprovado nas duas versões |
| Segundo cadastro na versão básica | Preservar conta existente | Aprovado |
| Alterar para o mesmo tipo | Informar que o tipo já está definido | Aprovado |
| Alterar de corrente para poupança | Atualizar tipo preservando saldo | Aprovado |
| Desativar conta e tentar consultar saldo ou alterar tipo | Bloquear as operações | Aprovado |
| Consultar dados de conta inativa | Mostrar cadastro e ocultar saldo | Aprovado |
| Reativar conta | Recuperar acesso ao mesmo saldo | Aprovado |
| Cadastrar cinco contas | Manter dados independentes | Aprovado |
| Tentar cadastrar sexta conta | Recusar sem sobrescrever dados | Aprovado |
| Cadastrar número repetido | Recusar e permitir outro número | Aprovado |
| Buscar número não cadastrado | Informar que a conta não foi encontrada | Aprovado |
| Alterar tipo e situação de cada uma das cinco contas | Preservar as outras quatro contas | Aprovado para cada posição |

## Como reproduzir

Compile as duas versões, conforme o README. Com Python 3 instalado, execute a partir da raiz do projeto:

```powershell
python tests/testar.py ./banco_horizonte.exe ./desafio_cinco_contas.exe
```

No Linux/macOS, informe os caminhos dos executáveis sem `.exe`. O script alimenta a entrada padrão dos programas e verifica as mensagens e os dados exibidos. Se qualquer condição falhar, encerra com erro e informa o caso.

Saída final esperada:

```text
OK - desafio: isolamento da conta 105
Todos os testes passaram.
```

## Correspondência com o enunciado

| Requisito | Implementação |
|---|---|
| Seis variáveis obrigatórias com os tipos pedidos | Presentes nas duas versões |
| Menu com seis opções | Presente nas duas versões |
| Seleção por `switch` | Presente nas duas versões |
| Repetição com `do while` até opção 6 | Presente nas duas versões |
| Nome do sistema no menu | Banco Horizonte |
| Cadastro de número, nome, CPF, tipo e saldo | Presente nas duas versões |
| Número positivo, saldo não negativo e tipo 1 ou 2 | Validados nas duas versões |
| Verificação de `contaAtiva` | Saldo e alteração de tipo exigem conta ativa |
| Código comentado | Comentários sobre fluxo e decisões |
| Resposta ao desafio de até cinco contas | Explicada em EXPLICACAO.md e implementada no segundo programa |

Os testes cobrem as regras descritas acima. Não há validação matemática de CPF, persistência em arquivos ou operações financeiras além das pedidas para esta etapa.
