#include <iostream>

#include <list>
using namespace std;
class subject;

class observer{
public:
    virtual ~observer() {};

    virtual void update(subject *s)=0;
};

class subject{
public:
    virtual void add_observer(observer *o)=0;
    virtual void remove_observer(observer *o)=0;
    virtual void print()=0;
    virtual void notify()=0;
    virtual ~subject() {};
};


class PacketMon:public subject{
public:
    PacketMon():packets(0){}
    void add_packet(int packet){
        this->packets+=packet;
        if(packets%100==0){
            notify();
        }
    }

    virtual void print()override {
        cout<<this->get_packets();

    }
    int get_packets() const{
        return packets;
    }

    virtual void add_observer(observer *o) override {
        _o.push_back(o);
    }
    virtual void remove_observer(observer *o)override{
        _o.remove(o);
    }
    virtual void notify()override {

        for(auto itr=_o.begin();itr!=_o.end();++itr){
            cout<<endl<<"Packet"<<endl;
            (*itr)->update(this);


        }


    }
private:
    int packets;
    list<observer*> _o;

};

class CPUUsage:public subject{
public:
    CPUUsage(): use(0){}

        void _update(int howmuch=1){
            use = use + howmuch;
            if(use%10==0){
                notify();
            }
        }

        virtual void print()override {
        cout<<this->getUsage();

    }
       virtual void add_observer(observer *o)override{
             _o.push_back(o);
        }

        virtual void remove_observer(observer *o)override{
            _o.remove(o);
    }
    virtual void notify()override {
        for(auto itr = _o.begin();itr!=_o.end();++ itr){
            cout<<endl<<"Usage:"<<endl;
            (*itr)->update(this);
        }

    }
        int getUsage() const {
            return use;
        }


private:
    int use;
    list<observer*> _o;
};


class multimonitor:public observer{
public:

    multimonitor(const string &name) : name(name) {}

    virtual void update(subject *s) override {
        cout << name << endl;
        s->print();
        cout<<endl;
    }

private:
    string name;
    list<subject*> _s;
};
int main() {
CPUUsage usage;
PacketMon packet;
multimonitor multi("monitor_1");
multimonitor multi_2("monitor_2");
multimonitor multi_3("monitor_3");
packet.add_observer(&multi);
packet.add_observer(&multi_2);
usage.add_observer(&multi);
usage.add_observer(&multi_2);
usage.add_observer(&multi_3);

for(int i=0;i<100;i++){
    packet.add_packet(1);
    usage._update(1);

}
usage.remove_observer(&multi_2);
usage._update(10);



}
