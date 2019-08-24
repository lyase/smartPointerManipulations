#pragma once
#ifndef BaseObserver_H
#define BaseObserver_H
#include  "BaseObserver.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>
class BaseObserver {
public:
    virtual void setValue(int newV);
    virtual int getValue(void);
    virtual void addValue(int i )=0;
    virtual ~BaseObserver() = default;
    virtual void setBPM(int bpm);
    int privateValue; /*if private derived class won't access this*/
    int _bpm;
    virtual void operator()(int bpm) = 0;
private :
};
#ifdef HAVE_CPP11
using pBaseObserver = std::unique_ptr<BaseObserver>;
#else
typedef BaseObserver* pBaseObserver;
#endif
#endif
