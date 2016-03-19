
#include "SmartPointerTest.h"
#include "SharedPtr.h"

using namespace SmartPointers;

void SmartPointerTest::test()
{
    test1();
}

void SmartPointerTest::test1()
{
    SharedPtr<int> ptr1(new int(5));
    SharedPtr<int> ptr2(ptr1);
    SharedPtr<int> ptr3 = ptr2;
    *ptr3;
}