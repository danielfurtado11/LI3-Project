default: guiao-1

guiao-1: obj/main.o obj/users.o obj/commits.o obj/repos.o
	gcc -g -o guiao-1 obj/main.o obj/users.o obj/commits.o obj/repos.o

obj/main.o: src/main.c libs/commits.h libs/users.h libs/repos.h
	gcc -g -o obj/main.o src/main.c -c -W -Wall 

obj/users.o: src/users.c libs/users.h
	gcc -g -o obj/users.o src/users.c -c -W -Wall 

obj/commits.o: src/commits.c libs/commits.h
	gcc -g -o obj/commits.o src/commits.c -c -W -Wall

obj/repos.o: src/repos.c libs/repos.h
	gcc -g -o obj/repos.o src/repos.c -c -W -Wall

clean:
	-rm -f obj/users.o
	-rm -f obj/commits.o
	-rm -f obj/repos.o
	-rm -f obj/main.o
	-rm -f guiao-1

