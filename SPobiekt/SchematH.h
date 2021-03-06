/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� obiektu "H"                            */
/*  Wej�cia sterownika (wyj�cia obiektu):                                   */
/*    X1..X16 - czujniki pojazd�w (0-brak pojazdu, 1-pojazd pod czujnikiem) */
/*  Wyj�cia sterownika (wej�cia obiektu):                                   */
/*    Z1, Z8  - sygnalizatory �wietlne (0-czerwone, 1-zielone)              */
/****************************************************************************/

struct SchemWeX *WeH=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki X1..X16)
struct SchemWyX *WyH=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Sygnalizatory Z1..Z8)

#define X1	WeH->x1				// Czujnik X1
#define X2	WeH->x2				// Czujnik X2
#define X3	WeH->x3				// Czujnik X3
#define X4	WeH->x4				// Czujnik X4
#define X5	WeH->x5				// Czujnik X5
#define X6	WeH->x6				// Czujnik X6
#define X7	WeH->x7				// Czujnik X7
#define X8	WeH->x8				// Czujnik X8
#define X9	WeH->x9				// Czujnik X9
#define X10	WeH->x10			// Czujnik X10
#define X11	WeH->x11			// Czujnik X11
#define X12	WeH->x12			// Czujnik X12
#define X13	WeH->x13			// Czujnik X13
#define X14	WeH->x14			// Czujnik X14
#define X15	WeH->x15			// Czujnik X15
#define X16	WeH->x16			// Czujnik X16

#define Z1	WyH->y1				// Sygnalizator Z1
#define Z2	WyH->y2				// Sygnalizator Z2
#define Z3	WyH->y3				// Sygnalizator Z3
#define Z4	WyH->y4				// Sygnalizator Z4
#define Z5	WyH->y5				// Sygnalizator Z5
#define Z6	WyH->y6				// Sygnalizator Z6
#define Z7	WyH->y7				// Sygnalizator Z7
#define Z8	WyH->y8				// Sygnalizator Z8
#define Z9 WyH->y9
#define Z10 WyH->y9
#define Z11 WyH->y9

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
