all: server client

server: bin/aurrasd

client: bin/aurras

obj/aurrasd.o: src/aurrasd.c
	gcc -Wall -g -c src/aurrasd.c -o obj/aurrasd.o

bin/aurrasd: obj/aurrasd.o
	gcc -g obj/aurrasd.o -o bin/aurrasd

obj/aurras.o: src/aurras.c
	gcc -Wall -g -c src/aurras.c -o obj/aurras.o

bin/aurras: obj/aurras.o
	gcc -g obj/aurras.o -o bin/aurras


clean:
	rm obj/* tmp/* bin/{aurras,aurrasd}
    
client:
	bin/aurras status	
	bin/aurras transform samples/Ievan.m4a output.m4a alto eco lento

server:
	bin/aurrasd etc/aurrasd.conf bin/aurrasd-filters	