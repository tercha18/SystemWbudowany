/****************************************************************************/
/*  Definicje oznacze� wej�� i wyj�� analogowych i binarnych obiektu "F"    */
/*  Wej�cia regulatora (wyj�cia obiektu):                                   */
/*    Y1 - warto�� sygna�u przed pierwszym cz�onem inercyjnym [0..32767]    */
/*    Y2 - warto�� sygna�u po pierwszym cz�onie inercyjnym [0..32767]       */
/*    Y3 - warto�� sygna�u po drugim cz�onie inercyjnym [0..32767]          */
/*    Y4 - warto�� sygna�u po cz�onie op�nienia [0..32767]                 */
/*  Wyj�cia regulatora (wej�cia obiektu):                                   */
/*    U1 - sterowanie (wyj�cie regulatora/wej�cie obiektu) [0..32767]       */
/*    Z1 - zwi�kszanie warto�ci (+)                                         */
/*    Z2 - zmniejszanie warto�ci (-)                                        */
/****************************************************************************/

struct SchemWeX *WeF=(struct SchemWeX *)bWe;	// Wej�cia binarne (Czujniki)
struct SchemWyX *WyF=(struct SchemWyX *)bWy;	// Wyj�cia binarne (Z1,Z2)

#define Y1	aWe[0]				// Wyj�cie Y1 obiektu
#define Y2	aWe[1]				// Wyj�cie Y2 obiektu
#define Y3	aWe[2]				// Wyj�cie Y3 obiektu
#define Y4	aWe[3]				// Wyj�cie Y4 obiektu

#define U1	aWy[0]				// Wej�cie U1 obiektu
#define R	aWy[1]				// Warto�� zadana uk�adu regulacji

#define Z1	WyF->y1				// Zwi�kszanie warto�ci (+)
#define Z2	WyF->y2				// Zmniejszanie warto�ci (-)

char ile_aWe = 4;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 2;				// Ile zmiennych analogowych w SYM_send()
