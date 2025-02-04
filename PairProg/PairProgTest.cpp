// PairProgTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int Sums(int a, int b) {
    return a + b;
}

float Sums(float a, float b) {
    return a + b;
}

string addSpaces(string word) {
    string final = "";
    string temp = "";
    for (char a : word) {
        temp = a;
       //cout << a << " ";
        final.append(temp + " ");
    //    final.append(" ");
       
    }
    return final;
}

int main()
{
   /* float spacer1 = 0;
    float spacer2 = 0;
    std::cout << "input first number: ";
    cin >> spacer1;
    cout << endl;

    cout << "input second number: ";

    cin >> spacer2;

    cout << endl << "the sum of these two numbers is: " << Sums(spacer1, spacer2);
    */
    string word = "";
    cout << "Please enter a string: ";
    cout << endl;
    getline(cin, word);
   cout <<  addSpaces(word);

   //This is to test updating the file in VS and then push to github

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file