/**********************************************************************************/
/*     Program symulatora SP-841/AVR w wersji do zadañ z Symulatorem Obiektów     */
/**********************************************************************************/
#include "WorkObiekt.h"				// Definicje zmiennych i prototypy funkcji SP841
#include "SchematG.h"				// Definicje wejœæ i wyjœæ obiektu A
#include "Zadania.h"				// Zadania u¿ytkownika

char tim, stan = 1;
char T_standard = 15, T_break = 10, T_fast = 5, T_unload = 20, T_twoCar = 10;;
char option=1;
int car_count = 0;
int i = 2, j = 2, k = 2;
void inicjuj(void)					// Inicjowanie programu (jednorazowo przy starcie)
{
}

void AutoDriveOptionOne()
{
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X1 || X5) { tim = T_standard; stan = 2; } // start x5 i x1 na 3 auta
		break;
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 3; } // przerwa 1sek
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X3 | X7)) { tim = T_standard; stan = 4; } // x3 i x7
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		if (!tim) {	stan = 5; tim = T_break;	} // przerwa 
		break;
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X2 || X6)) { tim = T_standard; stan = 6; } // x2 i x6
		break;
	case 6: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 7; } //przerwa 
		break;
	case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X4 || X8)) { tim = T_standard; stan = 8; } // x4 i x8
		break;
	case 8: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		if (!tim) { tim = T_break; stan = 9; } //przerwa
		break;
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) stan = 1;
		break;
	}
	if (tim) --tim;
}
void AutoDriveOptionTwo()
{
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X1 || X2) { tim = T_standard; stan = 2; } // start x1 i x2 na 3 auta
		break;
	case 2: Z1 = 1; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 3; } // przerwa 1sek
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X5 || X6)) { tim = T_standard; stan = 4; } // x5 i x6
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { stan = 5; tim = T_break; } // przerwa 
		break;
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X7 || X8)) { tim = T_standard; stan = 6; } // x7 i x8
		break;
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 1;
		if (!tim) { tim = T_break; stan = 7; } //przerwa 
		break;
	case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X3 || X4)) { tim = T_standard; stan = 8; } // x4 i x8
		break;
	case 8: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 9; } //przerwa
		break;
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) stan = 1;
		break;
	}
	if (tim) --tim;
}

void AutoDriveOptionFast()
{
	switch (stan)
	{ 
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X1 && X13) || (X5 && X14)) && i) { tim = T_unload; stan = 2; i--; }		// x1 i x5 rozladunek
		else if (!tim && ((X2 && X15) || (X6 && X16)) && i) { tim = T_unload; stan = 3; i--; }	// x2 i x6 rozladunek
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }					// x3 i x7
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }					// x4 i x8
		break;
		// x1 i x5
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 4; }
		break;
		// x2 i x6
	case 3: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 5; }
		break;
		// PRZERWA 
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X2 && X15) || (X6 && X16)) && i) { tim = T_unload; stan = 3; i--; }
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }
		else if (!tim) { stan = 1; j = i = k= 2; }
		break;
		//PRZERWA 
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X1 && X12) || (X5 && X14)) && i) { tim = T_unload; stan = 2; i--; }
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }
		else if (!tim) { stan = 1; j = i = k= 2; }
		break;
		// z4 i z8
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		if (!tim) { tim = T_break; stan = 8; }
		break;
		// z3 i z7
	case 7: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		if (!tim) { tim = T_break; stan = 9; }
		break;
		//PRZERWA
	case 8: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 10; j--; }
		else if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// PRZERWA
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 11; j--; }
		else if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// x3 i x7 
	case 10: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		if (!tim) { tim = T_break; stan = 12; }
		break;
		// x4 i x8
	case 11: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		if (!tim) { tim = T_break; stan = 12; }
		break;
		//Przerwa
	case 12: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// x1 i x5 DWA AUTA
	case 13: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		if(!tim) { tim = T_break; stan = 15; }
		break;
		// x2 i x6 DWA AUTA
	case 14: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = T_break; stan = 16; }
		break;

	case 15: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;

	case 16: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
	}
	if (tim) --tim;
}



void oblicz(void)					// Kod u¿ytkownika - wykonywany co wCykl [ms]
{
	//AutoDriveOptionOne();
	//AutoDriveOptionTwo();
	AutoDriveOptionFast();
	sprintf(buf, "Stan=%d tim=%d", (int)stan, (int)tim, (int)i, (int)j);
	LCD_xy(1, 1); LCD_puts(buf);
	sprintf(buf, " i=%d, j=%d, k=%d", (int)i, (int)j, (int)k);
	LCD_xy(1, 2); LCD_puts(buf);
}



void int_T0(void)					// Przerwanie od T0/T1/T2 wywo³ywane tIntr [ms]
{
}

void WykresyPC()					// Opisy/wartoœci wykresów i zmiennych pomocniczych
{
}

void test_old()
{
	switch (stan) {
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if ((!X5 && !X6) || (!X2 && !X1)) { tim = 50; stan = 15; }
		else if (!X1 && !X5) { tim = 50; stan = 4; }
		else if (X1 || X5) { tim = 50; stan = 2; }
		break;
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 50; stan = 3; }
		else if (X13 || X14) { tim = 100; stan = 13; }
		break;
	case 3: Z1 = 0; Z2 = 2; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 4; }
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X2 || X6) { tim = 50; stan = 5; }
		else if (!X2 && !X6) { tim = 50; stan = 7; }
		break;
	case 5: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 50; stan = 6; }
		else if (X15 || X16) { tim = 100; stan = 14; }
		break;
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 7; }
		break;
	case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X3 || X2) { tim = 50; stan = 8; }
		else if (!X3 && !X2) { tim = 50; stan = 10; }
		break;
	case 8: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		if (!tim) { tim = 50; stan = 9; }
		break;
	case 9:  Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 10; }
		break;
	case 10: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X4 || X8) { tim = 50; stan = 11; }
		else if (!X4 && !X8) { tim = 50; stan = 1; }
		break;
	case 11: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		if (!tim) { tim = 50; stan = 12; }
		break;
	case 12:  Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 1; }
		break;
	case 13: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 50; stan = 3; }
		break;
	case 14: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 50; stan = 6; }
		break;
	case  15: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!X5 && !X6) { tim = 50; stan = 16; }
		else if (!X1 && !X2) { tim = 50; stan = 18; }
		break;
	case 16: Z1 = 1; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 50; stan = 17; }
		break;
	case 17: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 18; }
		break;
	case 18: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		if (X5 || X6) { tim = 50; stan = 19; }
		else if (!X5 && !X6) { tim = 50; stan = 6; }
		break;
	case 19: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 1; Z7 = 0; Z8 = 0;
		if (!tim) { tim = 70; stan = 6; }
		break;
	}if (tim) --tim;
}