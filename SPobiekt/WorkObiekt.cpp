/**********************************************************************************/
/*     Program symulatora SP-841/AVR w wersji do zadañ z Symulatorem Obiektów     */
/**********************************************************************************/
#include "WorkObiekt.h"				// Definicje zmiennych i prototypy funkcji SP841
#include "SchematG.h"				// Definicje wejœæ i wyjœæ obiektu A
#include "Zadania.h"				// Zadania u¿ytkownika

char tim, stan = 1, tim2;
char T_standard = 20, T_break = 10, T_fast = 5, T_unload = 30, T_twoCar = 10, T_nextcar = 7;
int i = 2, j = 2, k = 2;
int cars[8] = { 0,0,0,0,0,0,0,0 };
char stan2 = 3;
char aX1 = 0, aX2 = 0, aX3 = 0, aX4 = 0, aX5 = 0, aX6 = 0, aX7 = 0, aX8 = 0, aX9 = 0, aX10 = 0, aX11 = 0, aX12 = 0, aX13 = 0, aX14 = 0, aX15 = 0, aX16 = 0;
char pX1, pX2, pX3, pX4, pX5, pX6, pX7, pX8, pX9, pX10, pX11, pX12, pX13, pX14, pX15, pX16;
int car_count = 0;
void Set_Sensor();
void Auto_Counting();

void inicjuj(void)					// Inicjowanie programu (jednorazowo przy starcie)
{
}

void AutoDriveOptionOne()
{
	Set_Sensor();
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (X1 || X5) { tim = T_standard; stan = 2; } // start x5 i x1 na 3 auta
		else if (X3 || X7) { tim = T_standard; stan = 4; }
		else if (X2 || X6) { tim = T_standard; stan = 6; }
		else if (X4 || X8) { tim = T_standard; stan = 8; }
		break;
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 3; } // przerwa 1sek
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 4; } // x3 i x7
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		Auto_Counting();
		if (!tim) { stan = 5; tim = T_break; } // przerwa 
		break;
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 6; } // x2 i x6
		break;
	case 6: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 7; } //przerwa 
		break;
	case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 8; } // x4 i x8
		break;
	case 8: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 9; } //przerwa
		break;
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) stan = 1;
		break;
	}
	if (tim) --tim;
}
void AutoDriveOptionTwo()
{
	Set_Sensor();
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (X1 || X2) { tim = T_standard; stan = 2; } // start x1 i x2 na 3 auta
		else if (X5 || X6) { tim = T_standard; stan = 4; }
		else if (X7 || X8) { tim = T_standard; stan = 6; }
		else if (X3 || X4) { tim = T_standard; stan = 8; }
		break;
	case 2: Z1 = 1; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 3; } // przerwa 1sek
		break;
	case 3: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 4; } // x5 i x6
		break;
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { stan = 5; tim = T_break; } // przerwa 
		break;
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 6; } // x7 i x8
		break;
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 7; } //przerwa 
		break;
	case 7: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_standard; stan = 8; } // x4 i x3
		break;
	case 8: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 9; } //przerwa
		break;
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) stan = 1;
		break;
	}
	if (tim) --tim;
}

void AutoDriveOptionFast()
{
	Set_Sensor();
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X1 && X13) || (X5 && X14)) && i) { tim = T_unload; stan = 2; i--; }		// x1 i x5 rozladunek
		else if (!tim && ((X2 && X15) || (X6 && X16)) && i) { tim = T_unload; stan = 3; i--; }	// x2 i x6 rozladunek
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }					// x3 i x7
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }					// x4 i x8
		break;
		// x1 i x5
	case 2: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 4; }
		break;
		// x2 i x6
	case 3: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 5; }
		break;
		// PRZERWA 
	case 4: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X2 && X15) || (X6 && X16)) && i) { tim = T_unload; stan = 3; i--; }
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		//PRZERWA 
	case 5: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X1 && X12) || (X5 && X14)) && i) { tim = T_unload; stan = 2; i--; }
		else if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 7; j--; }
		else if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 6; j--; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// z4 i z8
	case 6: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 8; }
		break;
		// z3 i z7
	case 7: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 9; }
		break;
		//PRZERWA
	case 8: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && (X3 || X7) && j) { tim = T_standard; stan = 10; j--; }
		else if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// PRZERWA
	case 9: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && (X4 || X8) && j) { tim = T_standard; stan = 11; j--; }
		else if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// x3 i x7 
	case 10: Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 12; }
		break;
		// x4 i x8
	case 11: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 12; }
		break;
		//Przerwa
	case 12: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
		// x1 i x5 DWA AUTA
	case 13: Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 15; }
		break;
		// x2 i x6 DWA AUTA
	case 14: Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 16; }
		break;

	case 15: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X2 || X6) && (!X15 && !X16)) && k) { stan = 14; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;

	case 16: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && ((X1 || X5) && (!X13 && !X14)) && k) { stan = 13; k--; tim = T_twoCar; }
		else if (!tim) { stan = 1; j = i = k = 2; }
		break;
	}
	if (tim) --tim;
}

