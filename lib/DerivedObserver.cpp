#include  "DerivedObserver.hpp"
int  DerivedObserver::getValue( void)
{
    auto  temp=privateValue;
    return privateValue;
};
void  DerivedObserver::addValue( int i )
{
    privateValue+=i;
    std::cout << " DerivedObserver::addValue was called \n ";
    return;
};
