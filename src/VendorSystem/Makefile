SOURCE_DEPS=* User/* Db

all: vendor

vendor: account.o chequingaccount.o savingsaccount.o creditaccount.o user.o usermethods.o dispatchloop.o db.o purchase.o purchasetable.o accounttable.o usertable.o main.o
	g++ Objects/account.o Objects/chequingaccount.o Objects/savingsaccount.o Objects/creditaccount.o Objects/usermethods.o Objects/dispatchloop.o Objects/user.o Objects/db.o Objects/purchase.o Objects/purchasetable.o Objects/accounttable.o Objects/usertable.o Objects/main.o -lmysqlclient -o vendor

testAccounts: account.o savingsaccount.o chequingaccount.o user.o usermethods.o dispatchloop.o testAccounts.o fundmovementvalidation.o logger.o db.o usertable.o
	g++ Object/account.o Object/savingsaccount.o Object/chequingaccount.o Object/usermethods.o Object/dispatchloop.o Object/user.o Object/testAccounts.o Object/fundmovementvalidation.o Object/logger.o Object/db.o Object/usertable.o -lmysqlclient -o Debug/testAccounts

main.o: main.cpp
	g++ -c main.cpp -o Objects/main.o

user.o: ../User/user.cpp
	g++ -c ../User/user.cpp -o Objects/user.o

dispatchloop.o: dispatchloop.cpp
	g++ -c dispatchloop.cpp -o Objects/dispatchloop.o

creditaccount.o: ../Account/creditaccount.cpp
	g++ -c ../Account/creditaccount.cpp -o Objects/creditaccount.o

chequingaccount.o: ../Account/chequingaccount.cpp
	g++ -c ../Account/chequingaccount.cpp -o Objects/chequingaccount.o

savingsaccount.o: ../Account/savingsaccount.cpp
	g++ -c ../Account/savingsaccount.cpp -o Objects/savingsaccount.o

account.o: ../Account/account.cpp
	g++ -c ../Account/account.cpp -o Objects/account.o

testAccounts.o: testAccounts.cpp
	g++ -c testAccounts.cpp -o Objects/testaccounts.o

fundmovementvalidation.o: Account/fundmovementvalidation.cpp
	g++ -c Account/fundmovementvalidation.cpp -o Objects/fundmovementvalidation.o

logger.o: logger.cpp
	g++ -c logger.cpp -o Objects/logger.o

usertable.o: ../User/usertable.cpp
	g++ -c ../User/usertable.cpp -o Objects/usertable.o

accounttable.o: ../Account/accounttable.cpp
	g++ -c ../Account/accounttable.cpp -o Objects/accounttable.o

db.o: ../Db/db.cpp
	g++ -c ../Db/db.cpp -o Objects/db.o

usermethods.o: usermethods.cpp
	g++ -c usermethods.cpp -o Objects/usermethods.o

managermethods.o: ../User/managermethods.cpp
	g++ -c ../User/managermethods.cpp -o Objects/managermethods.o

purchase.o: ../Purchase/purchase.cpp
	g++ -c ../Purchase/purchase.cpp -o Objects/purchase.o

purchasetable.o: ../Purchase/purchasetable.cpp
	g++ -c ../Purchase/purchasetable.cpp -o Objects/purchasetable.o

clean:
	rm Objects/*.o vendor report.txt
