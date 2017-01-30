main: main.o render.o sdl_boilerplate.o clock.o rules.o patterns.o
	gcc main.o render.o sdl_boilerplate.o clock.o rules.o patterns.o -o main.out -lSDL2 -lSDL2_ttf -std=c99 -g

main.o: main.c
	gcc main.c -c -std=c99

sdl_boilerplate.o: graphics/sdl_boilerplate.c
	gcc graphics/sdl_boilerplate.c -c

render.o: graphics/render.c
	gcc graphics/render.c -c -std=c99

clock.o: graphics/clock.c
	gcc graphics/clock.c -c -std=c99

rules.o: game/rules.c
	gcc game/rules.c -c -std=c99

patterns.o: game/patterns.c
	gcc game/patterns.c -c -std=c99