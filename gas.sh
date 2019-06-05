program = $1

as --32 -o $program.o $program.s
ld -o $program $program.o
echo "complete!!"