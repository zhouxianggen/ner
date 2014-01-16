
VPATH = ../com ../dat ../sre
CXXFLAGS = -I../com -I../dat -I../sre

run_test : test.o number.o utils.o dat.o sre.o
	g++ -pg -o $@ $^
	rm *.o

