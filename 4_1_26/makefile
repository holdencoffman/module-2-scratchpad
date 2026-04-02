all: main
main: main.cpp pointers array movie clock
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp pointers array movie clock -o main
pointers: pointers.h pointers.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g pointers.cpp -o pointers
array: arrayListType.h arrayListType.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g arrayListType.cpp -o array
movie: movieTimes.h movieTimes.cpp clock.h
	g++ -pedantic-errors -fdiagnostics-color=always -c -g movieTimes.cpp -o movie
clock: clock.h clock.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g clock.cpp -o clock
clean:
	rm main