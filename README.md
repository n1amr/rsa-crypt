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
`$PROJECT_ROOT/singlefile/rsa-crypt.in` contains two basic test cases which are
```
# simple example
P=11
Q=17
E=7
PrintN
PrintPhi
PrintD
EncryptPublic=88
EncryptPrivate=11

P=12369571528747655798110188786567180759626910465726920556567298659370399748072366507234899432827475865189642714067836207300153035059472237275816384410077871
Q=2065420353441994803054315079370635087865508423962173447811880044936318158815802774220405304957787464676771309034463560633713497474362222775683960029689473
E=65537
IsPPrime
IsQPrime
PrintN
PrintPhi
PrintD
EncryptPublic=88
EncryptPrivate=4397678428390379126255360246165021910057442267382175543246817108158797115317154540746718616555865161372450860559307149988169566508274711121236049281217144195628407516579953387138808449458611836421032431582081899650685651973204503916459595600207918950383877057152533041873901965623112895996177941667469292738
EncryptPrivate=11
EncryptPublic=21880230932604477992614117893862222757212287845281021154543717510642642365619523838019035747962755670112744108613949995939938709109560325465896091816053995698880564550411021131784018129301522482453764524425009272603306228293577801089684280984807415949225937675518051511432970692327336163089308396188679795011

Quit
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
