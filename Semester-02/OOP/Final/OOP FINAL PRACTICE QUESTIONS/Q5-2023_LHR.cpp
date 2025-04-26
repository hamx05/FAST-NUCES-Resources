#include <iostream>
#include <string>
using namespace std;

void Test1(int x);
class A
{
    string myWhat;

public:
    A(string str = "Error Occured.") { myWhat = str; }
    virtual string what() { return myWhat; }
};
class B : public A
{
public:
    B(string str = "Error.") : A(str) {}
};
int Test2(int x)
{
    if (x == 50)
        throw B("Exception 50");
    else if (x == 100)
        throw A("Exception 100");
    else if (x == 150)
    {
        string str = "Exception 150";
        throw str;
    }
    else
        return 0;
}
void SomeFunction(int x)
{
    try
    {
        Test1(x);
        cout << "Back in SomeFunction.\n";
    }
    catch (A &ex)
    {
        cout << "SomeFunction A: " << ex.what() << endl;
    }
    catch (B &ex)
    {
        cout << "SomeFunction B: " << ex.what() << endl;
    }
    catch (string &ex)
    {
        cout << "SomeFunction Exception: " << ex << endl;
        throw ex;
    }
    cout << "- - - -\n";
}

void Test1(int x)
{
    if (x == 50)
    {
        try
        {
            Test2(x);
        }
        catch (string &ex)
        {
            cout << "50: Test1 Exception ...\n"
                 << ex << endl;
        }
    }
    else if (x == 100)
    {
        try
        {
            Test2(x);
        }
        catch (B &ex)
        {
            cout << "100: Test1 B ...\n"
                 << ex.what() << endl;
        }
        catch (string &ex)
        {
            cout << "100: Test1 Exception ...\n"
                 << ex << endl;
        }
        catch (A &ex)
        {
            cout << "100: Test1 AAA ...\n"
                 << ex.what() << endl;
        }
    }
    else if (x == 150)
    {
        int *ptr = 0;
        try
        {
            ptr = new int[100];
        }
        catch (B &ex)
        {
            cout << "150: Test1 B ...\n"
                 << ex.what() << endl;
        }
        catch (string &ex)
        {
            cout << "150: Test1 Exception ...\n"
                 << ex << endl;
            throw ex;
        }
        catch (A &ex)
        {
            cout << "150: Test1 AAA ...\n"
                 << ex.what() << endl;
        }
        Test2(x);
        if (ptr)
            delete[] ptr;
    }
    else
    {
        try
        {
            cout << "Else ...\n";
        }
        catch (A &abc)
        {
            cout << "Else: Caught A...\n"
                 << abc.what() << endl;
        }
        catch (B &abc)
        {
            cout << "Else: Caught B...\n"
                 << abc.what() << endl;
        }
    }
    cout << "Test Printing.\n";
}

int main()
{
    // SomeFunction(50);
    // SomeFunction(100);
    SomeFunction(150);
}
