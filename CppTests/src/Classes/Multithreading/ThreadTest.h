//
//  ThreadTest.h
//  MainApp
//
//  Created by Gevorg Adamyan on 1/16/16.
//  Copyright © 2016 Gevorg Adamyan. All rights reserved.
//

#ifndef ThreadTest_h
#define ThreadTest_h

#include <mutex>
#include <memory>

namespace MainThreading {
    
    class ThreadTest
    {
    private:
        void threadFunction(const int i, std::shared_ptr<std::mutex> mutex);
    public:
        void test();
        void test1();
        void test2();
        void test3();
        void test4();
        void deadlock();
    };
};

#endif /* ThreadTest_h */
