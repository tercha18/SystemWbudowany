/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "E"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X4 - czujniki pojazdów (0-brak pojazdu, 1-pojazd pod czujnikiem)  */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1, Z2 - sygnalizatory œwietlne (0-czerwone, 1-zielone)               */
/****************************************************************************/

struct SchemWeX *WeE=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X8)
struct SchemWyX *WyE=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Sygnalizatory Z1..Z4)

#define X1	WeE->x1				// Czujnik X1
#define X2	WeE->x2				// Czujnik X2
#define X3	WeE->x3				// Czujnik X3
#define X4	WeE->x4				// Czujnik X4
#define X5	WeE->x5				// Czujnik X5
#define X6	WeE->x6				// Czujnik X6
#define X7	WeE->x7				// Czujnik X7
#define X8	WeE->x8				// Czujnik X8

#define Z1	WyE->y1				// Sygnalizator Z1 (dla kierunku "góra-dó³"
#define Z2	WyE->y2				// Sygnalizator Z2 (dla kierunku "prawo-lewo")

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
