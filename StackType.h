#include<iostream>
#include<string>

using namespace std;


class FullStack
{};
class EmptyStack
{};
typedef char ItemType;
const int MAX_ITEM=50;
class StackType{
    
    public:
    StackType();
    bool IsFull() const;
    bool IsEmpty() const;
    void Push(ItemType item);
    void Pop();
    ItemType Top() const;
    
    private:
    int top;
    ItemType items[MAX_ITEM];

};