/*\File atomicMultiThread.cpp
 * demo using threads & smartPointers collection of Observer*/

#include "../lib/Foo.hpp"
#include  "../lib/DerivedObserver.hpp"
#include  "../lib/BaseObserver.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
class Model {
public:
    int _bpm;
    std::list<pBaseObserver> Observers;
    virtual  void registerObserver(pBaseObserver);
    virtual  void unregisterObserver(pBaseObserver);
    virtual void notifyObservers();
};
void Model::registerObserver(pBaseObserver o)
{
    Observers.push_back(std::move(o));
};
void Model::unregisterObserver(pBaseObserver  o)
{
    Observers.remove(std::move(o));
};
void Model::notifyObservers()
{
    /*  for( std::list<std::unique_ptr<IBPMObserver>>::iterator listMyClassIter=bpmObservers.begin(); listMyClassIter>
    listMyClassIter ++)
    *listMyClassIter(_bpm);
    */
    auto m=_bpm;
    std::for_each(  Observers.begin(), Observers.end(), [m](pBaseObserver n) {
        n->operator()(m);
    });
    /* matthew
    for (const auto& observer : bpmObservers)
    try {
    (*(observer.get()))(_bpm);
    } catch (std::exception &e) {
    std::cerr << "notifyBPMObservers throws exception: one of bpmObserver failed to update it's speed " << e.>
    }*/
};

int main()
{
    Foo foo1;
    std::cout << "Type anything to end thread" << std::endl;
    foo1.StartThread();
    foo1.SendData();
//    type something to end threads
    char a;
    std::cin >> a;
    foo1.StopThread();
    std::unique_ptr<DerivedObserver> derived = std::make_unique<DerivedObserver>();/* a sub class object*/
    derived->setValue(5);
    std::cout<<"after derived->setValue(5);new is: "<<derived->getValue() << std::endl;
    derived->setValue(6);
    derived->addValue(666);
    std::cout<<"after base ->setValue(6)& addvalue(666);"<<derived->getValue() << std::endl;
    std::unique_ptr<Model> amodel=std::make_unique<Model>();
    amodel->registerObserver(derived.release());
    return 0;
}
