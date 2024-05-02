#ifndef __RemoteControl__
#define __RemoteControl__

#include <iostream>

class RemoteControl {
    public:
        RemoteControl(const int &channel) : _channel(channel) {}

        virtual void powerOn() = 0;
        virtual void powerOff() = 0;
        virtual void volumeUp() = 0;
        virtual void volumeDown() = 0;
        virtual void setChannel() = 0;

        virtual ~RemoteControl() {}

    protected:
        int _channel;
};

#endif // __RemoteControl__