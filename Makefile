kilo: memalloc/src/main.c
	$(CC) memalloc/src/main.c memalloc/src/linked.c -o target/main -Wall -Wextra -pedantic -std=c99