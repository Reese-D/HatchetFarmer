g++ -c boardObject.cpp -Wall
g++ -c Unit.cpp -Wall
g++ -I./include -c Square.cpp -Wall
g++ -I./include Grid.cpp -c -Wall
g++ -I./include -L./lib2 -lsfml-window-2 -lsfml-graphics-2 -lsfml-system-2 GridTest.cpp -o gridTest.out -Wall Grid.o Square.o
g++ -L./lib2 -I./include -lsfml-window-2 -lsfml-graphics-2 -lsfml-system-2 Test.cpp -o Test.out -Wall Grid.o Square.o  Unit.o BoardObject.o
