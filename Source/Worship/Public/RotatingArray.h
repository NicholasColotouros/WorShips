/**
	A simple rotating array used to track controller input for cheat codes.
	The implementation is in the .h file due to the template not compiling when I put it in the .cpp

	@author Nicholas Nathan Colotouros
*/

#pragma once
template<class T>
class WORSHIP_API RotatingArray
{
public:
	RotatingArray(int length);
	~RotatingArray();

	void Add(T element);
	T Get(int n);

private:
	TArray<T> *DataArray;
	int Length;
	int StartIndex;
	int EndIndex;
};

/*
 * Implementation, because C++ templates are screwy when these are in separate files.
 */

// Assumes length >= 2
template<class T>
RotatingArray<T>::RotatingArray(int length)
{
	Length = length;
	DataArray = new TArray<T>();
	DataArray->Init(length);
	StartIndex = -1;
	EndIndex = -1;
}

template<class T>
RotatingArray<T>::~RotatingArray()
{
	~DataArray();
}

template<class T>
void RotatingArray<T>::Add(T element)
{
	EndIndex++;
	if (EndIndex == Length)
	{
		EndIndex = 0;
	}

	if (StartIndex == EndIndex)
	{
		StartIndex++;
		if (StartIndex == Length)
		{
			StartIndex = 0;
		}
	}
	(*DataArray)[EndIndex] = element;

	// First inserted element
	if (StartIndex == -1)
	{
		StartIndex++;
	}
}

// Assumes 0 <= n < Length
// Length -1 is the oldest element
// 0 is the most recent element
template<class T>
T RotatingArray<T>::Get(int n)
{
	int index = n + StartIndex;
	while (index >= Length)
	{
		index -= Length;
	}
	return DataArray->GetData()[index];
}

