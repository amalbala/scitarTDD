
TEST = ScitarTests
MAIN = Scitar
CC=g++
CFLAGS=
INCLUDES=
LFLAGS=
SRCS =  main.cpp scitarTDD.cpp ScitarTests.cpp

CFLAGS += -I/Users/antoniomartinez/Software/gtest-1.6.0/include
LFLAGS += -L. -lgtest_main

COMMONOBJS = scitarTDD.o

MAINOBJ = main.o
TESTOBJ = ScitarTests.o

all: $(MAIN) $(TEST) executeTest

$(MAIN):  $(MAINOBJ) $(COMMONOBJS)
	$(CC) $(MAINOBJ) $(COMMONOBJS) -o $(MAIN) $(LFLAGS)

$(TEST):  $(TESTOBJ) $(COMMONOBJS)
	$(CC) $(TESTOBJ) $(COMMONOBJS) -o $(TEST) $(LFLAGS)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	rm -f *.o *~ $(MAIN)

executeTest:
	./ScitarTests