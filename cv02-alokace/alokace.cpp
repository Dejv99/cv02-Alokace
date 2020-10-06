#include "Alokace.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"

void AllocVector(TVector* uk, std::ptrdiff_t delka, double hodnota)
{
	if (uk->iData != nullptr) 
		throw TAllocExc::EFull;
	if (delka <= 0)
		throw TAllocExc::ESize;
	if (uk == nullptr)
		throw TAllocExc::EBadParam;

	uk->iData = new double[delka];

	if (uk->iData == nullptr)
		throw TAllocExc::EMemory;
	
	for (size_t i = 0; (signed)i < delka; i++)
		uk->iData[i] = hodnota;

//	if (uk->iData == nullptr)
//		throw TAllocExc::EMemory;

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