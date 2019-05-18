/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "B"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X6 - czujniki przekroczenia poziomu cieczy (0-poni¿ej, 1-powy¿ej) */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1..Z8 - zawory zbiorników (0-zamkniêty, 1-otwarty)                   */
/****************************************************************************/

struct SchemWeX *WeB=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X7,T)
struct SchemWyX *WyB=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Z1..Z5,M,G)

#define X1	WeB->x1				// Górny czujnik poziomu cieczy górnego zbiornika
#define X2	WeB->x2				// Dolny czujnik poziomu cieczy górnego zbiornika
#define X3	WeB->x3				// Górny czujnik poziomu cieczy lewego dolnego zbiornika
#define X4	WeB->x4				// Dolny czujnik poziomu cieczy lewego dolnego zbiornika
#define X5	WeB->x5				// Górny czujnik poziomu cieczy prawego dolnego zbiornika
#define X6	WeB->x6				// Dolny czujnik poziomu cieczy prawego dolnego zbiornika

#define Z1	WyB->y1				// Lewy zawór górnego zbiornika (dop³yw)
#define Z2	WyB->y2				// Prawy zawór górnego zbiornika (dop³yw)
#define Z3	WyB->y3				// Lewy zawór lewego dolnego zbiornika (dop³yw)
#define Z4	WyB->y4				// Prawy zawór lewego dolnego zbiornika (dop³yw)
#define Z5	WyB->y5				// Lewy zawór prawego dolnego zbiornika (dop³yw)
#define Z6	WyB->y6				// Prawy zawór prawego dolnego zbiornika (dop³yw)
#define Z7	WyB->y7				// Zawór odp³ywu lewego dolnego zbiornika (odp³yw)
#define Z8	WyB->y8				// Zawór odp³ywu prawego dolnego zbiornika (odp³yw)

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
