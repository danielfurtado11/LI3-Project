default: guiao-3 testes

testes: obj/testes.o obj/queries.o obj/users.o obj/maing1.o obj/usersg1.o obj/commitsg1.o obj/reposg1.o obj/print.o obj/funcoes.o obj/commits.o obj/repos.o obj/auxiliar.o
	gcc -g -o testes obj/testes.o obj/queries.o obj/users.o obj/maing1.o obj/usersg1.o obj/commitsg1.o obj/reposg1.o obj/print.o obj/funcoes.o obj/commits.o obj/repos.o obj/auxiliar.o

guiao-3: obj/main.o obj/queries.o obj/users.o obj/maing1.o obj/usersg1.o obj/commitsg1.o obj/reposg1.o obj/print.o obj/funcoes.o obj/commits.o obj/repos.o obj/auxiliar.o
	gcc -g -o guiao-3 obj/main.o obj/queries.o obj/users.o obj/maing1.o obj/usersg1.o obj/commitsg1.o obj/reposg1.o obj/print.o obj/funcoes.o obj/commits.o obj/repos.o obj/auxiliar.o

obj/main.o: src/main.c libs/queries.h libs/users.h libs/commits.h
	gcc -g -o obj/main.o src/main.c -c -W -Wall 

obj/queries.o: src/queries.c libs/queries.h libs/users.h libs/commits.h
	gcc -g -o obj/queries.o src/queries.c -c -W -Wall

obj/users.o: src/users.c libs/users.h
	gcc -g -o obj/users.o src/users.c -c -W -Wall

obj/commits.o: src/commits.c libs/commits.h
	gcc -g -o obj/commits.o src/commits.c -c -W -Wall

obj/repos.o: src/repos.c libs/repos.h
	gcc -g -o obj/repos.o src/repos.c -c -W -Wall

obj/maing1.o: src/maing1.c libs/maing1.h libs/usersg1.h libs/commitsg1.h libs/reposg1.h
	gcc -g -o obj/maing1.o src/maing1.c -c -W -Wall

obj/usersg1.o: src/usersg1.c libs/usersg1.h
	gcc -g -o obj/usersg1.o src/usersg1.c -c -W -Wall

obj/commitsg1.o: src/commitsg1.c libs/commitsg1.h 
	gcc -g -o obj/commitsg1.o src/commitsg1.c -c -W -Wall

obj/reposg1.o: src/reposg1.c libs/reposg1.h 
	gcc -g -o obj/reposg1.o src/reposg1.c -c -W -Wall

obj/print.o: src/print.c libs/print.h
	gcc -g -o obj/print.o src/print.c -c -W -Wall

obj/funcoes.o: src/funcoes.c libs/funcoes.h
	gcc -g -o obj/funcoes.o src/funcoes.c -c -W -Wall

obj/auxiliar.o: src/auxiliar.c libs/auxiliar.h
	gcc -g -o obj/auxiliar.o src/auxiliar.c -c -W -Wall

obj/testes.o: src/testes.c 
	gcc -g -o obj/testes.o src/testes.c -c -W -Wall

clean:
	-rm -f obj/main.o
	-rm -f obj/queries.o
	-rm -f obj/users.o
	-rm -f obj/commits.o
	-rm -f obj/repos.o
	-rm -f guiao-3
	-rm -f testes
	-rm -f obj/maing1.o
	-rm -f obj/usersg1.o
	-rm -f obj/commitsg1.o
	-rm -f saida/q1.txt
	-rm -f saida/users-ok.csv
	-rm -f saida/commits-ok.csv
	-rm -f saida/repos-ok.csv
	-rm -f obj/funcoes.o
	-rm -f obj/print.o
	-rm -f obj/auxiliar.o
	-rm -f saida/bots.txt
	-rm -f saida/ncommits.txt
	-rm -f saida/validq7.csv
	-rm -f saida/reposid.csv
	-rm -f saida/q1output.txt
	-rm -f saida/q2output.txt
	-rm -f saida/q3output.txt
	-rm -f saida/q4output.txt
	-rm -f saida/erros.txt
