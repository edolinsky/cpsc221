all: generator0 generator1 generator2 generator3 generator4 

generator0: generator0.cc 	
	g++ -Wall generator0.cc -o generator0
	
generator1: generator1.cc 	
	g++ -Wall generator1.cc -o generator1

generator2: generator2.cc 	
	g++ -Wall generator2.cc -o generator2

generator3: generator3.cc 	
	g++ -Wall generator3.cc -o generator3

generator4: generator4.cc 	
	g++ -Wall generator4.cc -o generator4

clean: 
	rm -f generator0
	rm -f generator1
	rm -f generator2
	rm -f generator3
	rm -f generator4
	rm -f generator*.o
	rm -fr generator*.dSYM/* 
	rmdir generator*.dSYM
 
