/****************************************************************************/
/*  Definicje oznaczeñ wejœæ i wyjœæ analogowych i binarnych obiektu "F"    */
/*  Wejœcia regulatora (wyjœcia obiektu):                                   */
/*    Y1 - wartoœæ sygna³u przed pierwszym cz³onem inercyjnym [0..32767]    */
/*    Y2 - wartoœæ sygna³u po pierwszym cz³onie inercyjnym [0..32767]       */
/*    Y3 - wartoœæ sygna³u po drugim cz³onie inercyjnym [0..32767]          */
/*    Y4 - wartoœæ sygna³u po cz³onie opóŸnienia [0..32767]                 */
/*  Wyjœcia regulatora (wejœcia obiektu):                                   */
/*    U1 - sterowanie (wyjœcie regulatora/wejœcie obiektu) [0..32767]       */
/*    Z1 - zwiêkszanie wartoœci (+)                                         */
/*    Z2 - zmniejszanie wartoœci (-)                                        */
/****************************************************************************/

struct SchemWeX *WeF=(struct SchemWeX *)bWe;	// Wejœcia binarne (Czujniki)
struct SchemWyX *WyF=(struct SchemWyX *)bWy;	// Wyjœcia binarne (Z1,Z2)

#define Y1	aWe[0]				// Wyjœcie Y1 obiektu
#define Y2	aWe[1]				// Wyjœcie Y2 obiektu
#define Y3	aWe[2]				// Wyjœcie Y3 obiektu
#define Y4	aWe[3]				// Wyjœcie Y4 obiektu

#define U1	aWy[0]				// Wejœcie U1 obiektu
#define R	aWy[1]				// Wartoœæ zadana uk³adu regulacji

#define Z1	WyF->y1				// Zwiêkszanie wartoœci (+)
#define Z2	WyF->y2				// Zmniejszanie wartoœci (-)

char ile_aWe = 4;				// Ile zmiennych analogowych w SYM_read()
char ile_aWy = 2;				// Ile zmiennych analogowych w SYM_send()
