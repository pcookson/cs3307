
all: bank

bank: account.o savingsaccount.o dispatchloop.o user.o main.o
	g++ dispatchloop.o user.o main.o -o bank

main.o: main.cc
	g++ -c main.cc

user.o: user.cc
	g++ -c user.cc

dispatchloop.o: dispatchloop.cc
	g++ -c dispatchloop.cc

savingsaccount.o: savingsaccount.cpp
	g++ -c savingsaccount.cpp

account.o: account.cpp
	g++ -c account.cpp

clean:
	rm *.o bank
