#include "Property.hpp"
#include <iostream>

class TestClass
{
public:
    TestClass():_value(3){}
    ~TestClass(){}

    //Read-only property of type int
    Property<int,PropertyDisable> Value = Property<int,PropertyDisable>(
        [&]{return _value;},
        [](PropertyDisable){}
    );

    //Write-only property of type int
    Property<PropertyDisable,int> Index = Property<PropertyDisable,int>(
        []{return PropertyDisable();},
        [&](int x){ _index = x;}
    );

    //Read-write property of type int
    Property<int,int> ID = Property<int,int>(
        [&]{return _id;},
        [&](int x){_id = x+4;}
    );

    void PrintIndex()
    {
        std::cout << "Index = " << _index << std::endl;
    }

private:
    int _value;
    int _index;
    int _id;
};


int main()
{
    TestClass test;

    int x = test.Value;

    //test.Value = x; //causes error since Value is read-only

    std::cout << "x = " << x << std::endl;

    test.Index = x + 2;

    //x = test.Index; //causes error since Index is write-only

    test.PrintIndex();

    //ID is read-write and causes no errors

    test.ID = 8;

    std::cout << "ID = " << test.ID << std::endl;
    
}