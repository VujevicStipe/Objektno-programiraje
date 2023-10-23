#include <iostream>

using namespace std;

struct Vektor {
    int* elements;
    int logicalSize;
    int physicalSize;

    Vektor(int initSize) : logicalSize(0), physicalSize(initSize) {
        elements = new int[initSize];
    }

    void vector_new(int initSize) {
        logicalSize = 0;
        physicalSize = initSize;
        elements = new int[initSize];
    }

    void vector_delete() {
        delete[] elements;
        elements = nullptr;
        logicalSize = 0;
        physicalSize = 0;
    }

    void vector_push_back(int val) {
        if (logicalSize == physicalSize) {
            int newCapacity = (physicalSize == 0) ? 1 : 2 * physicalSize;
            int* newElements = new int[newCapacity];

            for (int i = 0; i < logicalSize; i++)
                newElements[i] = elements[i];

            vector_delete();
        }
        elements[logicalSize] = val;
        logicalSize++;
    }

    void vector_pop_back() {
        if (logicalSize > 0)
            logicalSize--;
    }

    int vector_front() {
        if (logicalSize > 0)
            return elements[0];
    }

    int vector_back() {
        if (logicalSize > 0)
            return elements[logicalSize - 1];
    }

    int vector_size() {
        return logicalSize;
    }
};

int main1() {
    Vektor v1(5);

    v1.vector_push_back(10);
    v1.vector_push_back(20);
    v1.vector_push_back(30);

    cout << "vektor: ";
    for (int i = 0; i < v1.vector_size(); i++)
        cout << v1.elements[i] << " ";

    cout << endl;

    cout << "prvi element: " << v1.vector_front() << endl;
    cout << "zadnji element: " << v1.vector_back() << endl;

    v1.vector_pop_back();

    cout << "vektor nakon pop operacije: ";
    for (int i = 0; i < v1.vector_size(); i++)
        cout << v1.elements[i] << " ";

    v1.vector_delete();

    return 0;
}
