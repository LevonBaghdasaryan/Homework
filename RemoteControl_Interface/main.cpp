#include "remoteControl.hpp"
#include "TV.hpp"

int main() {

    TV tv(1);

    tv.powerOn();
    tv.volumeUp();
    tv.setChannel();
    tv.volumeDown();
    tv.powerOff();
    
    return 0;
}