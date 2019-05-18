/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� obiektu "D"                            */
/*  Wej�cia sterownika (wyj�cia obiektu):                                   */
/*    X1..X4 - czujniki pojazd�w (0-brak pojazdu, 1-pojazd pod czujnikiem)  */
/*  Wyj�cia sterownika (wej�cia obiektu):                                   */
/*    Z1, Z2 - sygnalizatory �wietlne przed mostem (0-czerwone, 1-zielone)  */
/****************************************************************************/

struct SchemWeX *WeD=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki X1..X4)
struct SchemWyX *WyD=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Sygnalizatory Z1..Z2)

#define X1	WeD->x1				// Czujnik przed mostem dla kierunku "w lewo"
#define X2	WeD->x2				// Czujnik przed mostem dla kierunku "w prawo"
#define X3	WeD->x3				// Czujnik na mo�cie
#define X4	WeD->x4				// Czujnik na mo�cie

#define Z1	WyD->y1				// Sygnalizator dla kierunku "w prawo"
#define Z2	WyD->y2				// Sygnalizator dla kierunku "w lewo"

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
