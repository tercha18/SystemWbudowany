/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "G"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X16 - czujniki pojazdów (0-brak pojazdu, 1-pojazd pod czujnikiem) */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1, Z8  - sygnalizatory œwietlne (0-czerwone, 1-zielone)              */
/****************************************************************************/

struct SchemWeX *WeG=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X16)
struct SchemWyX *WyG=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Sygnalizatory Z1..Z8)

#define X1	WeG->x1				// Czujnik X1
#define X2	WeG->x2				// Czujnik X2
#define X3	WeG->x3				// Czujnik X3
#define X4	WeG->x4				// Czujnik X4
#define X5	WeG->x5				// Czujnik X5
#define X6	WeG->x6				// Czujnik X6
#define X7	WeG->x7				// Czujnik X7
#define X8	WeG->x8				// Czujnik X8
#define X9	WeG->x9				// Czujnik X9
#define X10	WeG->x10			// Czujnik X10
#define X11	WeG->x11			// Czujnik X11
#define X12	WeG->x12			// Czujnik X12
#define X13	WeG->x13			// Czujnik X13
#define X14	WeG->x14			// Czujnik X14
#define X15	WeG->x15			// Czujnik X15
#define X16	WeG->x16			// Czujnik X16

#define Z1	WyG->y1				// Sygnalizator Z1
#define Z2	WyG->y2				// Sygnalizator Z2
#define Z3	WyG->y3				// Sygnalizator Z3
#define Z4	WyG->y4				// Sygnalizator Z4
#define Z5	WyG->y5				// Sygnalizator Z5
#define Z6	WyG->y6				// Sygnalizator Z6
#define Z7	WyG->y7				// Sygnalizator Z7
#define Z8	WyG->y8				// Sygnalizator Z8

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
