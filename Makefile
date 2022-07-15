all: dsym

dsym: dsym.c
	$(CC) -std=c11 -L/usr/local/lib -lbin -O2 -o $@ $^ 

clean:
	rm dsym