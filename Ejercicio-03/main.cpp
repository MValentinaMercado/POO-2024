#include <iostream>
#include "proyecto.h"
using namespace std;

int main() {
    string version = proyecto::getVersion();
    cout << version << endl;
    return 0;
}
