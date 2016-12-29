#ifdef N1AMR_MULTIPLE_FILES

#include <iostream>
using namespace std;

#include "App.h"
#endif //N1AMR_MULTIPLE_FILES

int main() {
#ifndef N1AMR_LOCAL_PC
  srand(time(NULL));
#endif //N1AMR_LOCAL_PC
  appLoop();
}
