#define F_CPU 1000000UL

#include "leds.h"
#include <avr/io.h>
#include <util/delay.h>


Leds:: Leds()
{
    // include setup definitions
    DDRC |= (1<<row1) | (1<<row2) | (1<<row3) | (1<<row4) | (1<<row5) | (1<<col1);
    DDRB |= (1<<col2) | (1<<col3) | (1<<col4) | (1<<col5) | (1<<col6) | (1<<col7);
    DDRD |= (1<<col8) | (1<<col9) | (1<<col10);
};

void Leds:: lightLED ( int row, int col )
{
    // includ code to light one led
    PORTC |= ( 1<< rows_pins[row] );
    if ( col == 0 )
        PORTC &= ~( 1<< cols_pins[col] );
    else if (col < 7)
        PORTB &= ~ ( 1<< cols_pins[col] );
    else
        PORTD &= ~( 1<< cols_pins[col] );
}

void Leds:: turnOffLED( int row, int col )
{
    PORTC &= ~( 1<< rows_pins[row] );
    if ( col == 0 )
        PORTC |= ( 1<< cols_pins[col] );
    else if (col < 7)
        PORTB |=  ( 1<< cols_pins[col] );
    else
        PORTD |= ( 1<< cols_pins[col] );
}

void Leds:: lightAllLEDs ()
{
    for ( int i = 0; i<rows; i++ )
        for ( int j = 0; j <cols ; j++ ){
            lightLED(i,j);
            _delay_ms(10);
            turnOffLED(i,j);
            _delay_ms(10);
        }
}

void Leds:: turnOffAllLEDs ()
{
    PORTC = 0;
    PORTC |= (1<<PC0);
    PORTB = 0xff;
    PORTD = 0xff;
}

//int[][] Leds:: makePattern ()
//{
    //looking to generate
    //HAPPY EASTER
//}

void Leds:: drawCharacter (const int A[3][5])
{
    //drawing A
    //
    int rows_char = 3;//sizeof(A)/ sizeof(A[0]);
    int cols_char = 5;//sizeof(A[0]) / sizeof(A[0][0]);

    for ( int i = 0; i < rows_char; i++ )
        for (int j= 0; j< cols_char; j++ ){
            if (A[i][j] == 1 ){
                lightLED(j,i);
                _delay_ms(1);
                turnOffAllLEDs();
                _delay_ms(1);
            }
        }
}

//draws the currently available buffer
void Leds:: drawBuffer()
{
    for ( int i = 0; i< 5 ; i++ ){
        for ( int j =0 ; j< 10; j++ ) {
            if (buffer[i][j] == 1){
                lightLED(i,j);
                _delay_us(100);
                turnOffLED(i,j);
            }
        }
    }
}

void Leds:: makePattern (int j) 
{
    int start = 0;
    while ( start < buffer_col )
    {
        if ( j >= pattern_col)
            j = 0;
        setColumn( start++, j++ );
        //start ++ ;
        //j++;
        //get all columns from j appending them into buffer
    }
}

void Leds:: setColumn(int buffer_column, int pattern_column )
{
    int column_length = buffer_row;
    for ( int j = 0 ; j < column_length ; j++ ){
        buffer [j][buffer_column] = pattern [j][ pattern_column];
    }
}

void Leds:: drawPattern () 
{
    int dis = 0;
    while (1) 
    {
        if (dis > pattern_col)
            dis = 0;
        makePattern(dis);
        for ( int turns = 0 ; turns <25 ; turns ++ ){
            drawBuffer();
        }
//        _delay_ms(10);
        dis ++;
    }
}
