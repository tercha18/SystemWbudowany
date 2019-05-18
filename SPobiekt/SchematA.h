/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� obiektu "A"                            */
/*  Wej�cia sterownika (wyj�cia obiektu):                                   */
/*    X1..X7 - czujniki przekroczenia poziomu cieczy (0-poni�ej, 1-powy�ej) */
/*    T      - czujnik przekroczenia temperatury (0-poni�ej, 1-powy�ej)     */
/*  Wyj�cia sterownika (wej�cia obiektu):                                   */
/*    Z1..Z5 - zawory zbiornik�w (0-zamkni�ty, 1-otwarty)                   */
/*    M      - mieszanie (0-wy��czone, 1-w��czone)                          */
/*    G      - grzanie (0-wy��czone, 1-w��czone)                            */
/****************************************************************************/

struct SchemWeX *WeA=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki X1..X7,T)
struct SchemWyX *WyA=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Z1..Z5,M,G)

#define X1	WeA->x1				// G�rny czujnik poziomu cieczy lewego g�rnego zbiornika
#define X2	WeA->x2				// Dolny czujnik poziomu cieczy lewego g�rnego zbiornika
#define X3	WeA->x3				// G�rny czujnik poziomu cieczy prawego g�rnego zbiornika
#define X4	WeA->x4				// Dolny czujnik poziomu cieczy prawego g�rnego zbiornika
#define X5	WeA->x5				// G�rny czujnik poziomu cieczy dolnego zbiornika
#define X6	WeA->x6				// �rodkowy czujnik poziomu cieczy dolnego zbiornika
#define X7	WeA->x7				// Dolny czujnik poziomu cieczy dolnego zbiornika
#define T	WeA->x8				// Czujnik temperatury

#define Z1	WyA->y1				// Zaw�r lewego g�rnego zbiornika (dop�yw)
#define Z2	WyA->y2				// Zaw�r prawego g�rnego zbiornika (dop�yw)
#define Z3	WyA->y3				// Zaw�r lewego g�rnego zbiornika (odp�yw)
#define Z4	WyA->y4				// Zaw�r prawego g�rnego zbiornika (odp�yw)
#define Z5	WyA->y5				// Zaw�r dolnego zbiornika (odp�yw)
#define M	WyA->y6				// Mieszad�o
#define G	WyA->y7				// Grza�ka

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
