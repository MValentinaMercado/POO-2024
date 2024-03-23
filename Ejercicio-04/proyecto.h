#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

namespace proyecto {
    string getVersion() {

        //archivo que almacena el nro de version
        ifstream versionFile("version.txt");

        if (!versionFile.is_open()) {
            ofstream newVersionFile("version.txt");
            if (!newVersionFile.is_open()) {
                return "Error al crear el archivo de versión";
            }
            newVersionFile << "0.0.0";
            newVersionFile.close();

            versionFile.open("version.txt");
            if (!versionFile.is_open()) {
                return "Error al abrir el archivo de versión";
            }
        }

        string versionStr;
        getline(versionFile, versionStr);
        versionFile.close();

        // para que cada vez se actualize el nro de version
        int major = 0, minor = 0, patch = 0;
        sscanf(versionStr.c_str(), "%d.%d.%d", &major, &minor, &patch);
        patch++;

        ofstream outFile("version.txt");
        if (!outFile.is_open()) {
            return "Error al abrir el archivo de versión";
        }
        outFile << major << '.' << minor << '.' << patch;
        outFile.close();

        // fecha actual
        time_t currentTime = time(nullptr);
        char formattedDateTime[9];
        strftime(formattedDateTime, sizeof(formattedDateTime), "%Y%m%d", localtime(&currentTime));

        ostringstream versionInfoStream;
        versionInfoStream << "v" << major << '.' << minor << '.' << patch << " - " << formattedDateTime;
        return versionInfoStream.str();
    }
}

#endif
