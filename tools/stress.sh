#!/usr/bin/env bash
# Stress test: compara a sua solução com um brute force em testes aleatórios.
#
# Uso:   tools/stress.sh sol.cpp brute.cpp gen.cpp [testes=1000]
# Ex.:   tools/stress.sh codeforces/problemset/2114f.cpp brute.cpp gen.cpp 500
#
# Para no primeiro teste em que as saídas diferem e mostra a entrada e as
# duas saídas. O gerador recebe o número do teste como seed (veja tools/gen.cpp).
set -euo pipefail

if [ $# -lt 3 ]; then
    echo "Uso: $0 sol.cpp brute.cpp gen.cpp [testes=1000]" >&2
    exit 2
fi

sol=$1; brute=$2; gen=$3; tests=${4:-1000}
dir=$(mktemp -d)
trap 'rm -rf "$dir"' EXIT

flags=(-O2 -std=c++17 -DLOCAL)
g++ "${flags[@]}" -o "$dir/sol" "$sol"
g++ "${flags[@]}" -o "$dir/brute" "$brute"
g++ "${flags[@]}" -o "$dir/gen" "$gen"

for ((i = 1; i <= tests; i++)); do
    "$dir/gen" "$i" > "$dir/in"
    "$dir/sol" < "$dir/in" > "$dir/out1" 2>/dev/null || { echo "Sua solução falhou (RE) no teste $i"; cat "$dir/in"; exit 1; }
    "$dir/brute" < "$dir/in" > "$dir/out2" 2>/dev/null || { echo "O brute falhou no teste $i"; cat "$dir/in"; exit 1; }
    if ! diff -wq "$dir/out1" "$dir/out2" > /dev/null; then
        echo "Diferença no teste $i"
        echo "--- entrada";  cat "$dir/in"
        echo "--- sua saída"; cat "$dir/out1"
        echo "--- brute";     cat "$dir/out2"
        exit 1
    fi
done
echo "OK em $tests testes"
