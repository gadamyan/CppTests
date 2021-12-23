/*#include <iostream>

#include <assert.h>
#include <map>
#include <limits>


template<class K, class V>
class interval_map {
    friend void IntervalMapTest();
    
private:
    std::map<K,V> m_map;
    
public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    };
    
    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, const V& val ) {
        
        if (!(keyBegin < keyEnd))
        {
            return;
        }
        
        auto endIt = --m_map.upper_bound(keyEnd);
        if (!(endIt->second == val) && endIt->first < keyEnd)
        {
            endIt = m_map.insert(endIt, std::make_pair(keyEnd, endIt->second));
        }
        
        auto beginIt = --m_map.upper_bound(keyBegin);
        if (!(beginIt->second == val))
        {
            if (beginIt->first < keyBegin)
            {
                beginIt = m_map.insert(beginIt, std::make_pair(keyBegin, val));
            }
            else
            {
                if (beginIt != m_map.cbegin() && std::prev(beginIt)->second == val)
                {
                    --beginIt;
                }
                else
                {
                    beginIt->second = val;
                }
            }
        }

        if (beginIt != endIt)
        {
            m_map.erase(std::next(beginIt), endIt);
            
            if (endIt->second == val)
            {
                m_map.erase(endIt);
            }
        }
    }
    
    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};




#include <random>


void IntervalMapTest()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(-10, 15); // distribution in range [1, 6]
    
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 4);
    
    std::uniform_int_distribution<std::mt19937::result_type> dist3(0, 20);
    
    
    interval_map<int, int> testMap(1);
    
    for (int i = 0; i < 10000000; ++i)
    {
        int rand1 = dist1(rng);
        int rand2 = dist1(rng);
        int randVar = dist3(rng);
        if (randVar == 0)
        {
            //rand1 = std::numeric_limits<int>::min();
            //rand2 = std::numeric_limits<int>::max();
        }
        else if (randVar == 1)
        {
            rand1 = std::numeric_limits<int>::min();
        }
        else if (randVar == 2)
        {
            rand2 = std::numeric_limits<int>::max();
        }
        
        if (rand1 < rand2)
        {
            int randNum = dist2(rng);
            testMap.assign(rand1, rand2, randNum);
            auto itBegin = --testMap.m_map.upper_bound(rand1);
            auto itEnd = testMap.m_map.find(rand2);
            if (itEnd == testMap.m_map.end())
            {
                itEnd = testMap.m_map.upper_bound(rand2);
            }
            if (itBegin != testMap.m_map.cbegin())
            {
                assert(itBegin->second != std::prev(itBegin)->second);
            }
            if (itEnd != testMap.m_map.cend())
            {
                assert(randNum != itEnd->second);
            }
            assert(std::next(itBegin) == itEnd);
            assert(itBegin->second == randNum);
            assert(itEnd == testMap.m_map.end() || itEnd->second != randNum);
        }
    }
    
    //testMap.assign(std::numeric_limits<int>::lowest(), 10, 1);
    //testMap.assign(6, 8, 1);
    
    std::cout << std::endl;
}


int convertToInt(const char* str, const int length)
{
    int result = 0;
    const int zeroVal = static_cast<int>('0');
    int counter = 1;
    for (int i = length - 1; i >= 0; --i)
    {
        const int current = static_cast<int>(*(str + i));
        const int value = current - zeroVal;
        if (value < 0 || value > 9)
        {
            return -1;
        }
        result += value  * counter;
        counter *= 10;
    }
    return result;
}

int main(int argc, char* argv[]) {
    //std::cout << convertToInt("1111", 4) << std::endl;
    
    //IntervalMapTest();
    return 0;
}*/






#include <iostream>
#include <string>
#include <regex>
#include <assert.h>

class MyClass1
{
public:
    template <typename T>
    size_t getNiCount(const T* str)
    {
        assert(str != nullptr && "The string is null");
        
        const std::basic_string<T> inputStr(str);
        const char* cStrNi = "Ni";
        const std::basic_string<T> searchStr(cStrNi, cStrNi + strlen(cStrNi));
        
        const std::basic_regex<T> expression(searchStr);
        
        using StringTypeIterator = typename std::basic_string<T>::const_iterator;
        const std::regex_iterator<StringTypeIterator> beginIt(inputStr.begin(), inputStr.end(), expression);
        const std::regex_iterator<StringTypeIterator> endIt;
        
        return static_cast<size_t>(std::distance(beginIt, endIt));
    }

    template <typename T>
    std::basic_string<T> replaceNiWithNI(const T* str)
    {
        assert(str != nullptr && "The string is null");
        
        const std::basic_string<T> inputStr(str);
        const char* cStrNi = "Ni";
        const std::basic_string<T> searchStr(cStrNi, cStrNi + strlen(cStrNi));
        const char* cStrNI = "NI";
        const std::basic_string<T> replaceStr(cStrNI, cStrNI + strlen(cStrNI));
        
        const std::basic_regex<T> expression(searchStr);
        return std::regex_replace(inputStr, expression, replaceStr);
    }
};

#include <iostream>
#include <string>

// in the original solution: regexps may have performance penalty
// please notice usage of getNiString, getNIString


template <typename T>
const T* getNiString() { return "Ni"; }
template <>
const wchar_t* getNiString<wchar_t>() { return L"Ni"; }

template <typename T>
const T* getNIString() { return "NI"; }
template <>
const wchar_t* getNIString<wchar_t>() { return L"NI"; }


class MyClass
{
    
public:
    template <typename T>
    size_t getNiCount(const T* str)
    {
        assert(str != nullptr && "The string is null");
        
        const std::basic_string<T> inputStr = str;
        size_t count = 0;
        size_t pos = 0;
        const size_t searchStrLen = 2;
        
        const T* searchStr = getNiString<T>();
        while (true)
        {
            pos = inputStr.find(searchStr, pos);
            
            if (pos == std::string::npos)
            {
                break;
            }
            
            ++count;
            pos += searchStrLen;
        }
        
        return count;
    }
    
    template <typename T>
    std::basic_string<T> replaceNiWithNI(const T* str)
    {
        assert(str != nullptr && "The string is null");
        
        std::basic_string<T> resultStr = str;
        
        const T* searchStr = getNiString<T>();
        const T* replaceStr = getNIString<T>();
        const size_t searchStrLen = 2;
        size_t pos = 0;
        
        while (true)
        {
            pos = resultStr.find(searchStr, pos);
            
            if (pos == std::string::npos)
            {
                break;
            }
            
            resultStr[pos + 1] = replaceStr[1];
            pos += searchStrLen;
        }
        
        return resultStr;
    }
};

int main(int argc, char* argv[])
{
    const char* szTestString1 = "Ni nI NI nI Ni";
    const wchar_t* szTestString2 = L"Ni nI NI nI Ni";
    
    MyClass myClass;
    
    const size_t niCount1 = myClass.getNiCount(szTestString1);
    const std::string& newString1 = myClass.replaceNiWithNI(szTestString1);
    std::cout << "Found " << niCount1 << " occurrences of Ni. New string: " << newString1 << std::endl;
    
    const size_t niCount2 = myClass.getNiCount(szTestString2);
    const std::wstring& newString2 = myClass.replaceNiWithNI(szTestString2);
    std::wcout << L"Found " << niCount2 << L" occurrences of Ni. New string: " << newString2 << std::endl;
    
    return 0;
}