#include <iostream>

struct TVector {
	size_t iCapacity;
	size_t iSize;
	double* iData;
};

enum class TAllocExc
{
	ESize,
	EMemory,
	EBadParam,
	EFull
};

void AllocVector( TVector *uk, std::ptrdiff_t delka, double hodnota );
void DeallocVector(TVector* vector);
void PrintVector(TVector* vector);