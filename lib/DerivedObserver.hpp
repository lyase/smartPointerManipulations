#pragma once
#ifndef DerivedObserver_H
#define DerivedObserver_H
#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include "DerivedObserver.hpp"
#include  "BaseObserver.hpp"
#include "BaseObserver.hpp"
class DerivedObserver :public BaseObserver {
public:
    ~DerivedObserver() {}
    int WidgetValue;
    int getValue(void) override;
    virtual void addValue(int i )override ;
    virtual void setBPM(int bpm) override;
    virtual void operator()(int bpm) override {};
private:
};
#ifdef HAVE_CPP11
using pDerivedObserver = std::unique_ptr<DerivedObserver>;
#else
typedef DerivedObserver* pDerivedObserver;
#endif
#endif
