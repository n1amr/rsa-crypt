# rsa-crypt

### Running Guide

You can run the code in two ways:

##### Method 1: Running the merged code file.
 1. Start by changing directory to project root (the directory which contains `generate-script` file)
    ```sh
    $ cd $PROJECT_ROOT
    ```

 1. Clean generated files and generate a new .cpp file, then compile.
    ```sh
    $ make clean
    $ make rsa-crypt.cpp
    $ make compile
    ```

 1. Now the combined code file is located at `$PROJECT_ROOT/singlefile/rsa-crypt.cpp` which you can run normally using
    ```sh
    $ make run
    ```
    or you can run with input redirected from input file `$PROJECT_ROOT/singlefile/rsa-crypt.in` using
    ```sh
    $ make run-fileinput
    ```

##### Method 2: Running the built project. (requires CMake).
 1. Start by changing directory to project root `$PROJECT_ROOT` (the directory which contains `generate-script` file)
    ```sh
    $ cd $PROJECT_ROOT
    ```
    then create build directory
    ```sh
    $ mkdir build
    $ cd build
    ```

 1. Build project
    ```sh
    $ cmake ..
    $ make main
    ```

 1. Run code
    ```sh
    $ pwd
    $PROJECT_ROOT/build
    $ ./main
    ```


### Test Cases

#### Manual testing
`$PROJECT_ROOT/python/generated_tests/` contains many tests with therir expected output.
One of them is:
```
P=207481375392597010851202112591892249773
Q=331770806486424764717034920629855380061
E=100626088435090661121482395257324948518759805644850519795162089101619479129717
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=23249262536259605220061310755303941150524293155329422230716928795028469058032
EncryptPrivate=66041727102282261918590740390480336812003149046636823494235947543867533159992
Quit
```
Expected output of the previous test case is:
```
Yes
Yes
68836263244914555931804870850720294327568185008915478281895479927933255976153
68836263244914555931804870850720294327028932827036456506327242894711508346320
14010463925005658669886400595918579421366418166250860635263639916564993156333
66041727102282261918590740390480336812003149046636823494235947543867533159992
23249262536259605220061310755303941150524293155329422230716928795028469058032
```

this test case's runtime is near 800 ms.

#### Automated testing
This project was developed using Test Driven Development (TDD) with the help of GoogleTest (unit testing framework).
So, you can easily verify its functionality.
To get started you need to have CMake
1. Start by changing directory to project root `$PROJECT_ROOT` (the directory which contains `generate-script` file)
   ```sh
   $ cd $PROJECT_ROOT
   ```
   then create build directory (if it does not exist)
   ```sh
   $ mkdir build
   ```

1. Build project
   ```sh
   $ cd build
   $ cmake ..
   $ make tests
   ```

1. Run tests
   ```sh
   $ pwd
   $PROJECT_ROOT/build
   $ ./tests
   ```

1. You should see that all tests passed. Also you will get the execution time of each test function.

*Note*: you can run very extensive tests (more than 800 test case generated using the attached python scripts) to test functionality of `BigInt` operations, but this tests requires long time to build for the first time. To proceed replace
```sh
$ make tests
$ ./tests
```
by
```sh
$ make tests_long
$ ./tests_long
```
