#include <iostream>
#include "StackType.cpp"

using namespace std;


bool checkParenthesis(string expr)
{

    StackType <char> s;
    char x;

    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {

            s.Push(expr[i]);
            continue;
        }

        if (s.IsEmpty())
           return false;

        switch (expr[i])
        {
        case ')':


            x = s.Top();
            s.Pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':

            x = s.Top();
            s.Pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':


            x = s.Top();
            s.Pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }


    return (s.IsEmpty());
}

string makeBalance(string expr)
{
     StackType <char> s2;
     StackType <char> s4;

     char a,b,c;

     for (int i=0; i<expr.length(); i++)
    {
         if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {

            s2.Push(expr[i]);
            s4.Push(expr[i]);
            continue;
        }





        switch (expr[i])
        {
        case ')':
           // cout<<"case ')'"<<endl;

            a = s2.Top();
            s2.Pop();
            if (a=='{' )

             {

              s4.Push('}') ;
              s4.Push('(') ;
               s4.Push(')') ;
            }
            else if(a == '[') {
                s4.Push(']');
                s4.Push('(') ;
                s4.Push(')');
            }
            else if(a == '}') {
                s4.Push('(');
                s4.Push(')');
            }
            else if(a == ']') {
                s4.Push('(');
                s4.Push(')');
            }
            else if(a == '(') {
                //s4.Push('(');
                s4.Push(')');
            }



            break;
           //continue;

        case '}':


            b = s2.Top();
             s2.Pop();
            if (b=='(' )

             {

                s4.Push(')');
                s4.Push('{');
                s4.Push('}');


             }
            else if(b =='[') {
                s4.Push(']');
                s4.Push('{');
                s4.Push('}');
            }

             else if(b == ')') {
                s4.Push('{');
                s4.Push('}');
            }
            else if(b == ']') {
                s4.Push('{');
                s4.Push('}');
            }
            else if(b == '{') {

                s4.Push('}');
            }
            break;
          // continue;
//
        case ']':

            //cout<<"case ']'"<<endl;

            c = s2.Top();
            s2.Pop();
            if (c =='(' )
            {

             s4.Push(')');
             s4.Push('[');
             s4.Push(']');
            }
            else if (c == '{' )
            {


                s4.Push('}');
                s4.Push('[');
                s4.Push(']');
            }
             else if(c == '}') {
                s4.Push('[');
                s4.Push(']');
            }
            else if(c == ')') {
                s4.Push('[');
                s4.Push(']');
            }
            else if(c == '[') {

                s4.Push(']');
            }
            break;
//           // continue;
        }




    }
    if(!s2.IsEmpty() && s2.Top() == '(')
    {
        s4.Push(')');
    }
   else if(!s2.IsEmpty() && s2.Top() == '{')
    {
        s4.Push('}');
    }
    else if(!s2.IsEmpty() && s2.Top() == '[')
    {
        s4.Push(']');
    }






    StackType <char> s3;



    cout << "Balanced expression is:   ";

    while(!s4.IsEmpty()){
        s3.Push(s4.Top());
        //cout<<s.Top();
        s4.Pop();
    }
//
     while(!s3.IsEmpty()){

        cout<<s3.Top();
        s3.Pop();
    }

     cout <<endl;



}


string makeBalanceGreedy(string expr)
{
    StackType <char> s10;
    StackType <char> s9;





    //char a[expr.length()];



    for (int i=0; i<expr.length(); i++)
    {
         if (expr[i]== '(')
        {
           // cout<<"before pushing '('" <<endl;
            s10.Push('(');
           // cout<<"after pushing '('" <<endl;

            s10.Push(')');

        }
        else if (expr[i]== '{')
        {
            s10.Push('{');
            s10.Push('}');


        }
          else if (expr[i]== '[')
        {

            s10.Push('[');
            s10.Push(']');

        }
         if (expr[i]== ')') {
            s10.Push('(');
            s10.Push(')');


        }
        else if (expr[i]== '}')
        {
             s10.Push('{');
            s10.Push('}');

        }
          else if (expr[i]== ']')
        {

             s10.Push('[');
            s10.Push(']');

        }



    }


    cout << "Balanced expression  (Greedy approach):   ";

    while(!s10.IsEmpty()){
        s9.Push(s10.Top());
        //cout<<s.Top();
        s10.Pop();
    }
//
      while(!s9.IsEmpty()){

        cout<<s9.Top();
        s9.Pop();
    }

         cout <<endl;

}





int main()
{


    cout<< "Enter your expression: ";

    string expr;
    getline(cin, expr); // get input until enter key is pressed

    cout <<endl;


    if (checkParenthesis(expr))
    {

        cout << "Expression is Balanced" <<endl;
        cout << "Balanced expression :  "<<expr;
        cout <<endl;
        cout <<endl;
    }


    else
    {
        cout <<"Expression is NOT Balanced !!!"<<endl;
        cout <<endl;

        cout <<"      Balanced Expression Output"<<endl;
        cout << " --------------------------------------------"<<endl;
        cout << " --------------------------------------------"<<endl;

        cout <<endl;
        cout <<endl;

        makeBalance(expr);
        cout <<endl;
        makeBalanceGreedy(expr);


        cout <<endl;
        cout <<endl;
        cout<<"Author: 1511960042" <<endl;




    }








    return 0;
}
