#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include "GUI.h"

int main(void) {
    bool status = false;
    unsigned instance = 0;
    std::ofstream create(cache_n, std::ifstream::binary);
    create.close();

    while (1)
        instance += userInterface(&status, instance);
    return 0;
}
