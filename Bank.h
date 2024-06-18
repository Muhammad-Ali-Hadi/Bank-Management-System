#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#ifndef BANK_H_
#define BANK_H_
#pragma once
using namespace std;

bool VerifyPassword(string Password, string password)
{
    if (password.length() < 8)
    {
        return false;
    }
    else
    {
        return Password == password;
    }
}

bool GetPasswordValidity(string password)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    if (password.length() >= 8 && password.length() <= 16)
    {
        for (int i = 0; i < password.length(); i++)
        {
            if ((password.at(i) >= 33 && password.at(i) <= 47) || (password.at(i) >= 58 && password.at(i) <= 64) || (password.at(i) >= 91 && password.at(i) <= 96) || (password.at(i) >= 123 && password.at(i) <= 126))
            {
                count1++;
            }

            if ((password.at(i) >= 65 && password.at(i) <= 90) || (password.at(i) >= 97 && password.at(i) <= 122))
            {
                count2++;
            }

            if ((password.at(i) >= 48 && password.at(i) <= 57))
            {
                count3++;
            }
        }
        return count1 >= 0 && count2 > 0 && count3 > 0;
    }
    else
        return false;
}

string GenerateAccountNumber()
{
    srand(time(nullptr));
    string AccountNumber;
    for (int i = 0; i < 16; i++)
    {
        char digit = rand() % 10 + '0';
        AccountNumber += digit;
    }

    return AccountNumber;
}

string GenerateCVV()
{
    string CVV;
    srand(time(nullptr));
    CVV = rand() % 10 + '0';
    CVV += rand() % 10 + '0';
    CVV += rand() % 10 + '0';

    return CVV;
}

string GenerateVirtualDebitCard()
{
    string DebitCardNumber;

    srand(time(nullptr));
    for (int i = 0; i < 19; i++)
    {
        if (i == 4 || i == 9 || i == 14)
        {
            DebitCardNumber += ' ';
        }
        else
        {
            char digit = rand() % 10 + '0';
            DebitCardNumber += digit;
        }
    }

    return DebitCardNumber;
}

int GetCurrentDay()
{
    time_t t = time(0);
    tm *now = localtime(&t);

    return now->tm_mday;
}

int GetCurrentMonth()
{
    time_t t = time(0);
    tm *now = localtime(&t);

    return (now->tm_mon + 1);
}

int GetCurrentYear()
{
    time_t t = time(0);
    tm *now = localtime(&t);

    return (now->tm_year + 1900);
}

int GetExpireYear()
{
    time_t t = time(0);
    tm *now = localtime(&t);

    return (now->tm_year + 1906);
}

string GetCurrentDate()
{
    string CurrentDate;

    CurrentDate = to_string(GetCurrentDay()) + '-';
    CurrentDate += to_string(GetCurrentMonth()) + '-';
    CurrentDate += to_string(GetCurrentYear());

    return CurrentDate;
}

string DebitCardExpiry()
{
    string ExpiryDate;
    ExpiryDate = to_string(GetCurrentDay()) + '-';
    ExpiryDate += to_string(GetCurrentMonth()) + '-';
    ExpiryDate += to_string(GetExpireYear());

    return ExpiryDate;
}

bool ValidatePin(string PIN)
{
    if (stoi(PIN) < 10000 && stoi(PIN) > 999)
    {
        return true;
    }
    else
        return false;
}

string GenerateIBAN_Number()
{
    string IBAN_Number;

    srand(time(nullptr));
    for (int i = 0; i < 24; i++)
    {
        if (i == 0)
        {
            IBAN_Number += 'P';
        }
        else if (i == 1)
        {
            IBAN_Number += 'K';
        }
        else if (i == 4)
        {
            IBAN_Number += 'F';
        }
        else if (i == 5)
        {
            IBAN_Number += 'A';
        }
        else if (i == 6)
        {
            IBAN_Number += 'S';
        }
        else if (i == 7)
        {
            IBAN_Number += 'T';
        }
        else
        {
            char digit = '0' + rand() % 10;
            IBAN_Number += digit;
        }
    }
    return IBAN_Number;
}

bool VerifyCNIC(string CNIC)
{
    int count = 0;
    if (CNIC.length() == 15 && CNIC.at(5) == '-' && CNIC.at(13) == '-')
    {
        for (int i = 0; i < 15; i++)
        {
            if (i != 5 && i != 13)
            {
                if (CNIC.at(i) >= 48 && CNIC.at(i) <= 57)
                {
                    count++;
                }
            }
        }
    }
    if (count == 13)
    {
        return true;
    }
    else
        return false;
}

bool DateOfBirthValidity(int day, int month, int year)
{
    int count = 0;
    if (day > 0 && day < 32)
        count++;
    if (month > 0 && month < 13)
        count++;
    if (year > 1947 && year < 2024)
        count++;

    if (count == 3)
        return true;
    else
        return false;
}

string GetDateOfBirth(int day, int month, int year)
{
    string date;
    date = to_string(day) + '-';
    date += to_string(month) + '-';
    date += to_string(year);

    return date;
}

bool ForgetPasswordValidity(string cnic, string verifycnic, string DebitCardNumber, string debitcardnumber)
{
    if (cnic == verifycnic && DebitCardNumber == debitcardnumber)
    {
        return true;
    }
    else
        return false;
}

bool ValidateEmail(string Email)
{
    if ((Email.at(Email.length() - 1)) == 'm' && (Email.at(Email.length() - 2)) == 'o' && (Email.at(Email.length() - 3)) == 'c' && (Email.at(Email.length() - 4)) == '.' && (Email.at(Email.length() - 5)) == 'l' && (Email.at(Email.length() - 6)) == 'i' && (Email.at(Email.length() - 7)) == 'a' && (Email.at(Email.length() - 8)) == 'm' && (Email.at(Email.length() - 9)) == 'g' && (Email.at(Email.length() - 10)) == '@' && (Email.size() - 10 > 4))
        return true;
    else
        return false;
}

bool ValidateCellNumber(string CellNumber)
{
    if (CellNumber.length() == 12)
    {
        if (CellNumber.at(0) == '0' && CellNumber.at(1) == '3' && CellNumber.at(4) == '-')
            return true;
        else
            return false;
    }
    else
        return false;
}

bool ValidateTransactionPassword(string password)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    if (password.length() >= 8 && password.length() <= 16)
    {
        for (int i = 0; i < password.length(); i++)
        {
            if ((password.at(i) >= 33 && password.at(i) <= 47) || (password.at(i) >= 58 && password.at(i) <= 64) || (password.at(i) >= 91 && password.at(i) <= 96) || (password.at(i) >= 123 && password.at(i) <= 126))
            {
                count1++;
            }

            if ((password.at(i) >= 65 && password.at(i) <= 90) || (password.at(i) >= 97 && password.at(i) <= 122))
            {
                count2++;
            }

            if ((password.at(i) >= 48 && password.at(i) <= 57))
            {
                count3++;
            }
        }
        return count1 >= 0 && count2 > 0 && count3 > 0;
    }
    else
        return false;
}

int getAge(int DOY)
{
    int Num = GetCurrentYear() - DOY;
    return Num;
}
#endif