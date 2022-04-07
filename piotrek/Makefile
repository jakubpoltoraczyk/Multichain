CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: multiWorker.exe
	./multiWorker.exe 

multiWorker.exe: obj/main.o obj/CmdClient.o obj/IpfsClient.o obj/IpfsTests.o 
	g++ -Wall -pedantic -o multiWorker.exe obj/*.o     

obj/main.o: src/main.cpp inc/CmdClient.hh inc/IpfsClient.hh inc/IpfsTests.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/CmdClient.o: src/CmdClient.cpp inc/CmdClient.hh  
	g++ ${CPPFLAGS} -o obj/CmdClient.o src/CmdClient.cpp

obj/IpfsClient.o: src/IpfsClient.cpp inc/IpfsClient.hh  
	g++ ${CPPFLAGS} -o obj/IpfsClient.o src/IpfsClient.cpp

obj/IpfsTests.o: src/IpfsTests.cpp inc/IpfsTests.hh  
	g++ ${CPPFLAGS} -o obj/IpfsTests.o src/IpfsTests.cpp

clean:
	rm -f obj/*.o multiWorker.exe