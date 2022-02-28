default: guiao-2


guiao-2: obj/main.o obj/query.o obj/users.o obj/commits.o obj/repos.o obj/auxiliar.o obj/struct_q.o
	gcc -g -o guiao-2 obj/main.o obj/query.o obj/users.o obj/commits.o obj/repos.o obj/auxiliar.o obj/struct_q.o

obj/main.o: src/main.c libs/query.h libs/struct_q.h
	gcc -g -o obj/main.o src/main.c -c -W -Wall 

obj/query.o: src/query.c libs/query.h libs/auxiliar.h libs/users.h libs/commits.h libs/repos.h
	gcc -g -o obj/query.o src/query.c -c -W -Wall

obj/users.o: src/users.c libs/users.h
	gcc -g -o obj/users.o src/users.c -c -W -Wall

obj/commits.o: src/commits.c libs/commits.h
	gcc -g -o obj/commits.o src/commits.c -c -W -Wall

obj/repos.o: src/repos.c libs/repos.h
	gcc -g -o obj/repos.o src/repos.c -c -W -Wall

obj/auxiliar.o: src/auxiliar.c libs/auxiliar.h
	gcc -g -o obj/auxiliar.o src/auxiliar.c -c -W -Wall

obj/struct_q.o: src/struct_q.c libs/struct_q.h
	gcc -g -o obj/struct_q.o src/struct_q.c -c -W -Wall
clean:
	-rm -f obj/main.o
	-rm -f obj/query.o
	-rm -f obj/users.o
	-rm -f obj/commits.o
	-rm -f obj/repos.o
	-rm -f obj/auxiliar.o
	-rm -f obj/struct_q.o
	-rm -f guiao-2
