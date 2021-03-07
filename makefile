main:
	g++ -std=c++17 main.cpp main.hpp represent.cpp basic-func.cpp modules/*.cpp modules/*.hpp modules/physicalModels/* -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system