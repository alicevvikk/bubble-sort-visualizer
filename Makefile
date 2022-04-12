cc = g++
libs = -lsfml-system -lsfml-window -lsfml-graphics

out: main.o
	$(cc) main.o -o out $(libs)
	

main.o: main.cpp
	$(cc) -c main.cpp

clean:
	rm main.o out 

