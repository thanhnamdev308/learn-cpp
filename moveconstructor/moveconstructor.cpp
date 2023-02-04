// rule_of_five.cpp
#include <stdlib.h>

#include <iostream>

class MyMovableClass {
   private:
    int _size;
    int *_data;

   public:
    // constructor
    MyMovableClass(size_t size) {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this
                  << " allocated with size = " << _size * sizeof(int)
                  << " bytes" << std::endl;
    }

    // 1 : destructor
    ~MyMovableClass() {
        std::cout << "DELETING instance of MyMovableClass at " << this
                  << std::endl;
        delete[] _data;
    }

    // 2 : copy constructor
    MyMovableClass(const MyMovableClass &source) {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source
                  << " to instance " << this << std::endl;
    }

    // 3 : copy assignment operator
    MyMovableClass &operator=(const MyMovableClass &source) {
        std::cout << "ASSIGNING content of instance " << &source
                  << " to instance " << this << std::endl;
        if (this == &source) return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    // 4 : move constructor
    MyMovableClass(MyMovableClass &&source) {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance "
                  << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    // 5 : move assignment operator
    MyMovableClass &operator=(MyMovableClass &&source) {
        std::cout << "MOVING (assign) instance " << &source << " to instance "
                  << this << std::endl;
        if (this == &source) return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

void useObject(MyMovableClass obj) {
    std::cout << "using object " << &obj << std::endl;
}

int main() {
    MyMovableClass obj1(100);  // constructor

    useObject(std::move(obj1));

    return 0;
}
