#ifndef __RemoteControl__
#define __RemoteControl__

#include <iostream>

class RemoteControl {
    public:
        virtual void powerOn() = 0;
        virtual void powerOff() = 0;
        virtual void volumeUp() = 0;
        virtual void volumeDown() = 0;
        virtual void setChannel() = 0;

        virtual ~RemoteControl() {}
};

#endif // __RemoteControl__