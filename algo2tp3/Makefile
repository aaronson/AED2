all: main test1

main: main.o workflow.o usorecursos.o planta.o defs.o cola.o
	g++ main.o workflow.o usorecursos.o planta.o defs.o cola.o -o main
	
test1: test1.o workflow.o usorecursos.o planta.o defs.o cola.o
	g++ test1.o workflow.o usorecursos.o planta.o defs.o cola.o -o test1

workflow.o: workflow.h workflow.cpp defs.h secu.h conj.h mconj.h secuIndexable.h
	g++ -g -c  workflow.cpp -o workflow.o

usorecursos.o: usorecursos.cpp usorecursos.h
	g++ -g -c usorecursos.cpp -o usorecursos.o

planta.o: planta.cpp planta.h
	g++ -g -c planta.cpp -o planta.o

defs.o: defs.cpp defs.h
	g++ -g -c defs.cpp -o defs.o
	
cola.o: cola.cpp cola.h
	g++ -g -c cola.cpp -o cola.o

main.o: main.cpp secu.h conj.h mconj.h cola.o workflow.o usorecursos.o planta.o defs.o secuIndexable.h
	g++ -g -c main.cpp -o main.o
	
test1.o: test1.cpp secu.h conj.h mconj.h cola.o workflow.o usorecursos.o planta.o defs.o secuIndexable.h
	g++ -g -c test1.cpp -o test1.o



clean:
	rm -f *.o *.gch main 
