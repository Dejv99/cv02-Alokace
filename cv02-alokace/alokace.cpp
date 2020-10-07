#include "Alokace.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"


// -------------------VECTOR------------------- //

void AllocVector(TVector* vector, std::ptrdiff_t lenght, double value)
{
	if (vector == nullptr)
		throw TAllocExc::EBadParam;
	if (vector->iData != nullptr) 
		throw TAllocExc::EFull;
	if (lenght <= 0)
		throw TAllocExc::ESize;
	//int a = lock_alloc(1);				// Jak predat klic?
	vector->iData = new double[lenght];
	//unlock_alloc(a);
	if (vector->iData == nullptr)
		throw TAllocExc::EMemory;

	vector->iSize = lenght;
	vector->iCapacity = 2 * lenght;
	for (std::ptrdiff_t i = 0; i < lenght; i++)
		vector->iData[i] = value;
}

void DeallocVector(TVector* vector)
{
	if (vector == nullptr || vector->iData == nullptr)
		throw TAllocExc::EBadParam;

	delete[] vector->iData;
	vector->iData = nullptr;
}

void PrintVector(TVector* vector)
{
	if (vector == nullptr)
		throw TAllocExc::EBadParam;

	for (size_t i = 0; i < vector->iSize; i++)
		std::cout << vector->iData[i] << " ";
	std::cout << '\n';
}


// -------------------MATRIX------------------- //

void AllocMatrix(TVector** matrix, std::ptrdiff_t rows, std::ptrdiff_t lenght, double value) {
	if (matrix == nullptr || rows <= 0)
		throw TAllocExc::EBadParam;
	if (lenght <= 0)
		throw TAllocExc::ESize;

	*matrix = new TVector[rows];
	for (std::ptrdiff_t i = 0; i < rows; i++)
		((*matrix)[i]).iData = nullptr;

	for (std::ptrdiff_t i = 0; i < rows; i++)
		AllocVector(&((*matrix)[i]), lenght, value);

	if ((*matrix)->iData == nullptr)
		throw TAllocExc::EMemory;
}

void DeallocMatrix(TVector* matrix, std::ptrdiff_t rows) {
	if (matrix == nullptr || rows <= 0)
		throw TAllocExc::EBadParam;

	for (std::ptrdiff_t i = 0; i < rows; i++)
		delete[]((matrix[i]).iData);	// Dealokace vsech radku
	delete[] matrix;					// Dealokace "zakladniho" sloupce, ktery obsahuje adresy vsech radku
	matrix = nullptr;
}

void PrintMatrix(TVector* matrix, std::ptrdiff_t rows)
{
	if (matrix == nullptr || rows <= 0)
		throw TAllocExc::EBadParam;

	for (std::ptrdiff_t i = 0; (signed)i < rows; i++) {
		for (size_t j = 0; j < (matrix[i]).iSize; j++)
			std::cout << (matrix[i]).iData[j] << " ";
		std::cout << '\n';
	}
	std::cout << '\n';	
}