
#pragma once

template <typename T>
class vector {
	T* array;
	size_t size_;
	size_t capacity = 16;
public:

	size_t size() const { return size_; }

	vector() {
		array = new T[capacity];
		size_ = 0;
	}

	vector(const vector& v) {
		capacity = v.capacity;
		size_ = v.size_;
		array = new T[capacity];
		for (size_t i = 0; i < size_; i++) {
			array[i] = v.array[i];
		}
	}

	T& front() const {
		if (size_ == 0)
			throw "no element";
		return array[0];
	}

	void push_back(const T& a) {
		if (size_ == capacity) {
			expansion();
			//push_back(a);
		}
		array[size_] = a;
		size_ += 1;
	}

	void expansion() {
		capacity *= 2;
		T* array_ = new T[capacity];
		for (size_t i = 0; i < size_; i++) {
			array_[i] = array[i];
		}
		delete[] array;
		array = array_;
	}

	T& operator[](size_t i) {
		if (i >= size_ || i < 0)
			throw "indexfailure";
		return array[i];
	}

	T operator[](size_t i) const {
		if (i >= size_ || i < 0)
			throw "indexfailure";
		return array[i];
	}

	~vector() {
		delete[] array;
	}

};

