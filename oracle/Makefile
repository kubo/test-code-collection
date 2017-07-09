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

clean:
	$(RM) $(PROGS) *.o
