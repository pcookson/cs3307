




user: libgtest.a
	g++ -isystem ${GTEST_DIR}/include ${GTEST_DIR}/src/gtest_main.cc ../src/user.cc user_unittest.cc libgtest.a -o user



gtest-all.o: 
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

libgtest.a: gtest-all.o
	 ar -rv libgtest.a gtest-all.o


clean:
	rm *.o *.exe *.a
