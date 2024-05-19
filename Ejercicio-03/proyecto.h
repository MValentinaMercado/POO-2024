#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
using namespace std;

namespace proyecto {
    string getVersion(double version, string date) {
        return "Version " + to_string(version) + " (" + date + ")";
    }
}


#endif // PROYECTO_H
