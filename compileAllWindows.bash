g++ -c Square.cpp -Wall
g++ Grid.cpp -c -Wall
g++ GridTest.cpp -o gridTest.out -Wall Grid.o Square.o
g++ -L./lib2 -I./include -llibsfml-window -llibsfml-graphics -llibsfml-system Test.cpp -o Test.out -Wall
