#define _CRT_SECURE_NO_DEPRECATE 
int  wCykl=500;							// Czas cyklu dla funkcji oblicz(), np. 100[ms]
char tIntr=4;							// Interwa� czasu pomi�dzy przerwaniami od T0 [ms]
char typPanelu=1;						// Typ panelu: 0=>SP-841, 1=>SP-AVR
char fTekstury=0;						// Czy rysowa� tekstury? (1=Tak, 0=Nie)
char fTablWart=0;						// Czy rysowa� tablic� wart.? (1=Tak, 0=Nie)
char fWykresy=0;						// Czy rysowa� wykresy? (1=Tak, 0=Nie)
char buf[64];							// Bufor komunikat�w wy�wietlacza LCD

#include <stdio.h>

typedef unsigned char bit;

#define aWe_MAX		16
#define aWy_MAX		16

extern bit K1,K2,K3,K4,K5,K6,K7,K8;		// Klawisze K1..K8
extern bit L1,L2,L3,L4,L5,L6,L7,L8,BUZ;	// Diody L1..L8, BUZzer
char aK1,aK2,aK3,aK4,aK5,aK6,aK7,aK8;	// Aktualny stan klawisza K1..K8
char pK1,pK2,pK3,pK4,pK5,pK6,pK7,pK8=0;	// Poprzedni stan klawisza K1..K8
extern unsigned char bWe[2],bWy[2];		// Wej�cia i wyj�cia binarne obiektu
extern unsigned int aWe[aWe_MAX];		// Tablica wej�� analogowych obiektu
extern unsigned int aWy[aWy_MAX];		// Tablica wyj�� analogowych obiektu

extern float aWykres[6];				// Wy�wietlane warto�ci wielko�ci analogowych
extern char  bWykres[12];				// Wy�wietlane warto�ci wielko�ci binarnych
extern int   iZmienna[8];				// Wy�wietlane warto�ci zmiennych pomocniczych
extern char  *bNazwa[12];				// Tablica nazw wielko�ci analogowych
extern char  *aNazwa[6];				// Tablica nazw wielko�ci binarnych
extern char  *iNazwa[8];				// Tablica nazw zmiennych pomocniczych
extern void LCD_xy(char x, char y);		// Ustawienie kursora na wy�wietlaczu LCD
extern void LCD_putch(char znak);		// Wy�wietlenie znaku na wy�wietlaczu LCD
extern void LCD_puts(char *tablica_LCD);// Wy�wietlenie �a�cucha znak�w na wy�wietlaczu LCD
extern int  get_KBD();					// Odczyt stanu klawiszy K1..K4
extern void set_LED(int val);			// Wy�wietlenie stanu diod LED
extern char SYM_send(void);				// Odczyt komunikatu z symulatora obiekt�w
extern char SYM_read(void);				// Wys�anie komunikatu do symulatora obiekt�w
extern void oblicz(void);				// Funkcja z programem u�ytkownika
void KEY_read(void)
{
	aK1=!K1; aK2=!K2; aK3=!K3; aK4=!K4;	// Aktualny stan klawiszy K1..K4
	aK5=!K5; aK6=!K6; aK7=!K7; aK8=!K8;	// Aktualny stan klawiszy K5..K8
}
void KEY_mem(void)						// Zapami�tanie stanu klawiszy
{
	pK1 = aK1; pK2 = aK2; pK3 = aK3; pK4 = aK4;
	pK5 = aK5; pK6 = aK6; pK7 = aK7; pK8 = aK8;
}
void LED_set(void)
{}

void work(void)
{
	KEY_read();
	oblicz();
	LED_set();
	KEY_mem();
	SYM_send();							// Wy�lij komunikat do symulatora obiekt�w
	SYM_read();							// Odczytaj komunikat z symulatora obiekt�w
}
struct SchemWeX				// Struktura wej�� binarnych obiekt�w
{
	unsigned int x1  : 1;
	unsigned int x2  : 1;
	unsigned int x3  : 1;
	unsigned int x4  : 1;
	unsigned int x5  : 1;
	unsigned int x6  : 1;
	unsigned int x7  : 1;
	unsigned int x8  : 1;
	unsigned int x9  : 1;
	unsigned int x10 : 1;
	unsigned int x11 : 1;
	unsigned int x12 : 1;
	unsigned int x13 : 1;
	unsigned int x14 : 1;
	unsigned int x15 : 1;
	unsigned int x16 : 1;
};

struct SchemWyX				// Struktura wyj�� binarnych obiekt�w
{
	unsigned int y1  : 1;
	unsigned int y2  : 1;
	unsigned int y3  : 1;
	unsigned int y4  : 1;
	unsigned int y5  : 1;
	unsigned int y6  : 1;
	unsigned int y7  : 1;
	unsigned int y8  : 1;
	unsigned int y9  : 1;
	unsigned int y10 : 1;
	unsigned int y11 : 1;
	unsigned int y12 : 1;
	unsigned int y13 : 1;
	unsigned int y14 : 1;
	unsigned int y15 : 1;
	unsigned int y16 : 1;
};
