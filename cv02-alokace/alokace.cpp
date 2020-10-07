#include "Alokace.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"
/*
void AllocMatrix(TVector* matrix, std::ptrdiff_t rows, std::ptrdiff_t lenght, double value) {

}
*/
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
	
	for (size_t i = 0; (signed)i < lenght; i++)
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