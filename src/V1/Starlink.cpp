#include "Starlink.h"
#include "LinkedList.h"

void Starlink::release() {
	while(root != nullptr){
        removeSat(nullptr,true);
    }
}

Iterator* Starlink::createIterator() {
	return new LinkedList(root);
}

void Starlink::addSat(Satelite *s) {
    if(root == nullptr){
        root = s;
        return;
    }
    Iterator* it = createIterator();
    while(it->hasNext()){
        it->next();
    }
    it->current()->setNextSatelite(s);
}

void Starlink::removeSat(Satelite *s, bool launch) {
    if(s != nullptr){
        if(root == nullptr){
            return;
        }
        Iterator* it = createIterator();
    if(it->current() == s){
        it->next();
        root = it->current();
        it->current()->setNextSatelite(nullptr);
        return;
    }
    Iterator* prev = createIterator();
    if(it->hasNext()){
        it->next();
        if(it->current() == s){
            prev->current()->setNextSatelite(it->current()->getNextSatelite());
            return;
        }
        while(it->hasNext()){
            it->next();
            prev->next();
            if(it->current() == s){
                prev->current()->setNextSatelite(it->current()->getNextSatelite());
            }
            return;
        }
    }
    }else{
        if(root == nullptr){
            return;
        }
        Iterator* it = createIterator();
        if(it->hasNext()){
            it->next();
            Iterator* prev = createIterator();
            while(it->hasNext()){
                prev->next();
                it->next();
            }
            if(launch){
                it->current()->release();
            }
            prev->current()->setNextSatelite(nullptr);
        }else{
            if(launch){
                root->release();
            }
            root = nullptr;
        }
    }
}

Starlink::Starlink() {
    root = nullptr;
    string name;
    stringstream ss;
    for(int i = 60; i > 0; i--)
    {
        ss<<"Starlink-"<<i;
        ss>>name;
        addSat(new Satelite(name));
        ss.clear();
    }
}

bool Starlink::isEmpty() {
    return root == nullptr;
}

Payload *Starlink::clone() {
    return this;
}

void Starlink::Activate() {
    release();
}

void Starlink::VentFuel() {

}

void Starlink::LoadFuel() {

}

double Starlink::GetFuel() {
    return 0;
}