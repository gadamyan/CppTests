
#ifndef SmartPointerTest_h
#define SmartPointerTest_h


template<typename T>
class P
{
};

class M : public P<int>
{
};

namespace SmartPointers {
    
    class SmartPointerTest
    {
    public:
        void test();
        void test1();
    };
};

#endif /* SmartPointerTest_h */
