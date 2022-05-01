#include <iostream>
#include <algorithm>
#include <cmath>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
int mas[1000];
int main()
{   
    using namespace std;
    int a = 1000;

    srand(time(0));
    for (int i = 0; i < a; i++)
    {
        mas[i]= rand () % 10000;

        cout << mas[i] << endl;
    }
    int b = 0;
    Timer Q;   
    
    for (int i = 0; i < a; i++)
    {   
        b++;
        if (mas[i] % 2 != 0)
        {
            cout << Q.elapsed()<<" "<<mas[i] <<" " << b << endl;
            break;
        }
        
    }
}
