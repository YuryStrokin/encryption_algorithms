
#include "cRC4.h"

// Конструктор. Генерирует sBox на основе представленного ключа.
CRC4::CRC4(unsigned char* pKey, unsigned int lenKey)
{
	Initialize(pKey, lenKey);
}

// Конструктор без аргуементов. Инициализация sBox вручную. 
            
CRC4::CRC4()
{}


void CRC4::Initialize(unsigned char* pKey, unsigned int lenKey)
{
	// Инициализируйте поле подстановки на основе предоставленного ключа.

	b = 0;

	for (a = 0; a < 256; a++)
	{
		m_sBox[a] = a;
	}

	for (a = 0; a < 256; a++)
	{
		b = (b + m_sBox[a] + pKey[a % lenKey]) % 256;
		swap = m_sBox[a];
		m_sBox[a] = m_sBox[b];
		m_sBox[b] = swap;
	}
}


void CRC4::RC4(unsigned char pData[], unsigned long lenData)
{
	int sBox[256];
	int i = 0, j = 0;
	long Offset;

	// Создаем локальную копию ключа. 
	memcpy(sBox, m_sBox, 256 * sizeof(int));

	// Зашифровка данных. 
	for (Offset = 0; Offset < lenData; Offset++)
	{
		i = (i + 1) % 256;
		j = (j + sBox[i]) % 256;
		swap = sBox[i];
		sBox[i] = sBox[j];
		sBox[j] = swap;
		pData[Offset] ^= sBox[(sBox[i] + sBox[j]) % 256];
	}
}


// Сохранение функции в отдельной строке 
string CRC4::RC4Str(unsigned char* pInputData, unsigned long InputSize)
{
	string sInputOutputData((char*)pInputData, InputSize);
	RC4((unsigned char*)sInputOutputData.c_str(), InputSize);
	return sInputOutputData;
}