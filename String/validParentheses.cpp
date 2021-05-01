#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool valid_paren(string input)
{
    // Declaraing a stack.
    stack<char> s;
    int length = input.length();
    char top;
    // Iterating over the entire string.
    for (int i = 0; i < length; i++)
    {
        //  If the input string contains an opening parenthesis,
        //  push in on to the stack.
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else
        {   // In the case of valid parentheses, the stack cannot be
            // be empty if a closing parenthesis is encountered.
            if (s.empty())
            {
                //cout<<input<<" contains invalid parentheses."<<endl;
                return 0 ;
            }
            else
            {
                top = s.top();
                // If the input string contains a closing bracket,
                // then pop the corresponding opening parenthesis if
                // present.
                if (input[i] == ')' && top == '(' ||
                    input[i] == '}' && top == '{' ||
                    input[i] == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {
                    // The opening and closing parentheses are of
                    // different types. This implies an invaled sequence
                    ////cout<<input<<" contains invalid parentheses."<<endl;
                    return 0;
                }
            }
        }
    }
    //  Checking the status of the stack to determine the
    //  validity of the string.
    if (s.empty())
    {
        //    cout<<input<<" contains valid parentheses."<<endl;
        return 1;
    }
    else
    {
        //    //cout<<input<<" contains invalid parentheses."<<endl;
        return 0;
    }
}


int main() {
 string input1 = "{{}}()[()]";
 string input2 = "{][}";
 string input3 = ")";
 cout<<valid_paren(input1)<<"\n";
 cout<<valid_paren(input2)<<"\n";
 cout<<valid_paren(input3)<<"\n";
 return 0;
}