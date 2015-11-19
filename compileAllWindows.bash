g++ -c boardObject.cpp -Wall
g++ -I./include -c Square.cpp -Wall
g++ -I./include Grid.cpp -c -Wall
g++ -I./include -L./lib -lsfml-window -lsfml-graphics -lsfml-system GridTest.cpp -o gridTest.out -Wall Grid.o Square.o
g++ -L./lib2 -I./include ./lib2/libsfml-window.a ./lib2/libsfml-graphics.a ./lib2/libsfml-system.a Test.cpp -o Test.out -Wall Grid.o Square.o
