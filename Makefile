DEBUG = true
CXX = g++
LINKER = $(CXX)
CXXFLAGS = --std=c++11 -Wall -Wextra -pedantic -O2
ifdef DEBUG
	CXXFLAGS := $(CXXFLAGS) -g
endif

rsa-crypt.cpp:
	@./generate-script

singlefile/rsa-crypt.in:
	@echo "# Enter commands here." >> singlefile/rsa-crypt.in
	@echo "# (i.e. P= Q= E= PrintN PrintPhi PrintP PrintQ PrintE PrintD EncryptPublic= EncrtyptPrivate= Quit)" >> singlefile/rsa-crypt.in

singlefile/rsa-crypt: rsa-crypt.cpp
	@test -f singlefile/rsa-crypt || g++ ./singlefile/rsa-crypt.cpp -o singlefile/rsa-crypt ${CXXFLAGS}

compile: rsa-crypt.cpp
	g++ ./singlefile/rsa-crypt.cpp -o singlefile/rsa-crypt ${CXXFLAGS}

run: singlefile/rsa-crypt
	./singlefile/rsa-crypt

timeit: singlefile/rsa-crypt
	/usr/bin/time --verbose ./singlefile/rsa-crypt

run-fileinput: singlefile/rsa-crypt singlefile/rsa-crypt.in
	./singlefile/rsa-crypt < singlefile/rsa-crypt.in

timeit-fileinput: singlefile/rsa-crypt singlefile/rsa-crypt.in
	/usr/bin/time --verbose ./singlefile/rsa-crypt < singlefile/rsa-crypt.in

clean:
	if [ -f ./singlefile/rsa-crypt ]; then rm ./singlefile/rsa-crypt; fi
	if [ -f ./singlefile/rsa-crypt.cpp ]; then rm ./singlefile/rsa-crypt.cpp; fi

update: clean singlefile/rsa-crypt
