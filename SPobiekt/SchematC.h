/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� obiektu "C"                            */
/*  Wej�cia sterownika (wyj�cia obiektu):                                   */
/*    X1..X3 - czujniki przekroczenia poziomu cieczy (0-poni�ej, 1-powy�ej) */
/*    T      - czujnik przekroczenia temperatury (0-poni�ej, 1-powy�ej)     */
/*  Wyj�cia sterownika (wej�cia obiektu):                                   */
/*    Z1..Z5 - zawory zbiornik�w                                            */
/*    M      - mieszanie (0-wy��czone, 1-w��czone)                          */
/*    G      - grzanie (0-wy��czone, 1-w��czone)                            */
/****************************************************************************/

struct SchemWeX *WeC=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki X1..X3,T)
struct SchemWyX *WyC=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Z1..Z5,M,G)

#define X1	WeC->x1				// G�rny czujnik poziomu cieczy lewego g�rnego zbiornika
#define X2	WeC->x2				// Dolny czujnik poziomu cieczy lewego g�rnego zbiornika
#define X3	WeC->x3				// G�rny czujnik poziomu cieczy prawego g�rnego zbiornika
#define T	WeC->x4				// Czujnik temperatury

#define Z1	WyC->y1				// Lewy g�rny zaw�r zbiornika (otwieranie)
#define Z2	WyC->y2				// Lewy g�rny zaw�r zbiornika (zamykanie)
#define Z3	WyC->y3				// Prawy g�rny zaw�r zbiornika (otwieranie)
#define Z4	WyC->y4				// Prawy g�rny zaw�r zbiornika (zamykanie)
#define Z5	WyC->y5				// Dolny zaw�r zbiornika (odp�yw)
#define M	WyC->y6				// Mieszad�o
#define G	WyC->y7				// Grza�ka

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
