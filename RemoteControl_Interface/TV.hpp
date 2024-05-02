#ifndef __TV__
#define __TV__

#include "remoteControl.hpp"

class TV : public RemoteControl {
    public:
        TV(const int &channel) : _channel(channel) {}

        void powerOn() override;
        void powerOff() override;
        void volumeUp() override;
        void volumeDown() override;
        void setChannel() override;
    protected:
        int _channel;    
};

#endif // __TV__