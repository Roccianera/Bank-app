CC=g++
CFLAGS=-std=c++11
DEPS=  Bank.h User.h Transaction.h Date\Date.h
OBJ = driver.o Bank.o User.o  Date\Date.o

%.o:%.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)