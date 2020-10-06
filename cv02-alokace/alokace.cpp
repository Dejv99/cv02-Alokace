#include "Alokace.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"

void AllocVector(TVector* uk, std::ptrdiff_t delka, double hodnota)
{
	if (uk != nullptr) 
		throw TAllocExc::EFull;

	if (delka <= 0)
		throw TAllocExc::ESize;

	uk->iData = new double[delka];
	if (uk == nullptr)
		throw TAllocExc::EBadParam;

	if (uk->iData == nullptr)
		throw TAllocExc::EMemory;

	for (size_t i = 0; i < delka; i++)
		uk->iData[i] = hodnota;
}
