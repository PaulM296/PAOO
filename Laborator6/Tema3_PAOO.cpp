#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Uncopyable {
protected:                              // allow construction
    Uncopyable() {}                     // and destruction of
    ~Uncopyable() {}                    // derived objects...
private:
    Uncopyable(const Uncopyable&);      // ...but prevent copying
    Uncopyable& operator = (const Uncopyable&);
};

class Triunghi {
    private: 
        string tipTriunghi;
        int lat1;
        int lat2;
        int lat3;
        bool triangleLocked;

    public: 
        Triunghi(): tipTriunghi("nonExistent"), lat1(0), lat2(0), lat3(0), triangleLocked(false){}

        Triunghi(const string &tipTriunghi, const int &lat1, const int &lat2, const int &lat3, const bool &triangleLocked):
        tipTriunghi(tipTriunghi),
        lat1(lat1),
        lat2(lat2),
        lat3(lat3),
        triangleLocked(triangleLocked)
        {}

        Triunghi(const Triunghi &triunghi):
        tipTriunghi(triunghi.tipTriunghi),
        lat1(triunghi.lat1),
        lat2(triunghi.lat2),
        lat3(triunghi.lat3),
        triangleLocked(triunghi.triangleLocked)
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
            this->triangleLocked = rhs.triangleLocked;
            return *this;
        }

        Triunghi& operator += (const Triunghi& rhs) {
            this->tipTriunghi += tipTriunghi;
            this->lat1 += rhs.lat1;
            this->lat2 += rhs.lat2;
            this->lat3 += rhs.lat3;
            this->triangleLocked = rhs.triangleLocked;
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

        bool getTriangleLocked() {
            return triangleLocked;
        }

        void setTriangleLocked(bool triangleLocked) {
            this->triangleLocked = triangleLocked;
        }

        void setLatura1(const int lat1){
            this->lat1 = lat1;
        }
        void setTipTriunghi(const string tipTriunghi) {
            this->tipTriunghi = tipTriunghi;
        }

        int perimetru() {
            return lat1 + lat2 + lat3;
        }

        int semiPerimetru() {
            return (lat1 + lat2 + lat3)/2;
        }
        
        
        // void printTriunghi() {
        //     cout<<this->lat1<<" "<<this->lat2<<" "<<this->lat3<<" "<<this->tipTriunghi<<'\n';
        // }
};

class TriunghiOarecare: public Triunghi {
    private:
        string unghiTriunghi;
    public:
        TriunghiOarecare() : Triunghi(), unghiTriunghi("Nu exista unghiuri"){}
        TriunghiOarecare(const string &tipTriunghi, const int &lat1, const int &lat2, const int &lat3, const bool &triangleLocked, const string unghi) : Triunghi(tipTriunghi, lat1, lat2, lat3, triangleLocked), unghiTriunghi(unghi){}
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

Triunghi* createTriunghi(const string &tipTriunghi, const int &lat1, const int &lat2, const int &lat3, const bool &triangleLocked) {
    return new Triunghi(tipTriunghi, lat1, lat2, lat3, triangleLocked);
}

void lock(Triunghi& triunghi) {
    triunghi.setTriangleLocked(true);
    cout<<"Blocam triunghiul\n";
};

void unlock(Triunghi& triunghi) {
    triunghi.setTriangleLocked(false);
    cout<<"Deblocam triunghiul\n";
};

class Lock : private Uncopyable {
    private:
        Triunghi& triunghiPtr;
    public:
        Lock(Triunghi& ptr): triunghiPtr(ptr) {
            lock(triunghiPtr);
        }
        ~Lock() {
            unlock(triunghiPtr);
        }
};

int main() {
    // Triunghi triunghi("isoscel", 15, 15, 10);
    // Triunghi triunghi2("echilateral", 10, 10, 10);
    // Triunghi triunghi3(triunghi2);
    // Triunghi triunghi4;
    // triunghi4 = triunghi;

    // TriunghiOarecare triunghi("oarecare", 15, 7, 10, "60");
    // TriunghiOarecare triunghi2("oarecare", 20, 18, 10, "78");
    // TriunghiOarecare triunghi3(triunghi);
    // TriunghiOarecare triunghi4;
    // triunghi4 = triunghi2;
    // cout<<triunghi4.getLatura1()<<" "<<triunghi4.getLatura2()<<" "<<triunghi4.getLatura3()<<" "<<triunghi4.getUnghi()<<'\n';

    //item 13
    auto_ptr<Triunghi> triunghi1(createTriunghi("isoscel", 5, 10 ,10, false));
    cout<<triunghi1->getTip()<<" "<<triunghi1->getLatura3()<<'\n';
    auto_ptr<Triunghi> triunghi2(triunghi1); // triunghi2 pointeaza acum spre obiectul creat
    cout<<triunghi2->getLatura1()<<" "<<triunghi2->getLatura2()<<'\n';  
    // cout<<triunghi1->getLatura2()<<" "<<triunghi1->getLatura2()<<'\n'; // va da segmentation fault deoarece triunghi1 acum este null 
    // triunghi1->printTriunghi();

    shared_ptr<Triunghi> triunghi3(createTriunghi("dreptunghic", 3, 4, 5, false));
    cout<<triunghi3->getTip()<<" "<<triunghi3->getLatura3()<<'\n';
    shared_ptr<Triunghi> triunghi4(triunghi3);   // triunghi3 si triunghi4 pointeaza acum spre acelasi obiect returnat de createTriunghi
    cout<<triunghi4->getLatura1()<<" "<<triunghi4->getLatura2()<<'\n';  

    //item 14
    Triunghi triunghi5("echilateral", 10, 10, 10, false);
    cout<<'\n'<<triunghi5.getTip()<<' '<<triunghi5.getLatura1()<<' '<<triunghi5.getLatura2()<<' '<<triunghi5.getLatura3()<<" Locked value: "<<triunghi5.getTriangleLocked()<<'\n';
    {
        Lock Triunghi6(triunghi5);     
        // Lock Triunghi7(Triunghi6);
        triunghi5.setLatura1(15);
        triunghi5.setTipTriunghi("isoscel");
    }
    cout<<'\n'<<triunghi5.getTip()<<' '<<triunghi5.getLatura1()<<' '<<triunghi5.getLatura2()<<' '<<triunghi5.getLatura3()<<" Locked value: "<<triunghi5.getTriangleLocked()<<'\n';


    // cout<<triunghi5.getTriangleLocked()<<'\n';
    // delete triunghi6;
    // cout<<triunghi5.getTriangleLocked()<<'\n';
    return 0;
}