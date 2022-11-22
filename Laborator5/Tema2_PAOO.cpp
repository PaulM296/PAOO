#include <iostream>
#include <string>
using namespace std;

// class Uncopyable {
// protected:                              // allow construction
//     Uncopyable() {}                     // and destruction of
//     ~Uncopyable() {}                    // derived objects...
// private:
//     Uncopyable(const Uncopyable&);      // ...but prevent copying
//     Uncopyable& operator = (const Uncopyable&);
// };

class Triunghi {
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

        Triunghi(const Triunghi &triunghi):
        tipTriunghi(triunghi.tipTriunghi),
        lat1(triunghi.lat1),
        lat2(triunghi.lat2),
        lat3(triunghi.lat3)
        {}

        ~Triunghi() {
            cout<<"Object has been destroyed!\n";
        }

        Triunghi& operator = (const Triunghi& rhs) {
            if(this == &rhs) {
                cout<<"Este acelasi obiect\n";
                return *this;
            }
            this->tipTriunghi = rhs.tipTriunghi;
            this->lat1 = rhs.lat1;
            this->lat2 = rhs.lat2;
            this->lat3 = rhs.lat3;
            return *this;
        }

        Triunghi& operator += (const Triunghi& rhs) {
            this->tipTriunghi += tipTriunghi;
            this->lat1 += rhs.lat1;
            this->lat2 += rhs.lat2;
            this->lat3 += rhs.lat3;
            return *this;
        }

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

class TriunghiOarecare: public Triunghi {
    private:
        string unghiTriunghi;
    public:
        TriunghiOarecare() : Triunghi(){}
        TriunghiOarecare(const string &tipTriunghi, const int &lat1, const int &lat2, const int &lat3, const string unghi) : Triunghi(tipTriunghi, lat1, lat2, lat3), unghiTriunghi(unghi){}
        TriunghiOarecare(const TriunghiOarecare &triunghiOarecare) : Triunghi(triunghiOarecare), unghiTriunghi(triunghiOarecare.unghiTriunghi){}
        ~TriunghiOarecare(){
            cout<<"Triunghiul oarecare a fost distrus\n";
        }
        TriunghiOarecare& operator = (const TriunghiOarecare& rhs){
            if(this == &rhs) {
                cout<<"Este acelasi obiect\n";
                return *this;
            }
            Triunghi::operator=(rhs);
            unghiTriunghi = rhs.unghiTriunghi;
            return *this;
        }
        string getUnghi() {
            return this->unghiTriunghi;
        }
};

int main() {
    // Triunghi triunghi("isoscel", 15, 15, 10);
    // Triunghi triunghi2("echilateral", 10, 10, 10);
    // Triunghi triunghi3(triunghi2);
    // Triunghi triunghi4;
    // triunghi4 = triunghi;

    TriunghiOarecare triunghi("oarecare", 15, 7, 10, "60");
    TriunghiOarecare triunghi2("oarecare", 20, 18, 10, "78");
    TriunghiOarecare triunghi3(triunghi);
    TriunghiOarecare triunghi4;
    triunghi4 = triunghi2;
    cout<<triunghi4.getLatura1()<<" "<<triunghi4.getLatura2()<<" "<<triunghi4.getLatura3()<<" "<<triunghi4.getUnghi()<<'\n';
    return 0;
}