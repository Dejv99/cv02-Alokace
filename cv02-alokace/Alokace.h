
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