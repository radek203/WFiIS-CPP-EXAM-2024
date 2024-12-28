#include <iostream>
#include <string>

namespace OOP {
    class Auto
    {
    public:
        Auto(int d = 0) : m_km(d)
        { std::cout << "Konstruktor Auto\n"; }

        virtual ~Auto()
        { std::cout << "Destruktor Auto\n"; }

        virtual void travel(int d) {
            m_km += d;
        }

        virtual void printTraveled()
        {
            std::cout << "Auto przejechalo "
                      << m_km << " km " << std::endl;
        }

    protected:
        int m_km;

    private:
        void fun()
        {}
    };

}  // namespace OOP

namespace OOP {

    class Lodz
    {
    public:
        Lodz(int d = 0) : m_sm(d)
        { std::cout << "Konstruktor Lodz\n"; }

        virtual ~Lodz()
        { std::cout << "Destruktor Lodz\n"; }

        virtual void travel(int d)
        {
            m_sm += d;
        }

        virtual void printTraveled()
        {
            std::cout << "Lodz przeplynela "
                      << m_sm << " mil " << std::endl;
        }

        void fun()
        {}

    protected:
        int m_sm;
    };

}  // namespace OOP

namespace OOP
{
    class Amf : public Auto, public Lodz
    {
    public:
        Amf(int k = 0, int s = 0) : Auto(k), Lodz(s)
        { std::cout << "Konstruktor Amf\n"; }

        virtual ~Amf()
        { std::cout << "Destruktor Amf\n"; }

        virtual void printTraveled()
        {
            std::cout << "Amfibia pokonala "
                      << m_km << " km i " << m_sm << " mil " << std::endl;
        }
    };

}  // namespace OOP


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
    using namespace std;
    using namespace OOP;

    Amf aAmf;

    //BLAD bo nie wiadomo, ktora funkcje uzyc z Auto czy z Lodz
    // aAmf.travel(10);

    //musimy uzyc operator zakresu
    aAmf.Auto::travel(100);
    aAmf.Lodz::travel(10);

    aAmf.printTraveled();

    //BLAD bo nie wiadomo, ktora funkcje uzyc z Auto czy z Lodz
    //pomimo tego ze nia ma dostepu do fun z Auto
    // aAmf.fun();

}