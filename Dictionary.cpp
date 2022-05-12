#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

template <class T, class U >
class Dictionary {
public:
	int Lengh() {
		return _Length;
	}
	void Added(T Key, U Value)
	{
		AddedP(&Key, &Value);
	}
	void Read() {
		for (int i = 0; i < _Length; i++) {
			cout << *_Key[i] << " , " << *_Value[i] << endl;
		}
	}
	U Key(T key)
	{
		for (int i = 0; i < _Length; i++)
		{
			if (*_Key[i] == key) {
				return *_Value[i];
			}
		}
	}
	T Value(U key)
	{
		for (int i = 0; i < _Length; i++)
		{
			if (*_Value[i] == key) {
				return *_Key[i];
			}
		}
	}
	void Remove(T RKey) {
		RemoveP(&RKey);
	}
	~Dictionary() {
		delete _Key;
		delete _Value;
	}
private:
	int _Length = 0;
	T** _Key;
	U** _Value;

	void RemoveP(T* PKey) {

		_Length = _Length - 1;
		T** RKey = _Key;
		U** RValue = _Value;
		_Key = new T * [_Length];
		_Value = new U * [_Length];
		for (int i = 0, j = 0; i < _Length + 1; i++)
		{
			if (*RKey[i] != *PKey) {
				_Key[j] = RKey[i];
				_Value[j] = RValue[i];
				j++;
			}
			else {
				free(RKey[i]);
			}
		}
		free(RKey);
		free(RValue);
	}
	void AddedP(T* KeyVal, U* ValueVal) {
		_Length++;

		if (_Length > 1) {
			if (Control(KeyVal, ValueVal)) {
				T** TKey = _Key;
				U** TValue = _Value;
				_Key = new T * [_Length];
				_Value = new U * [_Length];

				for (int i = 0; i < _Length; i++) {
					_Key[i] = TKey[i];
					_Value[i] = TValue[i];
				}
				_Key[_Length - 1] = KeyAddedP(KeyVal);
				_Value[_Length - 1] = ValueAddedP(ValueVal);
				free(TKey);
				free(TValue);
			}
			else {
				_Length--;
			}
		}
		else {
			_Key = new T * [1];
			_Value = new U * [1];

			_Key[0] = KeyAddedP(KeyVal);
			_Value[0] = ValueAddedP(ValueVal);
		}
	}
	bool Control(T* CKey, U* CValue) {
		for (int i = 0; i < _Length - 1; i++) {
			if (*_Key[i] == *CKey || *_Value[i] == *CValue) {
				return false;
			}
		}
		return true;
	}
	T* KeyAddedP(T* Key) {
		T* KeyPoint = new T[1];
		*KeyPoint = *Key;
		return KeyPoint;
	}
	U* ValueAddedP(U* Value) {
		U* ValuePoint = new U[1];
		*ValuePoint = *Value;
		return ValuePoint;
	}
};

int main()
{

	Dictionary<int, string> sozluk;
	sozluk.Added(1, "aa");
	sozluk.Added(2, "bb");
	sozluk.Added(3, "cc");
	sozluk.Added(4, "dd");
	sozluk.Added(5, "ee");
	sozluk.Added(6, "fdf");
	sozluk.Added(7, "sad");
	sozluk.Added(8, "asd");

	sozluk.Remove(2);
	sozluk.Read();

	cout << sozluk.Key(1);


}

