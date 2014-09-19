SOURCE_DEPS=* User/* Db

all: bank

bank: db.o account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o
	g++ account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o -o bank

testAccounts: account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o testAccounts.o fundmovementvalidation.o logger.o
	g++ account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o testAccounts.o fundmovementvalidation.o logger.o -o testAccounts

main.o: main.cpp
	g++ -c main.cpp

user.o: User/user.cpp
	g++ -c User/user.cpp

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

fundmovementvalidation.o: fundmovementvalidation.cpp
	g++ -c fundmovementvalidation.cpp

logger.o: logger.cpp
	g++ -c logger.cpp

db.o: Db/db.cpp
	g++ -c Db/db.cpp

clean:
	rm *.o bank testAccounts report.txt
