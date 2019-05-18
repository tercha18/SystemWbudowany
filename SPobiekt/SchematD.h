/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ obiektu "D"                            */
/*  Wejœcia sterownika (wyjœcia obiektu):                                   */
/*    X1..X4 - czujniki pojazdów (0-brak pojazdu, 1-pojazd pod czujnikiem)  */
/*  Wyjœcia sterownika (wejœcia obiektu):                                   */
/*    Z1, Z2 - sygnalizatory œwietlne przed mostem (0-czerwone, 1-zielone)  */
/****************************************************************************/

struct SchemWeX *WeD=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki X1..X4)
struct SchemWyX *WyD=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Sygnalizatory Z1..Z2)

#define X1	WeD->x1				// Czujnik przed mostem dla kierunku "w lewo"
#define X2	WeD->x2				// Czujnik przed mostem dla kierunku "w prawo"
#define X3	WeD->x3				// Czujnik na moœcie
#define X4	WeD->x4				// Czujnik na moœcie

#define Z1	WyD->y1				// Sygnalizator dla kierunku "w prawo"
#define Z2	WyD->y2				// Sygnalizator dla kierunku "w lewo"

char ile_aWe = 0;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 0;				// Ile zmiennych analogowych w SYM_send()
