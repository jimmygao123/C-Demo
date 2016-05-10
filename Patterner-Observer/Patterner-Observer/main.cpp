//
//  main.cpp
//  Patterner-Observer
//
//  Created by jimmygao on 3/4/16.
//  Copyright (c) 2016 jimmygao. All rights reserved.
//

#include <iostream>
#include <list>

class Observer
{
public:
    virtual void Update(int) = 0;
};

class Subject{
public:
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
};

class ConcreteObserver : public Observer{
public:
    ConcreteObserver(Subject *pSubject) : m_pSubject(pSubject){};
    
    void Update(int value){
        std::cout<<"ConcreteObserver get the update. New State:"<<value<<std::endl;
    }
private:
    Subject *m_pSubject;
};

class ConcreteObserver2 : public Observer{
public:
    ConcreteObserver2(Subject *pSubject) :m_pSubject(pSubject){};
    void Update(int value)
    {
        std::cout<<"ConcreteObserver2 get the update. New State:"<<value<<std::endl;
    }
    
private:
    Subject *m_pSubject;
};

class ConcreteSubject : public Subject{
public:
    void Attach(Observer*);
    void Detach(Observer*);
    void Notify();
    
    void setState(int state){
        m_state = state;
    }
private:
    std::list<Observer*> m_Observerlist;
    int m_state;
};

void ConcreteSubject::Attach(Observer *pObserver){
    m_Observerlist.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver){
    m_Observerlist.remove(pObserver);
}

void ConcreteSubject::Notify(){
    std::list<Observer *>::iterator it = m_Observerlist.begin();
    while (it != m_Observerlist.end()) {
        (*it) -> Update(m_state);
        ++it;
    }
}


int main()
{
    ConcreteSubject *subject = new ConcreteSubject();
    
    ConcreteObserver *observer1 = new ConcreteObserver(subject);
    ConcreteObserver2 *observer2 = new ConcreteObserver2(subject);
    
    subject->Attach(observer1);
    subject->Attach(observer2);
    
    subject->setState(2);
    subject->Notify();
    
    subject->Detach(observer1);
    
    subject->setState(3);
    subject->Notify();
    
    delete subject;
    delete observer1;
    delete observer2;
}