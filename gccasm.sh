program=$1
asmpart=$2
nasm -f elf -o $asmpart.o $asmpart.asm
gcc -m32 -o matrix.out $program.c $asmpart.o
./matrix.out
