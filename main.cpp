#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

bool isNumber(int keyCode){
    return (keyCode >= 48) &&  (keyCode <= 57);
}

int getNumber() {
    int result = 0;
    bool slash = false;
    while (true)
    {
        int keycode = getch();
        if(keycode == 13)
            break;
        
        if(keycode == 8)
            return -1;

        if(keycode == 27)
            return -2;

        if(keycode == 45){
            cout << (char)keycode;
            slash = true;
        }
        else if (isNumber(keycode))
        {
            cout << (char)keycode;
            result = (result * 10) + keycode - 48;
        }
    }
    if(slash) 
        return -2;
    else
        return result;
}

string backSpace(string input)
{
    if(input.find("+") == std::string::npos)
        return "";
    int endPlus = 0;
    while (input.find("+",endPlus+1) != std::string::npos)
    {
        endPlus = input.find("+",endPlus+1);
    }
    return input.substr(0,endPlus);
}

int sum(string numbers)
{
    int sum = 0;
    string b = numbers;
    while (b.find("+") != std::string::npos)
    {
        int pos = b.find("+");
        string n = b.substr(0,pos);
        sum += stoi(n);
        b = b.substr(pos+1,b.size()-pos);
    }
    if (b != "")
    {
        sum += stoi(b);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string numbers;
    while (true)
    {
        system("cls");
        cout << "Numbers: " << numbers << endl;
        cout << "Equal: " << sum(numbers) << endl;
        cout << "Enter a number to add: ";
        int newNumber;
        newNumber = getNumber();

        if(newNumber == -2)
            return 0;
            
        if (newNumber == -1)
        {
            numbers = backSpace(numbers);
        }
        else if(newNumber > 0)
        {
            if(numbers == "")
                numbers += to_string(newNumber);
            else
                numbers += " + " + to_string(newNumber);
        }
    }
    
    return 0;
}
