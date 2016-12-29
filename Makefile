DEBUG = true
CXX = g++
LINKER = $(CXX)
CXXFLAGS = --std=c++11 -Wall -Wextra -pedantic -O2
ifdef DEBUG
	CXXFLAGS := $(CXXFLAGS) -g
endif

generate:
	@./generate-script

rsa-crypt: generate
	@test -f rsa-crypt || g++ ./rsa-crypt.cpp -o rsa-crypt ${CXXFLAGS}

run: rsa-crypt
	time ./rsa-crypt

clean:
	rm ./rsa-crypt*
