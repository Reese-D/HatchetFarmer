g++ -c Square.cpp -Wall
g++ Grid.cpp -c -Wall
g++ GridTest.cpp -o gridTest.out -Wall Grid.o Square.o
g++ -L./lib2 -I./include -lsfml-window -lsfml-graphics -lsfml-system Test.cpp -o Test.out -Wall
