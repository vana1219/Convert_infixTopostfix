#include"StackType.cpp"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


int precedence(char op){
    if(op=='-'||op=='+')
        return 1;
    if(op=='*'||op=='/')
        return 2;
    return 0;
}

bool isOperator(char ch){
    return (ch =='+' || ch =='-' || ch =='*' || ch == '/');   
}

int main()
{
    ofstream outFile("inFix_postFix.txt");
    StackType Stack;
    string PostFix;
    string inFix;
    cout<<"Enter your InFix: "<<endl;
    getline(cin, inFix);
    outFile<<inFix;
    outFile<<"\n";
    int len;
    len = inFix.length();
    int i, j;
    for(i=0,j=0;i<len; i++){
        char item;
        item = inFix[i];
        if(isalpha(item)){
            PostFix[j]= item;
            j++;
            outFile<<"Item is operand. Push it to PostFix\n";
            }   
        else if(item=='('){
            Stack.Push(item);
            outFile<<"Item is '('. Push it to Stack\n";
            }
        else if(item==')'){
            outFile<<"Item is ')'. Will pop all operators inside the parenthese until '('\n";
            while(Stack.Top()!='('){
                PostFix[j]=Stack.Top();
                j++;
                Stack.Pop();
            Stack.Pop();
            break;
            }

        }
        else if(isOperator(item)){
            if(Stack.IsEmpty()){
                outFile<<"Stack is empty. Push operator into Stack\n";
                Stack.Push(item);
                }
            else
            {
                if(precedence(item)>precedence(Stack.Top())){
                    Stack.Push(item);
                    outFile<<"Stack is not Empty. Operator is being add to Stack\n";
                }
                else 
                    {
                    while(precedence(item)<=precedence(Stack.Top())){
                        PostFix[j]=Stack.Top();
                        j++;
                        outFile<<"Stack is not Empty.Operators in Stack is being add to PostFix\n ";
                        Stack.Pop();
                        
                    }
                    Stack.Push(item);
                    outFile<<"Add new operator to Stack\n";
                
                }
            }
        }
    }
    outFile<<"Done scaned. All operators inside Stack is now being add to PostFix\n";    
    while(!Stack.IsEmpty()){
        PostFix[j]= Stack.Top();
        j++;
        Stack.Pop();
    }
    outFile<<"Printing PostFix....\n";
    cout<<"PostFix is: \n";
    for(int k=0; k<j; k++){
        cout<<PostFix[k];
    }
    cout<<"\n";
    
    outFile.close();
    return 0;
}





