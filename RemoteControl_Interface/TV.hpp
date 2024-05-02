#ifndef __TV__
#define __TV__

#include "remoteControl.hpp"

class TV : public RemoteControl {
    public:
        TV(const int &channel) : RemoteControl(channel) {}

        void powerOn() override;
        void powerOff() override;
        void volumeUp() override;
        void volumeDown() override;
        void setChannel() override;
};

#endif // __TV__