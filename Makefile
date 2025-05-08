CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-window -lsfml-system
PROGRAM_TEST = test
PROGRAM_MAIN = EDistance

.PHONY: all clean lint


all: $(PROGRAM_MAIN) $(PROGRAM_TEST)


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM_MAIN): main.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(PROGRAM_TEST): test.o EDistance.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -f *.o $(PROGRAM_MAIN) $(PROGRAM_TEST)

lint:
	cpplint *.cpp *.hpp
