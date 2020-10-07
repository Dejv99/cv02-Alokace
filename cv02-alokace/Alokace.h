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

//void AllocMatrix(TVector* matrix, std::ptrdiff_t rows, std::ptrdiff_t lenght, double value);
void AllocVector(TVector* vector, std::ptrdiff_t lenght, double value);
void DeallocVector(TVector* vector);
void PrintVector(TVector* vector);