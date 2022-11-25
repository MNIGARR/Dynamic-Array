#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
class DynamicArray {
	T* arr = nullptr;
	int size = 0;
public:
	DynamicArray() = default;
	DynamicArray(const DynamicArray& da) {
		if (da.size == 0) {
			arr = nullptr;
			size = 0;
			return;
		}

		arr = new T[da.size];
		size = da.size;

		for (int i = 0; i < size; i++) {
			arr[i] = da.arr[i];
		}
	}

	DynamicArray& operator=(const DynamicArray& da) {
		delete[] arr;
		if (da.size == 0) {
			arr = nullptr;
			size = 0;
			return *this;
		}

		arr = new T[da.size];
		size = da.size;

		for (int i = 0; i < size; i++) {
			arr[i] = da.arr[i];
		}
		return *this;
	}
	T& operator[] (int index) {
		assert(size > 0);
		return arr[index];
	}

	void AddElementToEnd(T element) {
		T* newArr = new T[size + 1];

		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}

		newArr[size] = element;
		delete[] arr;
		size++;
		arr = newArr;
		newArr = nullptr;
	}

	void AddElementToHead(T element) {
		T* newArr = new T[size + 1];
		newArr[0] = element;

		for (int i = 0; i < size; i++) {
			newArr[i + 1] = arr[i];
		}

		delete[] arr;
		size++;
		arr = newArr;
		newArr = nullptr;
	}

	void AddElementByIndex(int index, T element) {
		T* newArr = new T[size + 1];

		for (int i = 0; i < index; i++) {
			newArr[i] = arr[i];
		}

		newArr[index] = element;

		for (int i = index; i < size; i++) {
			newArr[i + 1] = arr[i];
		}

		delete[] arr;
		size++;
		arr = newArr;
		newArr = nullptr;
	}

	void DeleteElementByIndex(int index) {
		T* newArr = new T[size - 1];

		for (int i = 0; i < index; i++) {
			newArr[i] = arr[i];
		}

		for (int i = index + 1; i < size; i++) {
			newArr[i - 1] = arr[i];
		}

		delete[] arr;
		size--;
		arr = newArr;
		newArr = nullptr;
	}


	friend ostream& operator<<(ostream& out, const DynamicArray& obj) {
		for (int i = 0; i < obj.size; i++) {
			out << obj.arr[i] << " ";
		}
		return out;
	}
};

void main() {
	DynamicArray<int> arr;
	arr.AddElementToHead(1);
	arr.AddElementToHead(2);
	arr.AddElementToEnd(13);
	cout << arr;

}