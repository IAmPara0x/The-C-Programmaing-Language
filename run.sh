set -e
readonly path=$1
name=$(basename "$path" ".c")
gcc $path -o ${name%%.*}
mv ${name%%.*} execs/ && execs/${name%%.*}


