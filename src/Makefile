SOURCE_DEPS=* User/* Db

all: bank

bank:  account.o savingsaccount.o chequingaccount.o user.o usermethods.o managermethods.o dispatchloop.o fundmovementvalidation.o logger.o db.o usertable.o main.o
	g++ account.o savingsaccount.o chequingaccount.o usermethods.o managermethods.o dispatchloop.o user.o fundmovementvalidation.o logger.o db.o usertable.o main.o -lmysqlclient  -o bank

testAccounts: account.o savingsaccount.o chequingaccount.o user.o usermethods.o dispatchloop.o testAccounts.o fundmovementvalidation.o logger.o db.o usertable.o
	g++ account.o savingsaccount.o chequingaccount.o usermethods.o dispatchloop.o user.o testAccounts.o fundmovementvalidation.o logger.o db.o usertable.o -lmysqlclient -o testAccounts

main.o: main.cpp
	g++ -c main.cpp

user.o: User/user.cpp
	g++ -c User/user.cpp

dispatchloop.o: dispatchloop.cpp
	g++ -c dispatchloop.cpp

chequingaccount.o: Account/chequingaccount.cpp
	g++ -c Account/chequingaccount.cpp

savingsaccount.o: Account/savingsaccount.cpp
	g++ -c Account/savingsaccount.cpp

account.o: Account/account.cpp
	g++ -c Account/account.cpp

testAccounts.o: testAccounts.cpp
	g++ -c testAccounts.cpp 

fundmovementvalidation.o: Account/fundmovementvalidation.cpp
	g++ -c Account/fundmovementvalidation.cpp

logger.o: logger.cpp
	g++ -c logger.cpp

usertable.o: User/usertable.cpp
	g++ -c User/usertable.cpp

db.o: Db/db.cpp
	g++ -c Db/db.cpp

usermethods.o:User/usermethods.cpp
	g++ -c User/usermethods.cpp

managermethods.o: User/managermethods.cpp
	g++ -c User/managermethods.cpp

clean:
	rm *.o bank testAccounts report.txt
