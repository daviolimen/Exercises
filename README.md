# Exercises

Minhas soluções de programação competitiva, organizadas por fonte.

| Pasta | O que tem |
| --- | --- |
| `codeforces/problemset/` | Problemas do Codeforces, nomeados `<contestId><índice>.cpp` |
| `codeforces/edu/` | Cursos do Codeforces EDU (busca binária, segment tree) |
| `cses/` | CSES Problem Set, por seção |
| `usaco/guide/` | USACO Guide (Bronze, Silver e módulos gerais) |
| `usaco/training/` | USACO Training Gateway, por capítulo e seção |
| `olympiads/obi/` | OBI por ano e fase; `mock/` tem os simulados |
| `olympiads/topcom/` | TOPCOM (UFES) |
| `library/` | Implementações reutilizáveis por tópico: o caderno de código |
| `misc/` | Problemas de outras fontes; `atcoder_dp_contest/` é o Educational DP Contest |
| `tools/` | Template, stress test, gerador e estatísticas do Codeforces |

## Ferramentas

```bash
# começar um problema novo
cp tools/template.cpp codeforces/problemset/2114f.cpp

# stress test: compara sua solução com um brute force em testes aleatórios
tools/stress.sh sol.cpp brute.cpp gen.cpp 1000

# resumo dos últimos contests e da prática, pronto para colar no log de treino
python3 tools/cf_stats.py daviolimen --contests 5 --days 7
```

O `tools/gen.cpp` é um gerador de exemplo: copie para a pasta do problema e
ajuste ao formato de entrada. Mantenha os testes pequenos.

## Convenções

- Pastas em inglês, `snake_case`; arquivos em minúsculas, sem espaços.
- Compilação: `g++ -O2 -std=c++17 -DLOCAL` (o `dbg()` do template só imprime com `-DLOCAL`).
- Binários e saídas não são versionados.
