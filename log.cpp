#include "main.h"

int curtLogLayer = LOG_ERROR;

void LogHandle(int layer, string tag, string detail) {
    if (layer == LOG_INFO && curtLogLayer >= LOG_INFO) {
        cout << "INFO-" << tag << ":" << detail << endl;
    } 
    if (layer == LOG_ERROR && curtLogLayer >= LOG_ERROR) {
        cout << "ERROR-" << tag << ":" << detail << endl;
    }
}
