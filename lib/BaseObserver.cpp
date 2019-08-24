#include  "BaseObserver.hpp"
int BaseObserver::getValue(void)
{
    return privateValue;
};
void BaseObserver::setValue(int newV)
{
    privateValue=newV;
    return ;
};
void  BaseObserver::addValue( int i )
{
    privateValue+=(2*i);/* fake to test this is been different from derived class implementation*/
    return ;
};
void BaseObserver::operator()(int bpm)
{
    setBPM(bpm);
};
void BaseObserver::setBPM(int bpm)
{
    _bpm = bpm;
//notifyBPMObservers();
};
