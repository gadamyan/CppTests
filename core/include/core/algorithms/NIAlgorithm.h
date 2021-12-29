//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <cassert>

namespace cpptests::core::algorithms {
    template <typename T>
    size_t getNiCount(const T* str)
    {
        assert(str != nullptr && "The string is null");
        
        const std::basic_string<T> inputStr(str);
        const char* cStrNi = "Ni";
        const std::basic_string<T> searchStr(cStrNi, cStrNi + strlen(cStrNi));
        
        const std::basic_regex<T> expression(searchStr, std::regex_constants::icase);
        
        std::match_results<typename std::basic_string<T>::const_iterator> mresult;
        std::regex_search(inputStr.begin(), inputStr.end(), mresult, expression, std::regex_constants::match_any);
        return mresult.size();
        
        
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
    
    void test()
    {
        const char* szTestString1 = "Ni nI NI nI Ni";
        const wchar_t* szTestString2 = L"Ni nI NI nI Ni";
        
        const size_t niCount1 = getNiCount(szTestString1);
        const std::string& newString1 = replaceNiWithNI(szTestString1);
        std::cout << "Found " << niCount1 << " occurrences of Ni. New string: " << newString1 << std::endl;
        
        const size_t niCount2 = getNiCount(szTestString2);
        const std::wstring& newString2 = replaceNiWithNI(szTestString2);
        std::wcout << L"Found " << niCount2 << L" occurrences of Ni. New string: " << newString2 << std::endl;
    }
}