void AutoAdaptiveOption()
{
	Set_Sensor();
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (X1 && X5) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[4] = 1; }
		else if (X1 && !X5 && X2) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[1] = 1; }
		else if (X5 && !X1 && X6) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; cars[5] = 1; }
		else if (X3 && X7) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[6] = 1; }
		else if (X3 && !X7 && X4) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[3] = 1; }
		else if (X7 && !X3 && X8) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; cars[7] = 1; }
		else if (X2 && X6) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; cars[5] = 1; }
		else if (X4 && X8) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; cars[7] = 1; }
		else if (X1 && !cars[0]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (X2 && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (X3 && !cars[2]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (X4 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (X5 && !cars[4]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (X6 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (X7 && !cars[6]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (X8 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		break;
	case 2:Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X1 && !X5) { stan = 10; tim = T_break; }
		if (!tim2 || (X1 || X5)) { tim2 = T_nextcar; }
		break;
	case 3:Z1 = 1; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X1 && !X2) { stan = 10; tim = T_break; }
		if (!tim2 || (X1 || X2)) { tim2 = T_nextcar; }
		break;
	case 4:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X6 && !X5) { stan = 10; tim = T_break; }
		if (!tim2 || (X6 || X5)) { tim2 = T_nextcar; }
		break;
	case 5:Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X3 && !X7) { stan = 10; tim = T_break; }
		if (!tim2 || (X3 || X7)) { tim2 = T_nextcar; }
		break;
	case 6:Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X3 && !X4) { stan = 10; tim = T_break; }
		if (!tim2 || (X3 || X4)) { tim2 = T_nextcar; }
		break;
	case 7:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X7 && !X8) { stan = 10; tim = T_break; }
		if (!tim2 || (X7 || X8)) { tim2 = T_nextcar; }
		break;
	case 8:Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X2 && !X6) { stan = 10; tim = T_break; }
		if (!tim2 || (X6 || X2)) { tim2 = T_nextcar; }
		break;
	case 9:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X4 && !X8) { stan = 10; tim = T_break; }
		if (!tim2 || (X4 || X8)) { tim2 = T_nextcar; }
		break;
	case 10: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim && X1 && X5 && !cars[0] && !cars[4])
		{
			stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[4] = 1;
		}
		else if (!tim && X1 && !X5 && X2 && !cars[0] && !cars[1])
		{
			stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[1] = 1;
		}
		else if (!tim && X5 && !X1 && X6 && !cars[4] && !cars[5])
		{
			stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; cars[5] = 1;
		}
		else if (!tim && X3 && X7 && !cars[2] && !cars[6])
		{
			stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[6] = 1;
		}
		else if (!tim && X3 && !X7 && X4 && !cars[2] && !cars[3])
		{
			stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[3] = 1;
		}
		else if (!tim && X7 && !X3 && X8 && !cars[6] && !cars[7])
		{
			stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; cars[7] = 1;
		}
		else if (!tim && X2 && X6 && !cars[1] && !cars[5])
		{
			stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; cars[5] = 1;
		}
		else if (!tim && (X4 && X8) && !cars[3] && !cars[7])
		{
			stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; cars[7] = 1;
		}
		else if (!tim && X1 && !cars[0]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (!tim && X2 && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (!tim && X3 && !cars[2]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (!tim && X4 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (!tim && X5 && !cars[4]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (!tim && X6 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (!tim && X7 && !cars[6]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (!tim && X8 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		else if (!tim) { stan = 1; for (int i = 0; i < 8; i++) cars[i] = 0; }
		break;
	}
	if (tim) --tim;
	if (tim2)--tim2;
}

void AutoAdaptiveOptionCounting()
{
	Set_Sensor();
	switch (stan)
	{
	case 1: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (X1 && X5) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[4] = 1; }
		else if ((X1 && !X5) && X2) { stan =  3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[1] = 1; }
		else if (X5 && !X1 && X6) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; cars[5] = 1; }
		else if (X3 && X7) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[6] = 1; }
		else if (X3 && !X7 && X4) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[3] = 1; }
		else if (X7 && !X3 && X8) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; cars[7] = 1; }
		else if (X2 && X6) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; cars[5] = 1; }
		else if (X4 && X8) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; cars[7] = 1; }

		else if (X1 && X5 && !cars[0]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (X1 && X2 && !cars[0]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (X1 && !cars[0]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }

		else if ((X2 && X1) && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (X2 && X6 && !cars[1]) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (X2 && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }

		else if (X3 && X7 && !cars[2]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (X3 && X4 && !cars[2]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (X3 && !cars[2]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }

		else if (X4 && X3 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (X4 && X8 && !cars[3]) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (X4 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }

		else if (X5 && X1 && !cars[4]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (X5 && X6 && !cars[4]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (X5 && !cars[4]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }

		else if (X6 && X5 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (X6 && X2 && !cars[5]) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (X6 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }

		else if (X7 && X3 && !cars[6]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (X7 && X8 && !cars[6]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (X7 && !cars[6]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }

		else if (X8 && X7 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		else if (X8 && X4 && !cars[7]) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		else if (X8 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		break;
	case 2:Z1 = 1; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X1 && !X5) { stan = 10; }
		if (!tim2 || (X1 || X5)) { tim2 = T_nextcar; }
		break;
	case 3:Z1 = 1; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X1 && !X2) { stan = 10; }
		if (!tim2 || (X1 || X2)) { tim2 = T_nextcar; }
		break;
	case 4:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 1; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X6 && !X5) { stan = 10; }
		if (!tim2 || (X6 || X5)) { tim2 = T_nextcar; }
		break;
	case 5:Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X3 && !X7) { stan = 10; }
		if (!tim2 || (X3 || X7)) { tim2 = T_nextcar; }
		break;
	case 6:Z1 = 0; Z2 = 0; Z3 = 1; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X3 && !X4) { stan = 10; }
		if (!tim2 || (X3 || X4)) { tim2 = T_nextcar; }
		break;
	case 7:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 1; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X7 && !X8) { stan = 10; }
		if (!tim2 || (X7 || X8)) { tim2 = T_nextcar; }
		break;
	case 8:Z1 = 0; Z2 = 1; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 1; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X2 && !X6) { stan = 10; }
		if (!tim2 || (X6 || X2)) { tim2 = T_nextcar; }
		break;
	case 9:Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 1; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 1;
		Auto_Counting();
		if (!tim) { tim = T_break; stan = 10; }
		if (!tim2 && !X4 && !X8) { stan = 10; }
		if (!tim2 || (X4 || X8)) { tim2 = T_nextcar; }
		break;
	case 10: Z1 = 0; Z2 = 0; Z3 = 0; Z4 = 0; Z5 = 0; Z6 = 0; Z7 = 0; Z8 = 0;
		Auto_Counting();
		if (!car_count && X1 && X5 && !cars[0] && !cars[4])
		{
			stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[4] = 1;
		}
		else if (!car_count && X1 && !X5 && X2 && !cars[0] && !cars[1])
		{
			stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; cars[1] = 1;
		}
		else if (!car_count && X5 && !X1 && X6 && !cars[4] && !cars[5])
		{
			stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; cars[5] = 1;
		}
		else if (!car_count && X3 && X7 && !cars[2] && !cars[6])
		{
			stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 2; cars[6] = 1;
		}
		else if (!car_count && X3 && !X7 && X4 && !cars[2] && !cars[3])
		{
			stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; cars[3] = 1;
		}
		else if (!car_count && X7 && !X3 && X8 && !cars[6] && !cars[7])
		{
			stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; cars[7] = 1;
		}
		else if (!car_count && X2 && X6 && !cars[1] && !cars[5])
		{
			stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; cars[5] = 1;
		}
		else if (!car_count && (X4 && X8) && !cars[3] && !cars[7])
		{
			stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; cars[7] = 1;
		}
		else if (!car_count && X1 && X5 && !cars[0]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (!car_count && X1 && X2 && !cars[0]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }
		else if (!car_count && X1 && !cars[0]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[0] = 1; }

		else if (!car_count && X2 && X1 && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (!car_count && X2 && X6 && !cars[1]) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }
		else if (!car_count && X2 && !cars[1]) { stan = 3; tim = T_standard; tim2 = T_nextcar; cars[1] = 1; }

		else if (!car_count && X3 && X7 && !cars[2]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (!car_count && X3 && X4 && !cars[2]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }
		else if (!car_count && X3 && !cars[2]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[2] = 1; }

		else if (!car_count && X4 && X3 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (!car_count && X4 && X8 && !cars[3]) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }
		else if (!car_count && X4 && !cars[3]) { stan = 6; tim = T_standard; tim2 = T_nextcar; cars[3] = 1; }

		else if (!car_count && X5 && X1 && !cars[4]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (!car_count && X5 && X6 && !cars[4]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }
		else if (!car_count && X5 && !cars[4]) { stan = 2; tim = T_standard; tim2 = T_nextcar; cars[4] = 1; }

		else if (!car_count && X6 && X5 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (!car_count && X6 && X2 && !cars[5]) { stan = 8; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }
		else if (!car_count && X6 && !cars[5]) { stan = 4; tim = T_standard; tim2 = T_nextcar; cars[5] = 1; }

		else if (!car_count && X7 && X3 && !cars[6]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (!car_count && X7 && X8 && !cars[6]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }
		else if (!car_count && X7 && !cars[6]) { stan = 5; tim = T_standard; tim2 = T_nextcar; cars[6] = 1; }

		else if (!car_count && X8 && X7 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		else if (!car_count && X8 && X4 && !cars[7]) { stan = 9; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }
		else if (!car_count && X8 && !cars[7]) { stan = 7; tim = T_standard; tim2 = T_nextcar; cars[7] = 1; }

		else if (!car_count) { stan = 1; for (int i = 0; i < 8; i++) cars[i] = 0; }
		break;
	}
	if (tim) --tim;
	if (tim2)--tim2;
}
void Set_Sensor()
{
	//sprawdzanie stanow na czujnikach
	pX1 = aX1; aX1 = X1;
	pX2 = aX2; aX2 = X2;
	pX3 = aX3; aX3 = X3;
	pX4 = aX4; aX4 = X4;
	pX5 = aX5; aX5 = X5;
	pX6 = aX6; aX6 = X6;
	pX7 = aX7; aX7 = X7;
	pX8 = aX8; aX8 = X8;
	pX9 = aX9; aX9 = X9;
	pX10 = aX10; aX10 = X10;
	pX11 = aX11; aX11 = X11;
	pX12 = aX12; aX12 = X12;
	pX13 = aX13; aX13 = X13;
	pX14 = aX14; aX14 = X14;
	pX15 = aX15; aX15 = X15;
	pX16 = aX16; aX16 = X16;
}
void Auto_Counting()
{
	if (pX1 == 1 && aX1 == 0)
	{
		car_count++;
	}
	if (pX5 == 1 && aX5 == 0)
	{
		car_count++;
	}
	if (pX3 == 1 && aX3 == 0)
	{
		car_count++;
	}
	if (pX7 == 1 && aX7 == 0)
	{
		car_count++;
	}
	if (pX2 == 1 && aX2 == 0)
	{
		car_count++;
	}
	if (pX6 == 1 && aX6 == 0)
	{
		car_count++;
	}
	if (pX4 == 1 && aX4 == 0)
	{
		car_count++;
	}
	if (pX8 == 1 && aX8 == 0)
	{
		car_count++;
	}
	if (pX12 == 1 && aX12 == 0) car_count--;
	if (pX10 == 1 && aX10 == 0) car_count--;
	if (pX11 == 1 && aX11 == 0) car_count--;
	if (pX9 == 1 && aX9 == 0) car_count--;
}



void oblicz(void)					// Kod u¿ytkownika - wykonywany co wCykl [ms]
{
	switch (stan2)
	{
		case 1:AutoDriveOptionOne();
			if (aK1 && !pK1) {
				stan2 = 2; stan = 1;
			}
			else if (aK2 && !pK2) {
				stan2 = 5; stan = 10;
			}
			break;
		case 2: AutoDriveOptionTwo();
			if (aK1 && !pK1) {
			stan2 = 3; stan = 1; tim = T_break;
			}
			else if (aK2 && !pK2) {
			stan2 = 1; stan = 1; tim = T_break;
			}
			break;
		case 3:AutoDriveOptionFast(); if (aK1 && !pK1) {
			stan2 = 4; stan = 10;
			}
			else if (aK2 && !pK2) {
			stan2 = 2; stan = 1; tim = T_break;
			}
			break;
		case 4: AutoAdaptiveOption(); if (aK1 && !pK1) {
			stan2 = 5; stan = 10;
		}
			else if (aK2 && !pK2) {
			stan2 = 3; stan = 1; tim = T_break;
		}
			break;
		case 5: AutoAdaptiveOptionCounting(); if (aK1 && !pK1) {
			stan2 = 1; stan = 1;
		}
			else if (aK2 && !pK2) {
			stan2 = 4; stan = 10;
		}
			break;
	}

	sprintf(buf, "Stan=%d tim=%d", (int)stan, (int)tim2);
	LCD_xy(1, 1); LCD_puts(buf);
	sprintf(buf, "Auta=%d, Tryb=%d", (int)car_count, (int)tim);
	LCD_xy(1, 2); LCD_puts(buf);
	
}



void int_T0(void)					// Przerwanie od T0/T1/T2 wywo³ywane tIntr [ms]
{
}

void WykresyPC()					// Opisy/wartoœci wykresów i zmiennych pomocniczych
{
}
