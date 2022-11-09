#include <iostream>
#include <string>
using namespace std;

class Uncopyable {
protected:                              // allow construction
    Uncopyable() {}                     // and destruction of
    ~Uncopyable() {}                    // derived objects...
private:
    Uncopyable(const Uncopyable&);      // ...but prevent copying
    Uncopyable& operator = (const Uncopyable&);
};

class Triunghi: private Uncopyable {
    private: 
        string tipTriunghi;
        int lat1;
        int lat2;
        int lat3;

    public: 
        Triunghi(){}

        Triunghi(const string &tipTriunghi, const int &lat1, const int &lat2, const int &lat3):
        tipTriunghi(tipTriunghi),
        lat1(lat1),
        lat2(lat2),
        lat3(lat3)
        {}

        // Triunghi(const Triunghi &triunghi):
        // tipTriunghi(triunghi.tipTriunghi),
        // lat1(triunghi.lat1),
        // lat2(triunghi.lat2),
        // lat3(triunghi.lat3)
        // {}

        ~Triunghi() {
            cout<<"Object has been destroyed!\n";
        }

        // Triunghi& operator = (const Triunghi& rhs) {
        //     this->tipTriunghi = rhs.tipTriunghi;
        //     this->lat1 = rhs.lat1;
        //     this->lat2 = rhs.lat2;
        //     this->lat3 = rhs.lat3;
        //     return *this;
        // }

        string getTip(){
            return tipTriunghi;
        }

        int getLatura1() {
            return lat1;
        }

        int getLatura2() {
            return lat2;
        }

        int getLatura3() {
            return lat3;
        }

        int perimetru() {
            return lat1 + lat2 + lat3;
        }

        int semiPerimetru() {
            return (lat1 + lat2 + lat3)/2;
        }
};

int main() {
    Triunghi triunghi("isoscel", 15, 15, 10);
    cout<<"Tip triunghi: "<< triunghi.getTip()<<"\n";
    cout<<"Latura1: "<< triunghi.getLatura1()<<"\n";
    cout<<"Latura2: "<< triunghi.getLatura2()<<"\n";
    cout<<"Latura3: "<< triunghi.getLatura3()<<"\n";
    Triunghi triunghi2("echilateral", 10, 10, 10);
    Triunghi triunghi3(triunghi2);
    cout<<"Perimetrul triunghiului "<<triunghi.getTip()<<" este "<<triunghi.perimetru()<<"\n";
    cout<<"Semiperimetrul triunghiului "<<triunghi3.getTip()<<" este "<<triunghi3.semiPerimetru()<<"\n";
    Triunghi triunghi4;
    triunghi4 = triunghi;
    cout<<"Semiperimetrul triunghiului "<<triunghi4.getTip()<<" este "<<triunghi4.semiPerimetru()<<"\n";
    return 0;
}