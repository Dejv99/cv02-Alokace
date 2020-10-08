#include <iostream>

const double value = 3;
const std::ptrdiff_t rows = 3;
const std::ptrdiff_t size = 6;

struct TVector {
	size_t iCapacity = 0;		//
	size_t iSize = 0;			// Inicializace v definici
	double* iData = nullptr;	//
};

enum class TAllocExc
{
	ESize,
	EMemory,
	EBadParam,
	EFull
};

// -------------------VECTOR------------------- //
void AllocVector(TVector* vector, std::ptrdiff_t lenght, double value);
void PrintVector(TVector* vector);
void DeallocVector(TVector* vector);

// -------------------MATRIX------------------- //
void AllocMatrix(TVector** matrix, std::ptrdiff_t rows, std::ptrdiff_t lenght, double value);
void PrintMatrix(TVector* matrix, std::ptrdiff_t rows);
void DeallocMatrix(TVector* matrix, std::ptrdiff_t rows);
