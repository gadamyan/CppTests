#ifndef Solution2_h__
#define Solution2_h__

struct ListNode;

class Solution2
{
private:
    ListNode* createList() const;
    void destroyList(ListNode* head) const;
    void coutList(ListNode* head) const;
    
public:
    void ex1() const;

};

#endif // Solution2_h__
