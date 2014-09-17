
user: libgtest.a
	g++ -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/user.cc user_unittest.cc libgtest.a -o user


db: libgtest.a
	g++ -pthread -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/db.cpp db_unittest.cc libgtest.a -lodbc -g -o db

gtest-all.o: 
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

libgtest.a: gtest-all.o
	 ar -rv libgtest.a gtest-all.o


clean:
	rm db 

superclean: clean
	rm *.a *.o
