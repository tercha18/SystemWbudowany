/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "A"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X7 - czujniki przekroczenia poziomu cieczy (0-poni¿ej, 1-powy¿ej) */
/*    T      - czujnik przekroczenia temperatury (0-poni¿ej, 1-powy¿ej)     */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1..Z5 - zawory zbiorników (0-zamkniêty, 1-otwarty)                   */
/*    M      - mieszanie (0-wy³¹czone, 1-w³¹czone)                          */
/*    G      - grzanie (0-wy³¹czone, 1-w³¹czone)                            */
/****************************************************************************/

struct SchemWeX *WeA=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X7,T)
struct SchemWyX *WyA=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Z1..Z5,M,G)

#define X1	WeA->x1				// Górny czujnik poziomu cieczy lewego górnego zbiornika
#define X2	WeA->x2				// Dolny czujnik poziomu cieczy lewego górnego zbiornika
#define X3	WeA->x3				// Górny czujnik poziomu cieczy prawego górnego zbiornika
#define X4	WeA->x4				// Dolny czujnik poziomu cieczy prawego górnego zbiornika
#define X5	WeA->x5				// Górny czujnik poziomu cieczy dolnego zbiornika
#define X6	WeA->x6				// Œrodkowy czujnik poziomu cieczy dolnego zbiornika
#define X7	WeA->x7				// Dolny czujnik poziomu cieczy dolnego zbiornika
#define T	WeA->x8				// Czujnik temperatury

#define Z1	WyA->y1				// Zawór lewego górnego zbiornika (dop³yw)
#define Z2	WyA->y2				// Zawór prawego górnego zbiornika (dop³yw)
#define Z3	WyA->y3				// Zawór lewego górnego zbiornika (odp³yw)
#define Z4	WyA->y4				// Zawór prawego górnego zbiornika (odp³yw)
#define Z5	WyA->y5				// Zawór dolnego zbiornika (odp³yw)
#define M	WyA->y6				// Mieszad³o
#define G	WyA->y7				// Grza³ka

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
