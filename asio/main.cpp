
#include <iostream>
#include "SerialPort.hpp"

using namespace std;
using namespace boost;

int main(int argc, char* argv[]){
    try {
        SerialPort serial;
        serial.open("/dev/ttyUSB0",115200);
        serial.write("Hello world\n");
        // string msg;
        int num = serial.read(100);
        string msg(serial.buffer.data(), serial.buffer.size());
        cout << "Received [" << num << "]: " << msg << " : end" << endl;
    }
    catch(boost::system::system_error& e){
        cout << "Error: " << e.what() << endl;
        return 1;
    }
}
