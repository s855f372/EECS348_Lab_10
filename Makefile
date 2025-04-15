calculator.exe: main.cpp calculator.cpp calculator.hpp
	g++ -Wall main.cpp calculator.cpp calculator.hpp -o calculator.exe

clean:
	rm -f calculator.exe

run:
	./calculator.exe