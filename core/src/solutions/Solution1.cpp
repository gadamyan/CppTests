#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>

void ex1()
{
    char str[256];
    bool matched[256] = {false};
    //std::vector<bool> matched(256, false);
    std::cin >> str;

    for (size_t i = 0; i < strlen(str); ++i)
    {
        char var = str[i];
        if (matched[var])
        {
            std::cout << "Found not unique character" << std::endl;
            return;
        }
        matched[var] = true;
    }
    std::cout << "String is unique" << std::endl;
}

void ex2()
{
    char str[256];
    std::cin >> str;

    char* end = str;
    char* start = str;
    char temp;
    if (strlen(str))
    {
        while (*end)
        {
            ++end;
        }
        --end;
        while (start < end)
        {
            temp = *start;
            *start = *end;
            ++start;
            *end = temp;
            --end;
        }
    }
    std::cout << str << std::endl;
}

void ex3()
{
    char str[256];
    std::cin >> str;
    int length = static_cast<int>(strlen(str));
    if (length < 2) return;

    int tail = 1;
    for (int i = 1; i < length; ++i)
    {
        int j = 0;
        for (j = 0; j < tail; ++j)
        {
            if (str[j] == str[i]) break;
        }
        if (j == tail)
        {
            str[tail] = str[i];
            ++tail;
        }
    }
    str[tail] = 0;
    std::cout << str << std::endl;
}

void ex4()
{
    char str[256];
    std::cin >> str;
    int length = static_cast<int>(strlen(str));
    if (length < 2) return;

    int tail = 1;
    bool checks[256] = { false };
    checks[str[0]] = true;

    for (int i = 1; i < length; ++i)
    {
        if (!checks[str[i]])
        {
            checks[str[i]] = true;
            str[tail] = str[i];
            ++tail;
        }
    }
    str[tail] = 0;
    std::cout << str << std::endl;
}

void ex5()
{
    /*char str1[255];
    char str2[255];
    std::cin >> str1;
    std::cin >> str2;
    std::string string1(str1);
    std::string string2(str2);
    std::sort(string1.begin(), string1.end());
    std::sort(string2.begin(), string2.end());
    if (string1 == string2)
    {
        std::cout << "// Strings are Anagrams" << std::endl;
    }
    else
    {
        std::cout << "// Strings are not Anagrams" << std::endl;
    }*/

    char str1[256];
    char str2[256];
    std::cin >> str1;
    std::cin >> str2;
    int str1Size = static_cast<int>(strlen(str1));
    int str2Size = static_cast<int>(strlen(str2));
    bool anagrams = true;
    if (str1Size == str2Size)
    {
        int matched[255] = { 0 };
        int i;
        for (i = 0; i < strlen(str1); ++i)
        {
            ++matched[str1[i]];
        }
        for (i = 0; i < strlen(str2); ++i)
        {
            if (matched[str2[i]] == 0)
            {
                anagrams = false;
            }
            --matched[str2[i]];
        }
    }
    else
    {
        anagrams = false;
    }
    if (anagrams)
    {
        std::cout << "// Strings are Anagrams" << std::endl;
    }
    else
    {
        std::cout << "// Strings are not Anagrams" << std::endl;
    }
}

void ex6()
{
    const char* replStr = "%20";
    const int replStrLen = static_cast<int>(strlen(replStr));
    char str[256];
    std::cin >> str;
    const int len = static_cast<int>(strlen(str));
    int spaceCount = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '_')
        {
            ++spaceCount;
        }
    }
    const int newLen = len + spaceCount * replStrLen;
    int tail = 0;
    char* newStr = new char[newLen + 1];
    for (int i = 0; i < len; ++i)
    {
        if (newStr[i] == '_')
        {
            for (int j = 0; j < replStrLen; ++j)
            {
                newStr[tail] = replStr[j];
                ++tail;
            }
        }
        else
        {
            newStr[tail] = str[i];
            ++tail;
        }
    }
    newStr[tail] = 0;
    std::cout << newStr << std::endl;
    delete[] newStr;
}

void removeElements()
{
    std::string removableStr("c");
    std::vector<std::string> testList = {"a", "b", "c", "d"};
    for (auto it = testList.begin(); it != testList.end(); ++it)
    {
        if (*it == removableStr)
        {
            auto temp = it;
            --it;
            testList.erase(temp);
        }
    }
    for (auto it = testList.begin(); it != testList.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
}

void geometric1()
{
#define PI 3.14159265f
    struct Vec2
    {
        float x, y;
        Vec2(float argX, float argY) { x = argX; y = argY; }
    };

    Vec2 inUpLeft(0.0f, 10.0f);
    Vec2 inBottomRight(10.0f, 0.0f);
    Vec2 inUpRight(10.0f, 10.0f);
    Vec2 inBottomLeft(0.0f, 0.0f);
    float radius = 1.0f;

    float p1 = 2.0f * ((inUpRight.x - inBottomLeft.x) + (inUpRight.y - inBottomLeft.y) + PI * radius);
    float s1 = (inUpRight.x - inBottomLeft.x + 2 * radius) * (inUpRight.y - inBottomLeft.y + 2 * radius)
        - 4.0f * radius * radius * (1 - PI / 4.0f);
    std::cout << "Circumference " << p1 << "\n Area " << s1 << std::endl;
}

template<typename T>
T findMostFrequent(const std::vector<T>& input)
{
    assert(!input.empty() && "Input shouldn't be empty");
    std::map<T, int> itemMap;
    int maxCount = 0;
    T mostFrequent = *input.begin();
    for (const T& item : input)
    {
        if (itemMap.find(item) == itemMap.end())
        {
            itemMap[item] = 1;
        }
        else
        {
            ++itemMap[item];
        }
        const int count = itemMap[item];
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = item;
        }
    }
    return mostFrequent;
}
