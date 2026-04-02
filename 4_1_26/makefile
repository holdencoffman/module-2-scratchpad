all: main
main: main.cpp pointers array
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp pointers -o main
pointers: pointers.h pointers.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g pointers.cpp -o pointers
array: arrayListType.h arrayListType.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g arrayListType.cpp -o array
clean:
	rm main