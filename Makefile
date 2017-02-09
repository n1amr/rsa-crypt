DEBUG = true
CXX = g++
LINKER = $(CXX)
CXXFLAGS = --std=c++11 -Wall -Wextra -pedantic -O2
ifdef DEBUG
	CXXFLAGS := $(CXXFLAGS) -g
endif

generate:
	@./generate-script

singlefile/rsa-crypt.in:
	@echo "# Enter commands here." >> singlefile/rsa-crypt.in
	@echo "# (i.e. P= Q= E= PrintN PrintPhi PrintP PrintQ PrintE PrintD EncryptPublic= EncrtyptPrivate= Quit)" >> singlefile/rsa-crypt.in

singlefile/rsa-crypt: generate
	@test -f singlefile/rsa-crypt || g++ ./singlefile/rsa-crypt.cpp -o singlefile/rsa-crypt ${CXXFLAGS}

run: singlefile/rsa-crypt
	time ./singlefile/rsa-crypt

run-fileinput: singlefile/rsa-crypt singlefile/rsa-crypt.in
	time ./singlefile/rsa-crypt < singlefile/rsa-crypt.in

clean:
	rm ./singlefile/rsa-crypt
	rm ./singlefile/rsa-crypt.cpp
