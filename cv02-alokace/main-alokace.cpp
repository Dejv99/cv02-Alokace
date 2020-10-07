#include "Alokace.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"

using std::cout;

// an EXCEPTION example:
/*
1)	Hozeni vyjimky pomoci klicoveho slova throw - do promenne se ulozi data popisujici chybu.

2)	Odchyceni vyjimky v sekci try - po throw program postupuje predchozimi funkcemi, dokud nenajde sekci try, ktera rika, ze je zajem o reseni vyjimek.
	Pozn.: Pri tomto postupu se volaji destruktory promennych z funkci, kterymi se prochazi.

3)	Vyreseni vyjimky v sekci catch - zde je mozne pracovat s promennou vytvorenou pomoci throw, ktera obsahuje data s popisem chyby a podle techto dat se zachovat.
*/
/*
void Test(std::ptrdiff_t aVelikost) {	// std::ptrdiff_t  <-- specialni datovy typ o velikosti int pro alokaci pameti 
	if (aVelikost < 0)
		throw aVelikost;
	if (aVelikost == 0)
		throw "Hodnota je nula!";
}

void Test1(std::ptrdiff_t aVelikost) {
	Test(aVelikost);
	cout << "Test1 " << '\n';
}

void Test2(std::ptrdiff_t aVelikost) {
	Test1(aVelikost);
	cout << "Test2 " << '\n';
}
*/
int main() {
	cout << "Zacatek programu:" << '\n' << '\n' << std::flush;	// cout << '\n' << std::flush; je to same jako: cout << std::endl;
	try {
	//	Test2(100);

	//	new double[200000000ul];		<---| Chyba pri alokaci
	//	new double[200000000ul];			|
	/*
		int* i = new int;
		delete i;
		
		size_t velikost = 100;
		TVector vector = { 0,0,nullptr };
		
		try {
			vector.iData = new double[2 * velikost];
		}
		catch (std::bad_alloc) { throw TAllocExc::EMemory; }
		
		vector.iSize = velikost;
		vector.iCapacity = 2 * velikost;
		delete[] vector.iData;
		vector.iData = nullptr;
		vector.iCapacity = vector.iSize = 0;
	*/	
		TVector* fp = nullptr;
		TVector vector = { 200,100,nullptr };
		try {
			AllocVector(&vector, vector.iSize, 3);
		}
		
		catch (TAllocExc exception) {
			if (exception == TAllocExc::EBadParam)
				std::cout << "An invalid vector address!" << '\n';
			if (exception == TAllocExc::EFull)
				std::cout << "An already initialized vector!" << '\n';
			if (exception == TAllocExc::EMemory)
				std::cout << "An unsuccessful allocation!" << '\n';
			if (exception == TAllocExc::ESize)
				std::cout << "A vector size must be at least 1!" << '\n';
			exit(1);
		}

		PrintVector(&vector);

		try {
			DeallocVector(&vector);
		}

		catch (TAllocExc exception) {
			if (exception == TAllocExc::EBadParam) {
				std::cout << "Invalid vector address!" << '\n';
				exit(1);
			}
		}

		cout << "end of main " << '\n';
	}

//	catch (std::ptrdiff_t velikost) { cout << "Zaporna velikost! " << velikost << '\n'; }
//	catch (const char* txt) { cout << "Chyba nulove cislo!" << txt << '\n'; }
	catch (...) { cout << "Nejaka nevyresena vyjimka." << '\n'; }	// catch (...) {} odchyti vsechny vyjimky, ktere doted nebyly odchyceny (musi byt zarazen jako posledni)
	cout << "Konec programu." << '\n';

}