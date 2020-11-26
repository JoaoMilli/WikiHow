compile: main.c Editor.c ListaEditor.c Pagina.c ListaPag.c Contribuicao.c ListaCont.c Link.c ListaLink.c
	gcc -o WikiHow *.c -I.

exec: WikiHow
	./WikiHow entrada.txt
