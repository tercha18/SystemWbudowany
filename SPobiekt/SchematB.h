/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� obiektu "B"                            */
/*  Wej�cia sterownika (wyj�cia obiektu):                                   */
/*    X1..X6 - czujniki przekroczenia poziomu cieczy (0-poni�ej, 1-powy�ej) */
/*  Wyj�cia sterownika (wej�cia obiektu):                                   */
/*    Z1..Z8 - zawory zbiornik�w (0-zamkni�ty, 1-otwarty)                   */
/****************************************************************************/

struct SchemWeX *WeB=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki X1..X7,T)
struct SchemWyX *WyB=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Z1..Z5,M,G)

#define X1	WeB->x1				// G�rny czujnik poziomu cieczy g�rnego zbiornika
#define X2	WeB->x2				// Dolny czujnik poziomu cieczy g�rnego zbiornika
#define X3	WeB->x3				// G�rny czujnik poziomu cieczy lewego dolnego zbiornika
#define X4	WeB->x4				// Dolny czujnik poziomu cieczy lewego dolnego zbiornika
#define X5	WeB->x5				// G�rny czujnik poziomu cieczy prawego dolnego zbiornika
#define X6	WeB->x6				// Dolny czujnik poziomu cieczy prawego dolnego zbiornika

#define Z1	WyB->y1				// Lewy zaw�r g�rnego zbiornika (dop�yw)
#define Z2	WyB->y2				// Prawy zaw�r g�rnego zbiornika (dop�yw)
#define Z3	WyB->y3				// Lewy zaw�r lewego dolnego zbiornika (dop�yw)
#define Z4	WyB->y4				// Prawy zaw�r lewego dolnego zbiornika (dop�yw)
#define Z5	WyB->y5				// Lewy zaw�r prawego dolnego zbiornika (dop�yw)
#define Z6	WyB->y6				// Prawy zaw�r prawego dolnego zbiornika (dop�yw)
#define Z7	WyB->y7				// Zaw�r odp�ywu lewego dolnego zbiornika (odp�yw)
#define Z8	WyB->y8				// Zaw�r odp�ywu prawego dolnego zbiornika (odp�yw)

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
