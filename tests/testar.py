"""Testes de caixa-preta. Uso: python tests/testar.py executavel1 executavel5."""
from pathlib import Path
import subprocess
import sys


def executar(exe, linhas):
    resultado = subprocess.run(
        [str(Path(exe).resolve())], input="\n".join(map(str, linhas)) + "\n",
        text=True, capture_output=True, timeout=5,
    )
    assert resultado.returncode == 0, resultado.stderr
    assert not resultado.stderr, resultado.stderr
    return resultado.stdout


def cadastro(numero=101, nome="Cliente Demonstracao", tipo=1, saldo="250.50"):
    return [1, numero, nome, "00000000000", tipo, saldo]


def verificar(nome, saida, presentes=(), ausentes=(), contagens=None):
    for trecho in presentes:
        assert trecho in saida, f"{nome}: faltou {trecho!r}\n{saida}"
    for trecho in ausentes:
        assert trecho not in saida, f"{nome}: encontrou {trecho!r}\n{saida}"
    for trecho, quantidade in (contagens or {}).items():
        assert saida.count(trecho) == quantidade, f"{nome}: contagem de {trecho!r}"
    print(f"OK - {nome}")


def main():
    if len(sys.argv) != 3:
        raise SystemExit("Uso: python tests/testar.py executavel_basico executavel_desafio")
    basico, desafio = sys.argv[1:]
    for exe, nome in [(basico, "basico"), (desafio, "desafio")]:
        verificar(f"{nome}: menu invalido e saida", executar(exe, ["abc", "1abc", "1.5", 0, 7, 6]),
                  ["Banco Horizonte encerrado"], contagens={"Opcao invalida": 5})
        verificar(f"{nome}: operacoes sem conta", executar(exe, [2, 3, 4, 5, 6]),
                  contagens={"Nenhuma conta cadastrada": 4})
        dados = [1, "abc", -1, 0, "2147483648", "1.5", 101, "", "   ",
                 "Nome Com Espacos", "123", "0000000000a", "00000000000", 0, 3, 1,
                 -1, "nan", "inf", "1e9999", "10,50", "10abc", "250.50", 2]
        if exe == desafio:
            dados.append(101)
        verificar(f"{nome}: validacoes do cadastro", executar(exe, dados + [6]),
                  ["Titular: Nome Com Espacos", "CPF: 00000000000", "Saldo: R$ 250.50"],
                  contagens={"Numero invalido": 5, "O nome nao pode": 2,
                             "Informe exatamente": 2, "Tipo invalido": 2, "Saldo invalido": 6,
                             "Conta cadastrada com sucesso": 1})
        dados = cadastro(saldo=0) + [3]
        if exe == desafio:
            dados.append(101)
        verificar(f"{nome}: saldo zero", executar(exe, dados + [6]), ["Saldo atual: R$ 0.00"])
        for parcial in [[], [1], [1, 101], [1, 101, "Nome"], [1, 101, "Nome", "00000000000"],
                        [1, 101, "Nome", "00000000000", 1]]:
            resultado = executar(exe, parcial)
            assert "Entrada encerrada" in resultado
            assert "Conta cadastrada com sucesso" not in resultado
        print(f"OK - {nome}: fim de entrada em seis pontos")

    verificar("basico: cadastro preservado", executar(basico, cadastro() + [1, 2, 6]),
              ["Dados preservados", "Numero: 101"], contagens={"Conta cadastrada com sucesso": 1})
    verificar("basico: tipo, bloqueios e reativacao", executar(basico, cadastro() +
              [4, 1, 4, 2, 5, 2, 3, 4, 5, 3, 2, 6]),
              ["A conta ja possui esse tipo", "Tipo da conta alterado", "Tipo: Poupanca",
               "Situacao: Inativa", "Saldo indisponivel", "Ative-a para verificar",
               "Ative-a antes de alterar", "Conta ativada", "Saldo atual: R$ 250.50"])

    dados = []
    for i in range(1, 6):
        dados += cadastro(100+i, f"Cliente {i}", 1, i*10)
    dados += [1, 2, 101, 2, 105, 4, 101, 2, 5, 105, 2, 101, 2, 105,
              3, 105, 4, 105, 5, 105, 3, 105, 2, 103, 6]
    verificar("desafio: cinco contas independentes, limite e reativacao", executar(desafio, dados),
              ["Limite de cinco contas", "Titular: Cliente 1", "Titular: Cliente 5",
               "Tipo: Poupanca", "Situacao: Inativa", "Saldo atual: R$ 50.00",
               "Titular: Cliente 3", "Saldo: R$ 30.00", "Ative-a antes de alterar"],
              contagens={"Conta cadastrada com sucesso": 5, "Tipo: Poupanca": 1,
                         "Situacao: Inativa": 1})
    verificar("desafio: numero duplicado e busca ausente", executar(desafio, cadastro() +
              [1, 101, 102, "Segundo Cliente", "00000000000", 2, 90, 2, 999, 2, 102, 6]),
              ["Numero invalido ou ja cadastrado", "Conta nao encontrada", "Titular: Segundo Cliente"],
              contagens={"Conta cadastrada com sucesso": 2})
    # Confere individualmente que alterar uma conta nao muda as outras quatro.
    for alvo in range(101, 106):
        dados = []
        for numero in range(101, 106):
            dados += cadastro(numero, f"Cliente {numero}", 1, numero)
        dados += [4, alvo, 2, 5, alvo]
        for numero in range(101, 106):
            dados += [2, numero]
        saida = executar(desafio, dados + [6])
        for numero in range(101, 106):
            trecho = saida.split(f"Numero: {numero}\n", 1)[1].split("========================================", 1)[0]
            assert ("Tipo: Poupanca" if numero == alvo else "Tipo: Corrente") in trecho
            assert ("Situacao: Inativa" if numero == alvo else "Situacao: Ativa") in trecho
            if numero != alvo:
                assert f"Saldo: R$ {numero:.2f}" in trecho
        print(f"OK - desafio: isolamento da conta {alvo}")
    print("Todos os testes passaram.")


if __name__ == "__main__":
    main()
