
all: bank

bank: account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o
	g++ account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o -o bank

testAccounts: account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o testAccounts.o
		g++ account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o testAccounts.o -o testAccounts

main.o: main.cc
	g++ -c main.cc

user.o: user.cc
	g++ -c user.cc

dispatchloop.o: dispatchloop.cc
	g++ -c dispatchloop.cc

chequingaccount.o: chequingaccount.cpp
	g++ -c chequingaccount.cpp

savingsaccount.o: savingsaccount.cpp
	g++ -c savingsaccount.cpp

account.o: account.cpp
	g++ -c account.cpp

testAccounts.o: testAccounts.cpp
	g++ -c testAccounts.cpp 

clean:
	rm *.o bank testAccounts
