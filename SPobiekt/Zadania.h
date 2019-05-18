/////////////////////////////////////////////////////////////////////////////////////
// Uwaga! Przed kompilacj� programu dopasowa� do��czany plik #include "Schemat?.h" //
/////////////////////////////////////////////////////////////////////////////////////
int tim1 = 0;
// Program testowy do obiektu "SchematA"
/*
void test_A(void)
{
	Z1 = aK1 ? 1 : 0;				// Otw�rz Z1 je�li naci�ni�ty K1
	Z2 = aK2 ? 1 : 0;				// Otw�rz Z2 je�li naci�ni�ty K2
	Z3 = aK3 ? 1 : 0;				// Otw�rz Z3 je�li naci�ni�ty K3
	Z4 = aK4 ? 1 : 0;				// Otw�rz Z4 je�li naci�ni�ty K4
	Z5 = 0x1 ? 1 : 0;				// Otw�rz Z5
	//M  = 0x1 ? 1 : 0;				// W��cz  M (mieszanie)
	G  = 0x0 ? 1 : 0;				// Wy��cz G (grzanie)
	if(!tim1) {M = !M; tim1=2*T1s;}	// Mieszanie cykliczne

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);

	if(tim1) --tim1;
}*/

////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematB"
void test_B(void)
{
	Z1 = aK1 ? 1 : 0;				// Otw�rz Z1 je�li naci�ni�ty K1
	Z2 = aK2 ? 1 : 0;				// Otw�rz Z2 je�li naci�ni�ty K2
	Z3 = aK3 ? 1 : 0;				// Otw�rz Z3 je�li naci�ni�ty K3
	Z4 = aK4 ? 1 : 0;				// Otw�rz Z4 je�li naci�ni�ty K4
	Z5 = 0x1 ? 1 : 0;				// Otw�rz Z5
	Z6 = 0x1 ? 1 : 0;				// Otw�rz Z6
	Z7 = 0x1 ? 1 : 0;				// Otw�rz Z7
	Z8 = 0x1 ? 1 : 0;				// Otw�rz Z8

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematC"
void test_C(void)
{
	Z1 = aK1 ? 1 : 0;				// Otw�rz Z1 je�li naci�ni�ty K1
	Z2 = aK2 ? 1 : 0;				// Otw�rz Z2 je�li naci�ni�ty K2
	Z3 = aK3 ? 1 : 0;				// Otw�rz Z3 je�li naci�ni�ty K3
	Z4 = aK4 ? 1 : 0;				// Otw�rz Z4 je�li naci�ni�ty K4
	Z5 = 0x1 ? 1 : 0;				// Otw�rz Z5
	M  = 0x1 ? 1 : 0;				// W��cz  M (mieszanie)
	G  = 0x0 ? 1 : 0;				// Wy��cz G (grzanie)

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematD"
void test_D(void)
{
	Z1 = aK1 ? 1 : 0;				// Otw�rz Z1 je�li naci�ni�ty K1
	Z2 = aK2 ? 1 : 0;				// Otw�rz Z2 je�li naci�ni�ty K2

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematE"
void test_E(void)
{
	Z1 = aK1 ? 1 : 0;				// Otw�rz Z1 je�li naci�ni�ty K1
	Z2 = aK2 ? 1 : 0;				// Otw�rz Z2 je�li naci�ni�ty K2

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematF"
char tryb = 1;						// Stan sterownika (AUTO=1/MAN=0)
double r=0.0, u=0.0, y=0.0, e=0.0, um=0;

void test_F(void)
{
	y=(float)Y4/32767;				// Odczyt przetwornika A/C

	if(aK1&&!pK1) u=u>0?0:0.5;		// Prze��czanie trybu pracy regulatora

	U1 = (int)(u*32767);			// Wys�anie na przetwornik C/A
	R = (int)(r*32767);				// Wys�anie na przetwornik C/A

	sprintf(buf,"r=%4.2fu=%4.2fy=%4.2f ",r,u,y);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"%c:  ",tryb?'A':'M');
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////
/*
// Program testowy do obiektu "SchematG"
void test_G(void)
{
	Z1 = Z2 = aK1 ? 1 : 0;				// W��cz Z1 i Z2 je�li naci�ni�ty K1
	Z3 = Z4 = aK2 ? 1 : 0;				// W��cz Z3 i Z4 je�li naci�ni�ty K2
	Z5 = Z6 = aK3 ? 1 : 0;				// W��cz Z5 i Z6 je�li naci�ni�ty K3
	Z7 = Z8 = aK4 ? 1 : 0;				// W��cz Z7 i Z8 je�li naci�ni�ty K4

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}
*/
////////////////////////////////////////////////////////////////////////////////////

// Program testowy do obiektu "SchematH"
void test_H(void)
{
	Z1 = Z2 = aK1 ? 1 : 0;				// W��cz Z1 i Z2 je�li naci�ni�ty K1
	//Z3 = Z4 = aK2 ? 1 : 0;				// W��cz Z3 i Z4 je�li naci�ni�ty K2
	//Z5 = Z6 = aK3 ? 1 : 0;				// W��cz Z5 i Z6 je�li naci�ni�ty K3
	//Z7 = Z8 = aK4 ? 1 : 0;				// W��cz Z7 i Z8 je�li naci�ni�ty K4

	sprintf(buf,"K1=%dK2=%dK3=%dK4=%d ",(int)aK1,(int)aK2,(int)aK3,(int)aK4);
	LCD_xy(1,1); LCD_puts(buf);
	sprintf(buf,"L1=%dL2=%dL3=%dL4=%d ",(int)L1,(int)L2,(int)L3,(int)L4);
	LCD_xy(1,2); LCD_puts(buf);
}

////////////////////////////////////////////////////////////////////////////////////
