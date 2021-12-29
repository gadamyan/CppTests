#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <memory>

class Composite : std::enable_shared_from_this<Composite>
{
public:
    std::weak_ptr<Composite> m_parent;
    std::vector<std::shared_ptr<Composite>> m_children;
    
public:
    
    void addChild(std::shared_ptr<Composite> child)
    {
        child->m_parent = shared_from_this();
        m_children.push_back(child);
    }
};

void testEnableSharedFromThis()
{
    std::shared_ptr<Composite> root;
    std::shared_ptr<Composite> c1;
    std::shared_ptr<Composite> c2;
    root->addChild(c1);
    root->addChild(c2);
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

void removeElements()
{
    char removableStr = 'c';
    std::vector<char> testList = {'a', 'b', 'c', 'd'};
    testList.erase(std::remove(testList.begin(), testList.end(), removableStr), testList.end());
    for (const auto element : testList)
    {
        std::cout << element;
    }
    std::cout << std::endl;
}

void geometric1()
{
    constexpr float PI = 3.14159265f;
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

void findAllThreeElements()
{
    std::vector<int> testList = { 1, 1, 2, 4, 3, 5, 7, 8, 9 };
    const int targetValue = 8;
    std::vector<std::tuple<int, int, int>> indexisTuple;
    const int size = static_cast<int>(testList.size());
    if (size < 3)
    {
        return;
    }
    
    std::sort(testList.begin(), testList.end());
    for (int i = 0; i < size - 2; ++i)
    {
        const int current = testList[i];
        int index1 = i + 1;
        int index2 = size - 1;
        while (index1 < index2)
        {
            const int sum = current + testList[index1] + testList[index2];
            if (sum > targetValue)
            {
                --index2;
            }
            else if (sum < targetValue)
            {
                ++index1;
            }
            else
            {
                indexisTuple.push_back({ i, index1, index2 });
            }
        }
    }
    for (const auto& element : indexisTuple)
    {
        std::cout << std::get<0>(element) << " " << std::get<1>(element) <<
        " " << std::get<2>(element) << std::endl;
    }
}

void wordInDict()
{
    std::set<std::string> dict = { "dog", "god", "foo" };
    const std::string word = "go";
    const std::string& str = *dict.lower_bound(word);
    if (str.compare(0, word.length(), word) == 0)
    {
        std::cout << str << std::endl;
    }
}
