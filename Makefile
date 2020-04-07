main: src/main.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 src/main.cpp


demo: src/main.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 -I /usr/include/python2.7  demo/demo.cpp -lpython2.7
