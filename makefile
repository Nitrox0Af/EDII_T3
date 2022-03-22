#para rodar o makefile basta digitar "make all" no terminal
all: compilar gerar executar clean

compilar:
	gcc -c *.c

gerar:
	gcc -o trab3 *.c

#adicionar caminho do arquivo de entrada
executar:
	./trab3 in/5.txt 

clean:	
	@rm *.o trab3 