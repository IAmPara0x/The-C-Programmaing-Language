#!/usr/bin/bash

set -e
readonly path=$1
readonly NEWFLAG="-n"
name=$(basename "$path" ".c")

if [ -e "$path" ]; then

  name=$(basename "$path" ".c")
  gcc $path -o ${name%%.*}
  mv ${name%%.*} execs/ && execs/${name%%.*}

elif [ "$NEWFLAG" == "$2" ]
then

  touch "$path"
  cp ./template/template.c "$path"
  name=$(basename "$path" ".c")
  gcc -std=c99 -pedantic -W -Wall $path -o ${name%%.*}
  mv ${name%%.*} execs/ && execs/${name%%.*}

else
  echo "Use -n flag to create the file if it does not exist."

fi



