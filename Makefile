
BIN=./bin/
SRC=./src/

CFLAGS = -Wall -O -std=c++17 -stdlib=libc++
CC = g++

all: $(BIN)makeix $(BIN)getseq $(BIN)getseqno $(BIN)getids

$(BIN)makeix: $(SRC)make_index.o $(SRC)fastaf.o
	$(CC) $(CFLAGS) -o $(BIN)makeix $(SRC)make_index.o $(SRC)fastaf.o
$(SRC)make_index.o: $(SRC)make_index.cpp
	$(CC) $(CFLAGS) -c $(SRC)make_index.cpp -o $(SRC)make_index.o
$(BIN)getseq: $(SRC)get_seq.o $(SRC)fastaf.o
	$(CC) $(CFLAGS) -o $(BIN)getseq $(SRC)get_seq.o $(SRC)fastaf.o
$(SRC)get_seq.o: $(SRC)get_seq.cpp
	$(CC) $(CFLAGS) -c $(SRC)get_seq.cpp -o $(SRC)get_seq.o
$(BIN)getseqno: $(SRC)get_seq_number.o $(SRC)fastaf.o
	$(CC) $(CFLAGS) -o $(BIN)getseqno $(SRC)get_seq_number.o $(SRC)fastaf.o
$(SRC)get_seq_number.o: $(SRC)get_seq_number.cpp
	$(CC) $(CFLAGS) -c $(SRC)get_seq_number.cpp -o $(SRC)get_seq_number.o

$(BIN)getids: $(SRC)get_seq_ids.o $(SRC)fastaf.o
	$(CC) $(CFLAGS) -o $(BIN)getids $(SRC)get_seq_ids.o $(SRC)fastaf.o
$(SRC)get_seq_ids.o: $(SRC)get_seq_ids.cpp
	$(CC) $(CFLAGS) -c $(SRC)get_seq_ids.cpp -o $(SRC)get_seq_ids.o
$(SRC)fastaf.o: $(SRC)fastaf.cpp
	$(CC) $(CFLAGS) -c $(SRC)fastaf.cpp -o $(SRC)fastaf.o
clean:
	rm -f core $(SRC)*.o
	rm -f $(BIN)getids $(BIN)getseq $(BIN)getseqno $(BIN)makeix
