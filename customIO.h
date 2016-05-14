#ifndef CUSTOMIO_H_INCLUDED
#define CUSTOMIO_H_INCLUDED

#ifdef WIN32
    #include <windows.h>
#endif
#include <iostream>


namespace Colour
{
    namespace
    {
        class Colour
        {
            friend std::ostream& operator<<(std::ostream& stream, const Colour& c);
            friend std::istream& operator>>(std::istream& stream, const Colour& c);

            unsigned short colour;
            public:
                Colour(unsigned int c): colour(c) {}
        };

        std::ostream& operator<<(std::ostream& stream, const Colour& c)
        {
            stream.std::ostream::flush();
            #ifdef WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c.colour);
            #endif

            return stream;
        }

        std::istream& operator>>(std::istream& stream, const Colour& c)
        {
            using namespace std;
            cout.flush();
            #ifdef WIN32
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c.colour);
            #endif

            return stream;
        }

        #ifdef WIN32
            const Colour BLACK   = 0;
            const Colour NORMAL  = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;
            const Colour WHITE   = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
            const Colour RED     = FOREGROUND_RED|FOREGROUND_INTENSITY;
            const Colour DKRED     = FOREGROUND_RED;
            const Colour CYAN    = FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
            const Colour BLUE    = FOREGROUND_BLUE|FOREGROUND_INTENSITY;
            const Colour DKBLUE    = FOREGROUND_BLUE|FOREGROUND_GREEN;
            const Colour GREEN   = FOREGROUND_GREEN|FOREGROUND_INTENSITY;
            const Colour DKGREEN   = FOREGROUND_GREEN;
            const Colour YELLOW  = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
            const Colour BROWN   = FOREGROUND_RED|FOREGROUND_GREEN;
            const Colour PINK   = FOREGROUND_RED|FOREGROUND_BLUE| FOREGROUND_INTENSITY;
            
        #else
            const Colour BLACK  = 0;
            const Colour NORMAL  = 0;
            const Colour WHITE   = 0;
            const Colour RED     = 0;
            const Colour DKRED     = 0;
            const Colour CYAN    = 0;
            const Colour BLUE    = 0;
            const Colour DKBLUE    = 0;
            const Colour GREEN   = 0;
            const Colour DKGREEN   = 0;
            const Colour YELLOW  = 0;
            const Colour BROWN   = 0;
            const Colour PINK   = 0;
        #endif

        template <typename T> bool get(T &t)
        {
            using std::cin;
            cin >> t;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return false;
            }
            else if (cin.bad())
            {
                cin.clear();
                return false;
            }
            else if (cin.eof())
            {
                cin.clear();
            }
            return true;
        }
    }
}

#endif // CUSTOMIO_H_INCLUDED
