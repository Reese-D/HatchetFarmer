g++ -c boardObject.cpp -Wall
g++ -I./include -c Square.cpp -Wall
g++ -I./include Grid.cpp -c -Wall
g++ -I./include -L./lib -lsfml-window -lsfml-graphics -lsfml-system GridTest.cpp -o gridTest.out -Wall Grid.o Square.o
g++ -L./lib -I./include -lsfml-window -lsfml-graphics -lsfml-system Test.cpp -o Test.out -Wall Grid.o Square.o
