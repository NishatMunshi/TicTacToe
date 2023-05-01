all: compile link run

compile:
	g++ -c "E:\Code\TicTacToe\Src\main.cpp" -I"E:\programming_tools\SFML-2.5.1\include" -I"E:\Code\TicTacToe" -DSFML_STATIC

link:
	g++ main.o -o main -L"E:\programming_tools\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

run:
	.\main

clean:
	rm -f main *.o