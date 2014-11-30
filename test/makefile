CC=g++
CFLAGS=-c -Wall -g -ggdb -isystem ${GTEST_DIR}/include 
LDFLAGS=-pthread -lmysqlclient libgtest.a
ACCOUNT_SOURCES=../src/Account/account.cpp ../src/Account/accounttable.cpp ../src/Account/chequingaccount.cpp ../src/Account/creditaccount.cpp ../src/Account/savingsaccount.cpp ../src/Account/fundmovementvalidation.cpp
DB_SOURCES=../src/Db/db.cpp
PURCHASE_SOURCES=../src/Purchase/purchase.cpp ../src/Purchase/purchasetable.cpp
PAYMENT_SOURCES=../src/Payment/payment.cpp ../src/Payment/paymenttable.cpp
USER_SOURCES=../src/User/maintenancemethods.cpp ../src/User/managermethods.cpp ../src/User/user.cpp ../src/User/usermethods.cpp ../src/User/usertable.cpp
ROOT_SOURCES= ../src/dispatchloop.cpp ../src/logger.cpp ${GTEST_DIR}/src/gtest_main.cc

SOURCES=$(ACCOUNT_SOURCES) $(DB_SOURCES) $(PURCHASE_SOURCES) $(PAYMENT_SOURCES)  $(USER_SOURCES) $(ROOT_SOURCES)

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) account

account: $(OBJECTS) libgtest.a
	$(CC) -g -ggdb -I${GTEST_DIR}/include $(OBJECTS) $(LDFLAGS) account.cc -o $@

gtest-all.o: 
	g++ -g -ggdb -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o gtest-all.o

libgtest.a: gtest-all.o
	 ar -rv libgtest.a gtest-all.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf ../src/*.o
	rm -rf ../src/Account/*.o
	rm -rf ../src/User/*.o
	rm -rf ../src/Purchase/*.o
	rm -rf ../src/Db/*.o
	rm account
#
#
#SHELL := /bin/bash
#
#DEPS=../src/*.cpp ../src/*.h ../src/User/*.cpp ../src/User/*.h ../src/Db/*.cpp ../src/Db/*.h ../src/Account/*.cpp ../src/Account/*.h db.cc 
#
#user: $(DEPS) libgtest.a
#	g++ -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/User/user.cpp Objects/libgtest.a -o Debug/user
#
#account: $(DEPS) libgtest.a
#	g++ -Wall -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/Purchase/*.cpp ../src/Account/*.cpp ../src/Db/db.cpp ../src/User/*.cpp account.cc Objects/libgtest.a ../src/logger.cpp -lmysqlclient -g -o Debug/account
#
#accountnowarn: $(DEPS) libgtest.a
#	g++ -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/Account/*.cpp ../src/Db/db.cpp ../src/User/*.cpp db.cc Objects/libgtest.a -lmysqlclient -g -o Debug/db
#
#db: $(DEPS) libgtest.a
#	g++ -Wall -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/Db/db.cpp ../src/User/*.cpp db.cc Objects/libgtest.a -lmysqlclient -lodbc -g -o Debug/db
#
#gtest-all.o: 
#	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o Objects/gtest-all.o
#
#libgtest.a: gtest-all.o
#	 ar -rv Objects/libgtest.a Objects/gtest-all.o
#
#
#
#
#clean:
#	rm Debug/*
#
#superclean: clean
#	rm Objects/*
