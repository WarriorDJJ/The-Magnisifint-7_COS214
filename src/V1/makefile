main: *.o
	g++ -g -o Main *.o -std=c++98

*.o: *.cpp
	g++ -c -g *.cpp

run: main
	./main

clean:
	rm -f *.o main

cleantar:
	rm *.tar

cleanall:
	@if ls -f main;\
	then\
		rm *.o main;\
	fi
	@if ls -f *.tar;\
	then\
		rm *.tar;\
	fi

runs:
	@if ls -f ./main;\
	then\
		make run;\
	else\
		make runc;\
	fi

runc:
	make;
	@if ls -f ./main;\
	then\
		make run;\
    else\
        echo "make: Failed, Canceled Run";\
	fi

tar:
	tar -cvz *.cpp *.h makefile -f COS214_Project_V1_TheMagnisifint7.tar

help:
	@echo "C++ Universal makefile 2021-11-22"
	@echo "By Damian Jordaan"
	@echo "Terminal Commands:"
	@echo "use 'make' to build"
	@echo "use 'make run' to run program"
	@echo "use 'make clean' to clean build outputs"
	@echo "use 'make tar' to create a .tar file with the cpp program, the makefile and text files, if they exist, to upload to the cs website"
	@echo "use 'make cleantar' to remove the .tar file"
	@echo "use 'make cleanall' to clean all outputs: .tar file .o file and build file"
	@echo "use 'make runs' check files and build files and then run program"
	@echo "use 'make runc' rebuild files and then run program"