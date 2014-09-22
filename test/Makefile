SHELL := /bin/bash

DEPS=../src/*.cpp ../src/*.h ../src/User/*.cpp ../src/User/*.h ../src/Db/*.cpp ../src/Db/*.h db.cc user.cc

user: $(DEPS) libgtest.a
	g++ -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/User/user.cpp user.cc Objects/libgtest.a -o Debug/user


db: $(DEPS) libgtest.a
	g++ -Wall -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/Db/db.cpp ../src/User/*.cpp db.cc Objects/libgtest.a -lmysqlclient -lodbc -g -o Debug/db

gtest-all.o: 
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o Objects/gtest-all.o

libgtest.a: gtest-all.o
	 ar -rv Objects/libgtest.a Objects/gtest-all.o


clean:
	rm Debug/*

superclean: clean
	rm Objects/*
