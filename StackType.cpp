#include "StackType.h"

StackType::StackType()
//Function: Class constructors
//Pre: N/A
//Post: will active an array and initialized top =-1
{
    top =-1;
}

bool StackType::IsEmpty() const
//Function: Determine whether the stack is empty
//Pre: Stack has been initialize
//Post: Function value =(Stack is empty)
{
    return(top==-1);
}

bool StackType::IsFull() const
//Function: Determine whether stack is full
//Pre: Stack has been initialized.
//Post: Function value =(Stack is full)
{
    return (top == MAX_ITEM -1 );
}

void StackType::Push(ItemType newItem)
//Function: Adds newItem to the top of Stack
//Pre: Stack has been initialized.
//Post: If(stack is full), exception EmptyStack is thrown, 
//else newItem is at the top of the stack.
{
    if(IsFull())
        throw FullStack();
    top++;
    items[top] = newItem;
}

void StackType::Pop()
//Function: Removes top item from the stack.
//Pre: Stack has been initialized.
//Post: If stack is empty, exception EmptyStack is thrown, 
//else top element has been removed from stack.
{
    if(IsEmpty())
        throw EmptyStack();
    top--;

}

ItemType StackType::Top() const
//Function: return a copy of the top item on the stack.
//Pre: Stack has been intialized
//Post: If stack is empty, exception EmptyStack is thrown, 
//else a copy of the top elements is return.
{
    if(IsFull())
        throw FullStack();
    return items[top];
}


