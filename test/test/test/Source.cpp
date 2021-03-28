#include <string>
#include <iostream>

//class COczko {
//public:
//    COczko() { this->kolor = "szary"; }
//    std::string dajKolor() { return kolor; }
//private:
//    std::string kolor;
//};
//class CMisio {
//private:
//    COczko lewe;
//    COczko prawe;
//public:
//    COczko& dajLewe() { return lewe; }
//    COczko& dajPrawe() { return prawe; }
//};
//
//int main() {
//    CMisio misio;
//    misio = CMisio();
//    misio.dajLewe() = COczko();
//    misio.dajPrawe() = COczko();
//    std::cout << misio.dajLewe().dajKolor() << std::endl;
//    std::cout << misio.dajPrawe().dajKolor() << std::endl;
//};

//class CTowar {
//private:
//    int ilosc;
//    std::string nazwa;
//public:
//    CTowar() { nazwa = ""; ilosc = 0; }
//    void setNazwa(std::string _n) { nazwa = _n; }
//    void setIlosc(int _i) { ilosc = _i; }
//    void pisz() { std::cout << nazwa << ", ilosc: " << ilosc; }
//    CTowar operator+(const int& il)
//    {
//        CTowar ctowar;
//        ctowar.setNazwa(nazwa);
//        ctowar.setIlosc(ilosc + il);
//        return ctowar;
//    };
//};
//
//int main() {
//    CTowar a;
//    a.setNazwa("jaja");
//    a.setIlosc(5);
//    a = a + 5;
//    a.pisz();
//};
//
//class A {
//    private:
//        double FVect[3];
//    protected:
//        void check_index(const int& _idx)
//        {
//            if (_idx > 2)
//                throw std::invalid_argument("Indeks nie mo¿e byæ wiêkszy od 2.");
//            if (_idx < 0)
//                throw std::invalid_argument("Indeks nie mo¿e byæ ujemny.");
//        }
//    public:
//        virtual void setValue(int _idx, double _val) 
//        {
//            check_index(_idx);
//            FVect[_idx] = _val; 
//        }
//        virtual double value(int _idx) 
//        { 
//            check_index(_idx);
//            return FVect[_idx]; 
//        }
//};

//// przyk³ad przechwycenia wyj¹tku
//class B : public A
//{
//    public:
//        B() : A() {};
//        void clear()
//        {
//            for (int i = 0; i < 4; ++i)
//            {
//                try
//                {
//                    setValue(i, 0);
//                }
//                catch (const char* msg)
//                {
//                    std::cout << msg;
//                }
//            }
//   
//        };
//        void add(const double& d)
//        {
//            for (int i = 0; i < 4; ++i)
//            {
//                try
//                {
//                    setValue(i, value(i) + d);
//                }
//                catch (const char* msg)
//                {
//                    std::cout << msg;
//                }
//            }   
//        };
//};

//#include <vector>
//
//double suma_co_x(const std::vector<double>& v, const int& pocz, const int& kon, const int& x)
//{
//	if (pocz > kon)
//		throw std::invalid_argument("pocz nie mo¿e byæ wiêksze od kon");
//	if(pocz > v.size())
//		throw std::invalid_argument("pocz nie mo¿e byæ wiêksze od dlugosci wektora");
//
//	double sum = 0;
//	for (int idx = pocz; idx < kon; idx += x)
//		sum += v[idx];
//
//	return sum;
//};

class A {
    private:
        int* eA = nullptr;
    public:
        A() { eA = new int[15]; }
        A(const A&&) = delete;
        A& operator=(const A&) = default;
        ~A() { delete[] eA; }
    };

class B : public A {
    double* eB = nullptr;
public:
    B() : A() { eB = new double[10]; }
    B(const B&) = delete;
    B& operator=(const B&) = delete;
    ~B() { delete[] eB; }
};

int main()
{
    A a = A();
    //B b = B();
}
//
//class Generator {
//    private: char Aktualny;
//    public: 
//        Generator(char _a = 'A') : Aktualny(_a) { }
//        char operator()()
//        {
//            char Kolejny = int(Aktualny) + 2;
//            Aktualny = Kolejny;
//            return Aktualny;
//        };
//};
//
//int main(int argc, char* argv[])
//{
//    Generator g('a'); // to i nastêpne jest w main:
//    char czn = g();
//    while (czn <= 'z') {
//        std::cout << czn;
//        czn = g();
//    }
//}