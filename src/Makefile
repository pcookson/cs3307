SOURCE_DEPS=* User/* Db

all: bank

bank: db.o account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o
	g++ account.o savingsaccount.o chequingaccount.o dispatchloop.o user.o main.o -o bank

testAccounts: account.o savingsaccount.o chequingaccount.o user.o usermethods.o dispatchloop.o testAccounts.o fundmovementvalidation.o logger.o db.o usertable.o
	g++ account.o savingsaccount.o chequingaccount.o usermethods.o dispatchloop.o user.o testAccounts.o fundmovementvalidation.o logger.o db.o usertable.o -lmysqlclient -o testAccounts

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

usertable.o: User/usertable.cpp
	g++ -c User/usertable.cpp

db.o: Db/db.cpp
	g++ -c Db/db.cpp

usermethods.o: usermethods.cpp
	g++ -c usermethods.cpp

clean:
	rm *.o bank testAccounts report.txt
