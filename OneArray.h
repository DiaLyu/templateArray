#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class OneArray {
private:
    size_t len;
    T* arr;

public:
    OneArray() : len(0) {}

    OneArray(size_t len) {
        if (len == 0)
            throw string("The number of elements must be greater than 0");
        assign(len);
    }

    OneArray(const OneArray& data){
        if (data.len != 0) {
            assign(data.len);
            for (size_t i = 0; i < data.len; i++) {
                arr[i] = data[i];
            }
        }
        else
            len = data.len;
    }

    // initializing and filling the array
    void assign(size_t count) {
        if (count == 0)
            throw "The array cannot be initialized";
        len = count;
        arr = new T[count];
        for (size_t i = 0; i < len; i++)
            arr[i] = 0;
    }

    void writeRand() {
        if (len == 0)
            throw string("The array is not initialized");
        srand(time(NULL));
        for (size_t i = 0; i < len; i++)
            arr[i] = (T)(1 + rand() % 100);
    }

    // Index Access
    T getElem(size_t index) {
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index >= len)
            throw string("The index goes outside the array");
        return *(arr + index);
    } 

    T& operator[] (size_t index){
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index >= len)
            throw string("The index goes outside the array");
        return *(arr + index);
    }

    const T& operator[] (size_t index) const {
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index >= len)
            throw string("The index goes outside the array");
        return *(arr + index);
    }

    void setElem(size_t index, T elem) {
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index >= len)
            throw string("The index goes outside the array");
        arr[index] = elem;
    }

    friend bool operator == (const OneArray<T>& data1, const OneArray<T>& data2) {
        if (&data1 != &data2) { 
            if (data1.len == data2.len) {
                bool is_equal = true;
                for (size_t i = 0; i < data1.len; i++)
                    if (data1[i] != data2[i])
                        is_equal = false;
                return is_equal;
            }
            else return false;
        }
        return true;
    }

    friend bool operator !=(const OneArray<T>& data1, const OneArray<T>& data2) {
        return !(data1 == data2);
    }

    OneArray<T>& operator= (const OneArray<T>& data) {
        if (data.len == 0)
            clear();
        else {
            len = data.len;
            arr = new T[len];
            for (size_t i = 0; i < data.len; i++)
                arr[i] = data[i];
        }
        return *this;
    }

    // Number of elements
    size_t getLength() {
        return len;
    }

    //  an interface that implements the concept of iterators
    class Iterator {

        T* elem;

    public:

        Iterator(T* first) {
            this->elem = first;
        }

        T& operator+ (int n) { return *(elem + n); }
        T& operator- (int n) { return *(elem - n); }

        T& operator++ (int) { return *elem++; }
        T& operator-- (int) { return *elem--; }
        T& operator++ () { return *++elem; }
        T& operator-- () { return *--elem; }

        bool operator!= (const Iterator& it) { return elem != it.elem; }
        bool operator== (const Iterator& it) { return elem == it.elem; }
        T& operator* () { return *elem; }
    };

    Iterator begin() { return arr; }
    Iterator end() { return arr + len; }

    // changing the size (decreasing, increasing the size)
    void changeLength(size_t change) {
        if (len + change <= 0) {
           clear();
        }
        else {
            size_t oldLen = len;
            len += change;

            T* oldArr = new T[oldLen];
            for (size_t i = 0; i < oldLen; i++) {
                *(oldArr + i) = *(arr + i);
            }
            arr = new T[len];

            if (len > oldLen)
                for (size_t i = 0; i < len; i++) {
                    if (i >= oldLen)
                        *(arr + i) = 0;
                    else
                        *(arr + i) = *(oldArr + i);
                }
            else
                for (int i = 0; i < len; i++) {
                    *(arr + i) = *(oldArr + i);
                }

            delete[] oldArr;
        }
    }

    // ������� ��������� � ������������ �������
    void addIndexArr(size_t index, T elem) {
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index > len)
            throw string("The index goes outside the array");
        T* newArr = new T[len + 1];
        size_t addIndex = 0;
        for (size_t i = 0; i < len + 1; i++) {
            if (index == i)
                *(newArr + i) = elem;
            else {
                *(newArr + i) = *(arr + addIndex);
                addIndex++;
            }
        }
        len += 1;
        arr = new T[len];
        for (size_t i = 0; i < len; i++) {
            *(arr + i) = *(newArr + i);
        }
        delete[] newArr;
    }

    // Deleting Elements
    void delIndexArr(size_t index) {
        if (len == 0)
            throw string("The array is not initialized");
        if (index < 0 || index >= len)
            throw string("The index goes outside the array");
        if (len == 0)
            throw "The array is empty";

        T* newArr = new T[len - 1];
        size_t addIndex = 0;
        for (size_t i = 0; i < len; i++) {
            if (index != i) {
                *(newArr + addIndex) = *(arr + i);
                addIndex++;
            }
        }
        len -= 1;
        arr = new T[len];
        for (size_t i = 0; i < len; i++) {
            *(arr + i) = *(newArr + i);
        }
        delete[] newArr;

        if (len == 0) {
            delete[] arr;
        }
    }

    friend void swap(OneArray<T>& obj, OneArray<T>& obj1) {

        swap(obj.len, obj1.len);
        swap(obj.arr, obj1.arr);
    }

    // cleaning the array
    void clear() {
        if (len == 0)
            throw string("The array has already been cleared");
        len = 0;
        delete[] arr;
    }

    ~OneArray() {
        if (len != 0)
            delete[] arr;
    }
};

