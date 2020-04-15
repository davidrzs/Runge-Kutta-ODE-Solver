usage: usage.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 usage.cpp


demo: demo/demo.cpp src/rk_implementer.hpp
	g++ -I /usr/include/eigen3 -I /usr/include/python2.7  demo/demo.cpp -lpython2.7
