algos: algos/src/main.c
	$(CC) algos/src/main.c algos/src/linked.c -o target/algos/main -Wall -Wextra -pedantic -std=c99

pointers: pointers/src/main.c
	$(CC) pointers/src/main.c -o target/pointers/main -Wall -Wextra -pedantic -std=c99

allocator: allocator/src/main.c
	$(CC) allocator/src/main.c -o target/allocator/main -Wall -Wextra -pedantic -std=c99

asm: asm/src/hello.asm
	$ nasm -f elf32 asm/src/hello.asm -o target/asm/hello.o

lasm: target/asm/hello.o
	$ ld -m elf_i386 target/asm/hello.o -o target/asm/hello