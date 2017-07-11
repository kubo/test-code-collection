OCI_INC_DIR = $(ORACLE_HOME)/rdbms/public
OCI_LIB_DIR = $(ORACLE_HOME)/lib

CFLAGS = -Wall -I$(OCI_INC_DIR)
LIBS = -L$(OCI_LIB_DIR) -Wl,-rpath,$(OCI_LIB_DIR) -lclntsh

PROGS = connect-by-Logon \
	connect-by-Logon2 \
	connect-by-ServerAttach-and-SessionBegin \
	connect-by-SessionGet \

all: $(PROGS)

connect-by-Logon: connect-main.o util.o connect-by-Logon.o
	$(CC) -o $@ $^ $(LIBS)

connect-by-Logon2: connect-main.o util.o connect-by-Logon2.o
	$(CC) -o $@ $^ $(LIBS)

connect-by-ServerAttach-and-SessionBegin: connect-main.o util.o connect-by-ServerAttach-and-SessionBegin.o
	$(CC) -o $@ $^ $(LIBS)

connect-by-SessionGet: connect-main.o util.o connect-by-SessionGet.o
	$(CC) -o $@ $^ $(LIBS)

connect-by-Logon.o: connect-by-Logon.c connect.h util.h
connect-by-Logon2.o: connect-by-Logon2.c connect.h util.h
connect-by-ServerAttach-and-SessionBegin.o: connect-by-ServerAttach-and-SessionBegin.c connect.h util.h
connect-by-SessionGet.o: connect-by-SessionGet.c connect.h util.h
connect-main.o: connect-main.c connect.h util.h
util.o: util.c util.h

clean:
	$(RM) $(PROGS) *.o
