#para rodar o makefile basta digitar "make teste" no terminal
testar: compilar gerar executar

testarvalgrind: compilar gerar valgrind

compilar: main.c worstFit.c worstFit.h bestFit.c bestFit.h
	gcc -c main.c worstFit.c bestFit.c worstFit.h bestFit.h

gerar: main.o worstFit.o bestFit.o worstFit.h.gch bestFit.h.gch
	gcc -o trab3 main.o worstFit.o bestFit.o

#adicionar o nome da pasta onde as entradas se encontram, apenas
executar: trab3
	./trab3 Entrada/100000.txt 

valgrind:
	valgrind ./trab3 Entrada/5.txt

clean:
	@rm *.o trab3 *.h.gch
