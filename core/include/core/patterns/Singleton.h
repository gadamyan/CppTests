//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

namespace cpptests::core::patterns {

class GlobalsSingleton {
public:
    GlobalsSingleton(const GlobalsSingleton&) = delete;
    GlobalsSingleton& operator =(const GlobalsSingleton&) = delete;

    static GlobalsSingleton& getInstance() {
        return sInstance;
    }

    int getInt() const {
        return mValue;
    }

    void setInt(int value) {
        mValue = value;
    }
private:
    GlobalsSingleton() = default;

private:
    int mValue = 0;
    static GlobalsSingleton sInstance;
};

GlobalsSingleton GlobalsSingleton::sInstance;

}
