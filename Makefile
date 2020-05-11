usage: usage.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 usage.cpp


demo: demo/demo.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 -I /usr/include/python3.8  demo/demo.cpp -lpython3.8
