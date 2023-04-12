#include <iostream>
#include <ostream>
#include <string>
#include "OneArray.h"

using namespace std;

int main()
{
    OneArray<float> art;
    cout << art.getLength() << endl;

    art.assign(7);

    setlocale(LC_ALL, "Russian");
    OneArray<float> arr(10);
    OneArray<float> arr1(7);

    OneArray<float> test(arr);

    cout << "arr[2] = " << arr.getElem(2) << endl;
    cout << "Length arr = " << arr.getLength() << endl;
    
    auto it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }
    cout << "----- changeLength -----" << endl;
    arr.changeLength(6);
    arr.changeLength(-8);
    cout << "Length arr = " << arr.getLength() << endl;

    it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }

    cout << "----- addIndexArr ------" << endl;
    arr.addIndexArr(4, 12);
    cout << "Length arr = " << arr.getLength() << endl;
    it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }
    arr[2] = 3.9;

    cout << "----- = ------" << endl;
    test = arr;
    cout << "Length arr = " << test.getLength() << endl;
    it = OneArray<float>::Iterator(test.begin());
    while (it != test.end()) {
        cout << *it << endl;
        it++;
    }

    cout << "----- = ------" << endl;
    it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }

    cout << "----- delIndexArr ------" << endl;
    arr.delIndexArr(8);
    arr.delIndexArr(7);
    arr.delIndexArr(6);
    arr.delIndexArr(5);
    arr.delIndexArr(4);
    arr.delIndexArr(3);
    arr.delIndexArr(2);
    arr.delIndexArr(1);
    arr.delIndexArr(0);
    cout << "Length arr = " << arr.getLength() << endl;
    it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }

    cout << "----- addIndexArr ------" << endl;
    try {
        arr.addIndexArr(0, 12);
        cout << "Length arr = " << arr.getLength() << endl;
        it = OneArray<float>::Iterator(arr.begin());
        while (it != arr.end()) {
            cout << *it << endl;
            it++;
        }
    }
    catch (string str) {
        cout << str << endl;
    }

    cout << "----- swap ------" << endl;
    swap(arr, arr1);
    cout << "Length arr = " << arr.getLength() << endl;
    it = OneArray<float>::Iterator(arr.begin());
    while (it != arr.end()) {
        cout << *it << endl;
        it++;
    }

    return 0;
}




