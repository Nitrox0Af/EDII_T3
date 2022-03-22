#para rodar o makefile basta digitar "make teste" no terminal
testar: compilar gerar executar

compilar: main.c worstFit.c worstFit.h bestFit.c bestFit.h
	gcc -c *.c *.h

gerar: main.o worstFit.o bestFit.o worstFit.h.gch bestFit.h.gch
	gcc -o trab3 *.c

#adicionar o nome da pasta onde as entradas se encontram, apenas
executar:
	./trab3 Entrada/ 

clean:	
	@rm *.o trab3 *.txt *.h.gch