all: main
main: main.cpp person employee drink product donut bagel
	g++ -pedantic-errors -fdiagnostics-color=always -g main.cpp person employee drink product donut bagel -o main
person: person.h person.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g person.cpp -o person
employee: employee.h employee.cpp person.h
	g++ -pedantic-errors -fdiagnostics-color=always -c -g employee.cpp -o employee
drink: drink.h drink.cpp product.h
	g++ -pedantic-errors -fdiagnostics-color=always -c -g drink.cpp -o drink
product: product.h product.cpp
	g++ -pedantic-errors -fdiagnostics-color=always -c -g product.cpp -o product
donut: donut.h donut.cpp product.h
	g++ -pedantic-errors -fdiagnostics-color=always -c -g donut.cpp -o donut
bagel: bagel.h bagel.cpp product.h
	g++ -pedantic-errors -fdiagnostics-color=always -c -g bagel.cpp -o bagel