#include <iostream>
#include "proyecto.h"

using namespace std;

int main() {
    string version = proyecto::getVersion(1.0, "19/05/2024");
    cout << version << endl;
    return 0;
}
