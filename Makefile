EXE=fois_2 quotient quotient_reste

.PHONY: help all clean 

help:
	@echo "\"make <binary>\" where <binary> is among:"
	@echo "   $(EXE)"
	@echo "or \"make all\" to compile all"

all: $(EXE)

fois_2: fois_2.c read_int.o write_int.o Makefile
	gcc -Wall $< read_int.o write_int.o -o $@

quotient: quotient.c read_int.o write_int.o Makefile
	gcc -Wall $< read_int.o write_int.o -o $@

quotient_reste: quotient_reste.c read_int.o write_int.o Makefile
	gcc -Wall $< read_int.o write_int.o -o $@

%.o: %.c %.h Makefile
	gcc -Wall -c $<

clean:
	$(RM) *~ *.o $(EXE)
