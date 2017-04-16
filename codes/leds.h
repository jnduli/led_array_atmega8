#define row1 PC5
#define row2 PC4
#define row3 PC3
#define row4 PC2
#define row5 PC1

#define col1 PC0
#define col2 PB5
#define col3 PB4
#define col4 PB3
#define col5 PB2
#define col6 PB1
#define col7 PB0
#define col8 PD5
#define col9 PD6
#define col10 PD7

#include <avr/io.h>

const int rows_pins[] = {PC5, PC4, PC3, PC2, PC1};
const int cols_pins[] = {PC0, PB5, PB4, PB3, PB2, PB1, PB0, PD5, PD6, PD7};


#define rows 5
#define cols 10
class Leds
{
    public:
        Leds ();
        void lightLED ( int row, int col );
        void turnOffLED ( int row, int col );
        void lightAllLEDs ();
        void turnOffAllLEDs();
        void drawCharacter ( const int A [3][5]);
        void drawBuffer();
        void makePattern( int j);
        void drawPattern();
        void setColumn(int a, int b);

        //variables
        //
        static const int buffer_row = 5;
        static const int buffer_col = 10;
        static const int pattern_col = 48;
        volatile int8_t buffer [buffer_row][buffer_col] = {
            {1,0,1,0,1,0,1,1,0,1},
            {1,0,1,1,0,1,1,0,1,1},
            {1,1,1,1,1,1,1,1,0,1},
            {1,0,1,1,0,1,1,0,0,1},
            {1,0,1,1,0,1,1,0,0,1}
        };
        //int pattern [buffer_row][buffer_col] = {
            //{1,0,1,0,1,0,1,1,0,1},
            //{1,0,1,1,0,1,1,0,1,1},
            //{1,1,1,1,1,1,1,1,0,1},
            //{1,0,1,1,0,1,1,0,0,1},
            //{1,0,1,1,0,1,1,0,0,1}
        //};
        const uint8_t pattern [buffer_row][pattern_col] ={
            {1,0,1,0,0,1,0,0,1,1,0,0,1,1,0,0,1,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,1,0,1,1,1,0,1,1,1,0,1,1,0,0,0,0},
            {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0},
            {1,1,1,0,1,1,1,0,1,1,0,0,1,1,0,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,0,0,0,0},
            {1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0},
            {1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,1,0,1,0,1,1,0,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0}
        };
        const int H [3][5] = {
            {1,1,1,1,1},
            {0,0,1,0,0},
            {1,1,1,1,1}
        };
        const int A [3][5] = {
            {0,1,1,1,1},
            {1,0,1,0,0},
            {0,1,1,1,1}
        };
        const int P [3][5] = {
            {1,1,1,1,1},
            {1,0,1,0,0},
            {0,1,0,0,0}
        };
        const int Y [3][5] = {
            {1,1,1,0,1},
            {0,0,1,0,1},
            {1,1,1,1,0}
        };
        const int E [3][5] = {
            {1,1,1,1,1},
            {1,0,1,0,1},
            {1,0,1,0,1}
        };
        const int S [3][5] = {
            {0,1,0,0,1},
            {1,0,1,0,1},
            {1,0,0,1,0}
        };
        const int T [3][5] = {
            {1,0,0,0,0},
            {1,1,1,1,1},
            {1,0,0,0,0}
        };
        const int R [3][5] = {
            {1,1,1,1,1},
            {1,0,1,0,0},
            {0,1,0,1,1}
        };
};
