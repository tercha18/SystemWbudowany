/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "C"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X3 - czujniki przekroczenia poziomu cieczy (0-poni¿ej, 1-powy¿ej) */
/*    T      - czujnik przekroczenia temperatury (0-poni¿ej, 1-powy¿ej)     */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1..Z5 - zawory zbiorników                                            */
/*    M      - mieszanie (0-wy³¹czone, 1-w³¹czone)                          */
/*    G      - grzanie (0-wy³¹czone, 1-w³¹czone)                            */
/****************************************************************************/

struct SchemWeX *WeC=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X3,T)
struct SchemWyX *WyC=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Z1..Z5,M,G)

#define X1	WeC->x1				// Górny czujnik poziomu cieczy lewego górnego zbiornika
#define X2	WeC->x2				// Dolny czujnik poziomu cieczy lewego górnego zbiornika
#define X3	WeC->x3				// Górny czujnik poziomu cieczy prawego górnego zbiornika
#define T	WeC->x4				// Czujnik temperatury

#define Z1	WyC->y1				// Lewy górny zawór zbiornika (otwieranie)
#define Z2	WyC->y2				// Lewy górny zawór zbiornika (zamykanie)
#define Z3	WyC->y3				// Prawy górny zawór zbiornika (otwieranie)
#define Z4	WyC->y4				// Prawy górny zawór zbiornika (zamykanie)
#define Z5	WyC->y5				// Dolny zawór zbiornika (odp³yw)
#define M	WyC->y6				// Mieszad³o
#define G	WyC->y7				// Grza³ka

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
