#include <iostream>
#include <cassert>
using namespace std;

class Drob   //Task1
{
    int numerator;
    int denominator;
public:
    Drob(int Numerator = 0, int Denominator = 1)
    {
        assert(denominator != 0);
        numerator = Numerator;
        denominator = Denominator;
    }
    void sum(Drob x)
    {
        if (denominator == x.denominator)
        {
            cout << "Sum of fractions =  " << numerator + x.numerator;
            cout << "/" << denominator << endl;
            return;
        }
        cout << "Sum of fractions =  " << numerator * x.denominator + x.numerator * denominator;
        cout << "/" << denominator * x.denominator << endl;
    }
    void subtraction(Drob x)
    {
        if (denominator == x.denominator)
        {
            cout << "Subtracting fractions =  " << numerator - x.numerator;
            cout << "/" << denominator << endl;
            return;
        }
        cout << "Subtracting fractions =  " << numerator * x.denominator - x.numerator * denominator;
        cout << "/" << denominator * x.denominator << endl;
    }
    void product(Drob x)
    {
        cout << "Product of fractions =  " << numerator * x.numerator;
        cout << "/" << denominator * x.denominator << endl;
    }
    void divide(Drob x)
    {
        cout << "Divide of fractions =  " << numerator * x.denominator;
        cout << "/" << denominator * x.numerator << endl;
    }
};

class Contact       //Task2
{
    char* name;
    char* lastname;
    char* surname;
    char* phoneNumber;
public:
    Contact() 
    {
        name = nullptr;
        lastname = nullptr;
        surname = nullptr;
        phoneNumber = nullptr;
    }
    Contact(const char* Name, const char* LastName, const char* Surname, const char* PhoneNumber) 
    {
        name = new char[strlen(Name) + 1];
        strcpy_s(name, strlen(Name) + 1, Name);
        lastname = new char[(strlen(LastName) + 1)];
        strcpy_s(lastname, strlen(LastName) + 1, LastName);
        surname = new char[(strlen(Surname) + 1)];
        strcpy_s(surname, strlen(Surname) + 1, Surname);
        phoneNumber = new char[(strlen(PhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(PhoneNumber) + 1, PhoneNumber);

    }
    void Set()
    {
        char bufferName[30];
        char bufferLastName[30];
        char bufferSurname[30];
        char bufferPhoneNumber[30];

        cout << "Enter the name: ";
        cin >> bufferName;
        cout << "Enter your lastname: ";
        cin >> bufferLastName;
        cout << "Enter your surname: ";
        cin >> bufferSurname;
        cout << "Enter your phonenumber: ";
        cin >> bufferPhoneNumber;

        name = new char[strlen(bufferName) + 1];
        strcpy_s(name, strlen(bufferName) + 1, bufferName);
        lastname = new char[strlen(bufferLastName) + 1];
        strcpy_s(lastname, strlen(bufferLastName) + 1, bufferLastName);
        surname = new char[(strlen(bufferSurname) + 1)];
        strcpy_s(surname, strlen(bufferSurname) + 1, bufferSurname);
        phoneNumber = new char[(strlen(bufferPhoneNumber) + 1)];
        strcpy_s(phoneNumber, strlen(bufferPhoneNumber) + 1, bufferPhoneNumber);

    }
    void Output()
    {
        if (name == nullptr || lastname == nullptr || surname == nullptr || phoneNumber == nullptr)
        {
            cout << "Not full contact." << endl;
            return;
        }
        cout << "Name: " << name << endl;
        cout << "LastName: " << lastname << endl;
        cout << "Surname: " << surname << endl;
        cout << "Phonenumber: " << phoneNumber << endl;
    }
    ~Contact()
    {

    }
};

Contact* addContact(Contact* contact, int& size, const Contact& newStudent) 
{
    Contact* newStudents = new Contact[size + 1];
    for (int i = 0; i < size; i++) 
    {
        newStudents[i] = contact[i];
    }
    newStudents[size] = newStudent;
    delete[] contact;
    size++;
    return newStudents;
}

Contact* removeStudent(Contact* сontact, int& size, int index) 
{
    if (index < 0 || index >= size) 
    {

        cout << "Unknown index: " << index << endl;
        return сontact;
    }
    Contact* newStudents = new Contact[size - 1];
    for (int i = 0; i < index; ++i) {
        newStudents[i] = сontact[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newStudents[i - 1] = сontact[i];
    }
    delete[] сontact;
    size--;
    return newStudents;
}


void printContact(Contact* contact, int size)
{
    for (int i = 0; i < size; i++)
    {
        contact[i].Output();
    }
}

int main() 
{
    Drob drob1(7, 8), drob2(8, 7);      //Task1
    drob1.sum(drob2);
    drob1.subtraction(drob2);
    drob1.product(drob2);
    drob1.divide(drob2);

    int size = 1;       //Task2
    Contact* сontact = new Contact[size];
    сontact[0] = {"Dima","Juravskiy","Alekseyovich","0683084312"};
    Contact newContact = { "Bogdan","Pirhavko","Oleksandrovich","0916084933" };
    сontact = addContact(сontact, size, newContact);
    printContact(сontact, size);
    сontact = removeStudent(сontact, size, 0);
    printContact(сontact, size);
    delete[] сontact;

    return 0;
}