program=$1
asmpart=$2
as --32 -o $asmpart.o $asmpart.s
gcc -m32 -o matrix.out $program.c $asmpart.o
./matrix.out
