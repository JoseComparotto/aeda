# Definir o compilador
CC = gcc

# Definir flags de compilação
CFLAGS = -Wall -g
LDFLAGS = -lm

# Lista de arquivos de código-fonte
SRCS = main.c util.c ArvoreBinaria.c

# Gerar a lista de arquivos-objetos
OBJS = $(SRCS:.c=.o)

# Nome do executável
EXEC = main.exe

# Regra principal: compilar tudo
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS)

# Regra para compilar os arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para rodar o programa (opcional)
run: $(EXEC)
	./$(EXEC)
