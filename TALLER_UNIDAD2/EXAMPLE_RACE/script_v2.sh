#!/bin/bash

if [ -z "$1" ]; then
  echo "Uso: $0 <ruta_al_ejecutable> [args...]" >&2
  exit 1
fi

exe="$1"
shift  # elimina $1 para que $@ contenga solo los posibles argumentos del ejecutable

rm -f sal.txt

for i in {1..10000}; do
  "$exe" "$@" >> sal.txt
done

nano sal.txt
