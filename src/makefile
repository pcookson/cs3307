CC=g++
CFLAGS=-c -Wall -g -ggdb
LDFLAGS=-pthread -lmysqlclient
ACCOUNT_SOURCES=Account/account.cpp Account/accounttable.cpp Account/chequingaccount.cpp Account/creditaccount.cpp Account/savingsaccount.cpp Account/fundmovementvalidation.cpp
DB_SOURCES=Db/db.cpp
PURCHASE_SOURCES=Purchase/purchase.cpp Purchase/purchasetable.cpp
PAYMENT_SOURCES=Payment/payment.cpp Payment/paymenttable.cpp
USER_SOURCES=User/maintenancemethods.cpp User/managermethods.cpp User/user.cpp User/usermethods.cpp User/usertable.cpp
ROOT_SOURCES=dispatchloop.cpp logger.cpp main.cpp

SOURCES=$(ACCOUNT_SOURCES) $(DB_SOURCES) $(PURCHASE_SOURCES) $(PAYMENT_SOURCES) $(USER_SOURCES) $(ROOT_SOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bank

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf Account/*.o
	rm -rf User/*.o
	rm -rf Purchase/*.o
	rm -rf Payment/*.o
	rm -rf Db/*.o
	rm bank
