CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

CC = gcc
CCFLAGS = -Wall -Wextra -pedantic -std=c99

bsort: bsort/main.c
	$(CC) $(CCFLAGS) bsort/main.c -o target/bsort/main
	./target/bsort/main

algos: algos/src/main.c
	$(CC) $(CCFLAGS) algos/src/main.c algos/src/linked.c -o target/algos/main 
	./target/algos/main

pointers: pointers/src/main.c
	$(CC) $(CCFLAGS) pointers/src/main.c -o target/pointers/main
	./target/pointers/main

allocator: allocator/src/main.c
	$(CC) $(CCFLAGS) allocator/src/main.c -o target/allocator/main
	./target/allocator/main

asm: asm/src/hello.asm
	$ nasm -f elf32 asm/src/hello.asm -o target/asm/hello.o
	ld -m elf_i386 target/asm/hello.o -o target/asm/hello
	./target/asm/hello

cpp: cpp/src/main.cpp
	${CXX} $(CXXFLAGS) cpp/src/main.cpp -o target/cpp/main
	./target/cpp/main

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean

# Default rule to build all targets
all: algos pointers allocator asm lasm cpp

# Clean rule to remove generated files
clean:
	rm -f target/algos/main target/pointers/main target/allocator/main target/asm/hello.o target/asm/hello target/cpp/main