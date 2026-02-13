addons := $$(pkg-config allegro-5 allegro_primitives-5 --libs --cflags)

main: main.c
	gcc -o main main.c $(addons)

clean:
	rm -f main
