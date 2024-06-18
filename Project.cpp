#include <bits/stdc++.h>
#include <windows.h>
#include "bank.h"
using namespace std;

class Account
{
    string AccountNumber;
    string Name;
    string AccountType; // (Current/Saving)
    string IBAN_Number;
    string Password;
    string DateOfBirth;
    string DebitCardCategory;
    string DebitCardNumber;
    string DebitCardIssueDate;
    string DebitCardExpireDate;
    string DebitCardCVV;
    string Email;
    string Gender; //(Mr/Ms)
    string CellNumber;
    long long int Balance;
    string TransactionPassword;
    string DebitCardPIN;
    vector<string> TransactionPurpose;
    vector<long long int> Transactions;
    long long int NumTransactions;

    protected:
    bool LoanExistance;
    string CNIC_Number;

public:
    Account() : Balance(10000), NumTransactions(0) {}

    void SetName(string Name)
    {
        this->Name = Name;
    }

     void setLoanExistance(bool l){
        LoanExistance=l;
    }

    void SetGender(string Gender)
    {
        this->Gender = Gender;
    }

    void SetEmail(string Email)
    {
        this->Email = Email;
    }

    void SetCNIC(string CNIC_Number)
    {
        this->CNIC_Number = CNIC_Number;
    }

    void SetDateOfBirth(string DateOfBirth)
    {
        this->DateOfBirth = DateOfBirth;
    }

    void SetAccountNumber(string AccountNumber)
    {
        this->AccountNumber = AccountNumber;
    }

    void SetIBAN_Number(string IBAN_Number)
    {
        this->IBAN_Number = IBAN_Number;
    }

    void SetPassword(string Password)
    {
        this->Password = Password;
    }

    void UpdateBalance(long long int Balance)
    {
        this->Balance = Balance;
    }

    void SetDebitCardCategory(string DebitCardCategory)
    {
        this->DebitCardCategory = DebitCardCategory;
        if (DebitCardCategory == " Silver ")
            Balance -= 1500;
        else if (DebitCardCategory == "  Gold  ")
            Balance -= 2500;
        else if (DebitCardCategory == "Platinum")
            Balance -= 3500;
    }

    void DebitCard(string DebitCardNumber)
    {
        this->DebitCardNumber = DebitCardNumber;
    }

    void SetDebitCardPIN(string DebitCardPIN)
    {
        this->DebitCardPIN = DebitCardPIN;
    }

    void SetDebitCardIssueDate(string DebitCardIssueDate)
    {
        this->DebitCardIssueDate = DebitCardIssueDate;
    }

    void SetDebitCardExpireDate(string DebitCardExpireDate)
    {
        this->DebitCardExpireDate = DebitCardExpireDate;
    }

    void setLoanAmount(double D){
        Balance-=D;
    }

    void deductDownPaymentAmount(long long int interest,long long int Amount){
        long long int A=(interest/100)*Amount;
        Balance-=A;
    }

    void SetDebitCardCVV(string DebitCardCVV)
    {
        this->DebitCardCVV = DebitCardCVV;
    }

    void SetCellNumber(string CellNumber)
    {
        this->CellNumber = CellNumber;
    }

    void SetAccountType(string AccountType)
    {
        this->AccountType = AccountType;
    }

    void SetTransactionPassword(string TransactionPassword)
    {
        this->TransactionPassword = TransactionPassword;
    }

    void UpdateNumTransactions()
    {
        NumTransactions++;
    }

    void updateTransactionsHistory(string purpose,long long int amount)
    {
        Transactions.push_back(amount); 
        TransactionPurpose.push_back(purpose);
    }

    void DepositAmount(long long int amount)
    {
        Balance += amount;
    }

    string GetCNIC()
    {
        return CNIC_Number;
    }

    string GetDebitCardCategory()
    {
        return DebitCardCategory;
    }

    string GetDebitCardNumber()
    {
        return DebitCardNumber;
    }

    string GetDebitCardCVV()
    {
        return DebitCardCVV;
    }

    bool getLoanExistance(){
        if (LoanExistance){
            return true;
        }
        else{
            return false;
        }
    }

    string GetName()
    {
        return Name;
    }

    string GetAccountNumber()
    {
        return AccountNumber;
    }

    string GetIBAN_Number()
    {
        return IBAN_Number;
    }

    string GetPassword()
    {
        return Password;
    }

    string GetTransactionPassword()
    {
        return TransactionPassword;
    }

    string GetDebitCardIssueDate()
    {
        return DebitCardIssueDate;
    }

    string GetDebitCardExpireDate()
    {
        return DebitCardExpireDate;
    }

    string GetEmail()
    {
        return Email;
    }

    string GetCellNumber()
    {
        return CellNumber;
    }

    long long int GetBalance()
    {
        return Balance;
    }

    string GetAccountType()
    {
        return AccountType;
    }

    string GetGender()
    {
        return Gender;
    }

    void DisplayAccountDetails()
    {
        cout << "|--------------<Account Details>---------------|" << endl;
        cout << "| Account Holder Name : " << Name << endl;
        cout << "| Account Holder CNIC : " << CNIC_Number << endl;
        cout << "| Date of Birth : " << DateOfBirth << endl;
        cout << "| Account Type : " << AccountType << endl;
        cout << "| Account Number : " << AccountNumber << endl;
        cout << "| IBAN Number : " << IBAN_Number << endl;
        cout << "| Debit Card Number : " << DebitCardNumber << endl;
        cout << "| Balance : Rs." << Balance << endl;
    }

    void DisplayTransactionDetails()
    {
        if (NumTransactions == 0)
        {
            cout << "No Transactions Yet!" << endl;
            return;
        }

        cout << "---------(Transaction Details)----------" << endl;
        for (int i = 0; i < Transactions.size(); i++)
        {
            cout << i + 1 << ") Transaction Purpose : " << TransactionPurpose[i] << endl;
            cout << "   Transaction Amount : Rs." << Transactions[i] << endl;
        }
        cout << "----------------------------------------" << endl;
    }
};

class Branch : public Account
{
    string branchName;
    long int branchCode;
    string address;
    string phoneNumber;
    string managerName;
    vector<Account> accounts;
    int size;

public:

    Branch(){}
    Branch(string branchName, long int branchCode, string address, string phoneNumber, string managerName) : size(0)
    {
        this->branchName = branchName;
        this->branchCode = branchCode;
        this->address = address;
        this->phoneNumber = phoneNumber;
        this->managerName = managerName;
    }

    string getBranchName()
    {
        return branchName;
    }

    void addAccount(Account account)
    {
        accounts.push_back(account);
        size++;
    }

    void deleteAccount(Account account)
    {
        vector<Account> tempAccounts;
        for (int i = 0; i < size; ++i)
        {
            if (accounts[i].GetAccountNumber() != account.GetAccountNumber())
            {
                tempAccounts.push_back(accounts[i]);
                break;
            }
        }
        accounts = tempAccounts;
        size--;
    }

    int getBranchCode()
    {
        return branchCode;
    }

    int getNumberOfAccounts()
    {
        return size;
    }

    string getBranchManager()
    {
        return managerName;
    }

    string getBranchContactNumber()
    {
        return phoneNumber;
    }

    string getBranchLocation()
    {
        return address;
    }

    vector<Account> getAccounts()
    {
        return accounts;
    }
};

void SetConsoleColor(int Color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Color);
}

class Loan: public Branch{
    long long int Salary;
    int TypeLoanChoice;
    int TypeCarLoanChoice;
    int TypeHomeLoanChoice;
    int TypeHealthLoanChoice;
    int TypeEducationLoanChoice;
    int Age;
    bool downPaymentStatus;
    Account* account;
    

    public:
    Loan(){
        downPaymentStatus=true;
    }

    void setSalary(float s){
        Salary=s;
    }

    void SetAccountForLoan(Account *a){
        account=a;
    }

    void setTypeLoanChoice(int C){
        TypeCarLoanChoice=C;
    }

    void setTypeCarLoanChoice(int C){
        TypeCarLoanChoice=C;
    }
    
    void setTypeHomeLoanChoice(int C){
        TypeHomeLoanChoice=C;
    }

    void setTypeHealthLoanChoice(int C){
        TypeHealthLoanChoice=C;
    }

    void setEducationLoanChoice(int C){
        TypeEducationLoanChoice=C;
    }

    void setAge(int A){
        Age=A;
    }

    void showCarLoanDetails(){
        cout<<endl<<"|<           Welcome To Car Loan System Of Fast!         >|"<<endl<<endl;
        cout<<endl<<"Deal 1: "<<endl;
        cout<<"Loan Amount: 20,000,000."<<endl;
        cout<<"Interest Rate: 8.5%."<<endl;
        cout<<"Loan Term: 4 Years."<<endl;
        cout<<"Down Payment: 20% of Loan Amount."<<endl;
        cout<<"Early Settlement: No Penalty for Late Payment."<<endl;
        cout<<endl<<"Terms and Conditions Apply. Subject to Approval."<<endl;

        cout<<endl<<"Deal 2: "<<endl;
        cout<<"Loan Amount: Up to PKR 1,500,000."<<endl;
        cout<<"nterest Rate: 7% per annum."<<endl;
        cout<<"Loan Term: 3 years."<<endl;
        cout<<"Down Payment: 15% of Loan Amount."<<endl;
        cout<<"Early Settlement: 2% penalty for early repayment"<<endl;

        cout<<endl<<"Terms and Conditions Apply. Subject to Approval."<<endl;

        
        cout<<"Deal 3: "<<endl;
        cout<<"Loan Amount: Up to PKR 3,000,000"<<endl;
        cout<<"Interest Rate: 10% per annum"<<endl;
        cout<<"Loan Term: 7 years"<<endl;
        cout<<"Down Payment: As low as 10% of the car's value"<<endl;
        cout<<"Early Settlement: No penalty for early repayment after the first year"<<endl;
        cout<<endl<<"Terms and Conditions Apply. Subject to Approval."<<endl;

        cout<<endl<<"Eligibility Criteria For All Deals: "<<endl;
        cout<<"Pakistani citizen or resident with valid ID proof."<<endl;
        cout<<"Minimum age of 23 years and maximum age of 60 years at loan maturity."<<endl;
        cout<<"Stable source of income of atleast PKR 80000."<<endl;
        cout<<endl<<"Terms and Conditions Apply. Subject to Credit Assessment."<<endl;
    }

    void showHomeLoanDetails(){
        cout<<endl<<"|<        Welcome To Home Loan System Of Fast Bank!        |>"<<endl<<endl;
        cout<<endl<<"Deal 1: "<<endl;
        cout<<"Loan Amount: Up to PKR 10,000,000"<<endl;
        cout<<"Interest Rate: 7.5% per month"<<endl;
        cout<<"Loan Term: 15 years"<<endl;
        cout<<"Down Payment: 20% of the property's value"<<endl;
        cout<<"Early Settlement: No penalty for early repayment after the first 5 years"<<endl;


        cout<<endl<<"Deal 2: "<<endl;
        cout<<endl<<"Loan Amount: Up to PKR 15,000,000"<<endl;
        cout<<"Interest Rate: 8.25% per month"<<endl;
        cout<<"Loan Term: 20 years"<<endl;
        cout<<"Down Payment: 15% of the property's value"<<endl;
        cout<<"Early Settlement: 2% penalty for early repayment within the first 7 years, waived thereafter"<<endl;

        cout<<endl<<"Deal 3: "<<endl;
        cout<<"Loan Amount: Up to PKR 20,000,000"<<endl;
        cout<<"Interest Rate: 8.75% per month"<<endl;
        cout<<"Loan Term: 25 years"<<endl;
        cout<<"Down Payment: 10% of the property's value"<<endl;
        cout<<"Early Settlement: No penalty for early repayment after the first 8 years"<<endl;

        cout<<endl<<"Eligibility Criteria For All Deals: "<<endl;
        cout<<"Minimum age of 21 years at the time of application."<<endl;
        cout<<"Pakistani citizenship or valid residency."<<endl;
        cout<<"Minimum Salary of PKR 80000"<<endl;
    }

    void showHealthLoanDetails(){
        cout<<endl<<"|<           Welcome To Health Loan System Of Fast!         >|"<<endl<<endl;
        cout<<endl<<"Deal 1: "<<endl;
        cout<<"Coverage Amount: Up to PKR 500,000 per annum"<<endl;
        cout<<"Interest Rate: 5% of Coverage Amount";
        cout<<"Coverage Type: Individual"<<endl;
        cout<<"Hospital Network: Nationwide, including specialized centers"<<endl;
        cout<<"Guarentee of 15 Years Life Insurance"<<endl;

        cout<<endl<<"Deal 2: "<<endl;
        cout<<"Coverage Amount: Up to PKR 1,000,000 per annum"<<endl;
        cout<<"Interest Rate: 6% of Coverage Amount";
        cout<<"Coverage Type: Individual"<<endl;
        cout<<"Hospital Network: Major cities nationwide"<<endl;
        cout<<"Guarentee of 20 Years Life Insurance"<<endl;
        

        cout<<endl<<"Deal 3: "<<endl;
        cout<<"Coverage Amount: Up to PKR 2,000,000 per annum"<<endl;
        cout<<"Coverage Type: Individual"<<endl;
        cout<<"Interest Rate: 7% of Coverage Amount";
        cout<<"Hospital Network: Nationwide, including specialized centers"<<endl;
        cout<<endl<<"Terms and Conditions Apply. Subject to Approval."<<endl;
        cout<<"Guarentee of 25 Years Life Insurance"<<endl;

        cout<<endl<<"Eligibility Criteria For All Deals: "<<endl;
        cout<<endl<<"Pakistani citizenship or valid residency."<<endl;
        cout<<"Minimum age of 21 years for primary insured."<<endl;
        cout<<"Maximum age of 60 years for dependent children."<<endl;
    }

    void showEducationLoanDetails(){
        cout<<endl<<"|<           Welcome To Education Loan System Of Fast Bank!         >|"<<endl<<endl;
        cout<<endl<<"Deal 1: "<<endl;
        cout<<"Loan Amount: Up to PKR 2,500,000"<<endl;
        cout<<"Interest Rate: 7.25% per annum"<<endl;
        cout<<"Loan Term: 10 years"<<endl;
        cout<<"Additional Benefits: Partial interest subsidy for students from underprivileged backgrounds"<<endl;

        cout<<endl<<"Deal 2: "<<endl;
        cout<<"Loan Amount: Up to PKR 3,500,000"<<endl;
        cout<<"Interest Rate: 8% per annum"<<endl;
        cout<<"Loan Term: 15 years"<<endl;
        cout<<"Additional Benefits: Scholarship opportunities for outstanding academic performance"<<endl;
    
        cout<<endl<<"Deal 3: "<<endl;
        cout<<"Loan Amount: Up to PKR 4,500,000"<<endl;
        cout<<"Interest Rate: 7.25% per annum"<<endl;
        cout<<"Loan Term: 20 years"<<endl;
        cout<<"Additional Benefits: Partial interest subsidy for students from underprivileged backgrounds"<<endl;

        cout<<endl<<"Eligibility Criteria For All Deals Deals: "<<endl;
        cout<<"Pakistani citizenship or valid residency, admission into recognized institution"<<endl;

    }

    bool isNationalCitizen(){
        string cnic=account->GetCNIC();
        string sub=cnic.substr(0,2);
        int num=stoi(sub);
        if (num>15 && num<54){
            return true;
        }
        else{
            return false;
        }
    }

    bool isCarLoanEligible(){
        bool flag=isNationalCitizen();
        if (flag && Salary>=60000 && (Age>=21 || Age<60)){
            return true;
        }
        else{
            return false;

        }
    }

    bool isHomeLoanEligible(){
        bool flag=isNationalCitizen();
        if (flag && Salary>80000 && Age>=21){
            return true;
        }
        else{
            return false;
        }
    }

    bool isHealthLoanEligible(){
        if (isNationalCitizen() && (Age>=21 && Age<=60)){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEducationLoanEligible(){
        if (isNationalCitizen()){
            return true;
        }
        else{
            return false;
        }
    }

    bool isDownPaymentAvailable(double DPercent,long long int A){
        long long int Amount=(DPercent*A);
        long long int balance=account->GetBalance();
        if (balance>=Amount){
            downPaymentStatus=true;
            return downPaymentStatus;
        }
        else{
            downPaymentStatus=false;
            return downPaymentStatus;
        }
    }


    double calculatePerMonthAmount(float i,int y,long int amount){
        double A=amount*(i/100);
        amount+=A;
        amount/=(y*12);
        return amount;
    }

    double getDownPayment(double i,long int amount){
        amount=amount*i;
        return amount;
    }

    bool BalanceOverInstallment(long int Amount,long int Balance){
        if (Amount<=Balance){
            return true;
        }
        else{
            return false;
        }
    }

};

main()
{
    char selections = '-';
    long int perMonthAmount;
    int year;
    Loan loan;
    Branch branch[5] = {Branch("Gulshan", 1001, "Maskan Chowrangi", "021-111-784-784", "Mr.Muhammad Ali Hadi"),
                        Branch("Defence", 1002, "3 Talwaar", "021-111-785-785", "Ms.Fatima Mukhtar"),
                        Branch("FAST-NUCES Main Campus", 1003, "Shah-Latif Town", "021-111-787-787", "Mr.Muhammad Mustafa"),
                        Branch("Nazimabad", 1004, "Matric Board Office", "021-11-788-788", "Ms.Ayesha"),
                        Branch("PECHS", 1005, "FAST-NUCES City Campus", "021-111-789-789", "Mr.Shafique")};

    while (selections != '0')
    {
        SetConsoleColor(FOREGROUND_BLUE);
        cout << "<(>-^-<)>--------(WELCOME TO FAST ONLINE BANKING PLATFORM--------<(>-^-<)>" << endl;
        cout << "   <(|)>*********************************************************************<(|)>   " << endl;
        cout << "-------------------------------------------------------------------------------------" << endl;
        SetConsoleColor(FOREGROUND_RED);
        cout << "<||>        Press (1) to Login to your Account        <||>" << endl
             << "<||>        Press (2) to Create New Account           <||>" << endl
             << "<||>        Press (0) to End Program                  <||>" << endl;
        cin >> selections;
        string Email;
        switch (selections)
        {
        case '1':
        {
            bool Continue = false;
            SetConsoleColor(FOREGROUND_RED);
            cout << "Press (1) to Confirm Proceeding Login" << endl
                 << "Press (0) to Get to the Home Page" << endl;
            cin >> Continue;
            if (!Continue)
                break;
            else
            {
                SetConsoleColor(FOREGROUND_BLUE);
                cout << endl
                     << "     <(>-^-<)>--------(WELCOME TO FAST ONLINE BANKING PLATFORM)--------<(>-^-<)>     " << endl;
                cout << "   <(|)>*********************************************************************<(|)>   " << endl
                     << endl;
                cout << "-------------------------------------------------------------------------------------" << endl
                     << endl;
                SetConsoleColor(FOREGROUND_GREEN);
                cout << "                                    <(LOGIN PORTAL)>                                 " << endl
                     << endl;
                SetConsoleColor(FOREGROUND_GREEN);
                int valid = 0;
                while (valid == 0)
                {
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Enter Your Registered Email : ";
                    cin >> Email;
                    if (ValidateEmail(Email))
                    {
                        ++valid;
                    }
                    else
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Invalid EMAIL Pattern!" << endl;
                    }
                }
                SetConsoleColor(FOREGROUND_GREEN);
                int forget;
                cout << "Press (1) for Forgotten Password else any Numeric Key" << endl;
                cin >> forget;
                if (forget == 1)
                {
                    bool flag8 = false;
                    int count = 3;
                    string cnic, DebitCardNumber, password;
                    int continueReset = 0;
                    do
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number(#####-#######-#) : ";
                        cin >> cnic;
                        cout << "Enter Debit Card Number(#### #### #### #####) : ";
                        cin.ignore();
                        getline(cin, DebitCardNumber);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "(1001) for Gulshan Branch" << endl
                             << "(1002) for Defence Branch" << endl
                             << "(1003) for FAST-NUCES Main Campus" << endl
                             << "(1004) for Nazimabad Branch" << endl
                             << "(1005) for PECHS Branch" << endl;
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Enter Your Branch Code from the Above : " << endl;
                        int branchCODE;
                        cin >> branchCODE;
                        for (int i = 0; i < 5; ++i)
                        {
                            if (branch[i].getBranchCode() == branchCODE)
                            {
                                vector<Account> acc = branch[i].getAccounts();
                                for (int j = 0; j < branch[i].getNumberOfAccounts(); ++j)
                                {
                                    if (ForgetPasswordValidity(cnic, acc[j].GetCNIC(), DebitCardNumber, acc[j].GetDebitCardNumber()) == true)
                                    {
                                        while (!flag8)
                                        {
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            cout << "Enter Password to Update : ";
                                            cin >> password;
                                            if (GetPasswordValidity(password) == true)
                                            {
                                                acc[j].SetPassword(password);
                                                SetConsoleColor(FOREGROUND_GREEN);
                                                cout << "Password Updated Successfully!" << endl;
                                                flag8 = true;
                                                count = 0;
                                            }
                                            else
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Invalid Password Pattern! Enter Again!" << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        SetConsoleColor(FOREGROUND_RED);
                                        cout << "Incorrect CNIC Number or Debit Card Number" << endl
                                             << "Your Have " << count << " Times Entry Left" << endl;
                                        count--;
                                        cout << "Press 1 to continue resetting the password?" << endl;
                                        cin >> continueReset;
                                    }
                                }
                            }
                        }
                    } while ((continueReset == 1) && (count != 0));
                }

                cout << "Enter Your Login Password : ";
                string PASSWORD;
                cin >> PASSWORD;
                cout << "Enter Your Account Branch Code" << endl
                     << "(1001) for Gulshan Branch" << endl
                     << "(1002) for Defence Branch" << endl
                     << "(1003) for FAST-NUCES Main Campus" << endl
                     << "(1004) for Nazimabad Branch" << endl
                     << "(1005) for PECHS Branch" << endl;
                int branchCode;
                cin >> branchCode;
                bool isFound = false;
                for (int i = 0; i < 5; i++)
                {
                    if (branch[i].getBranchCode() == branchCode)
                    {
                        vector<Account> account = branch[i].getAccounts();
                        for (int j = 0; j < branch[i].getNumberOfAccounts(); j++)
                        {
                            if (account[j].GetEmail() == Email && account[j].GetPassword() == PASSWORD)
                            {
                                isFound = true;
                                Account ACCount = account[j];
                                char choice = '-';
                
                                while (choice != '0')
                                {
                                    end_loop:
                                    SetConsoleColor(FOREGROUND_BLUE);
                                    cout << endl
                                         << "<(>-^-<)>--------(WELCOME TO FAST ONLINE BANKING " << ACCount.GetGender() << "." << ACCount.GetName() << "--------<(>-^-<)>" << endl;
                                    cout << "   <(|)>*********************************************************************<(|)>   " << endl
                                         << endl;
                                    cout << "-------------------------------------------------------------------------------------" << endl;
                                    SetConsoleColor(FOREGROUND_GREEN);
                                    cout << "                                  [Select the Given Choices]                              " << endl;
                                    SetConsoleColor(FOREGROUND_RED);
                                    cout << "<|                                Press (A) to View Balance                            |>" << endl
                                         << "<|                                Press (B) to Account Details                         |>" << endl
                                         << "<|                                Press (C) to View Virtual Debit Card Details         |>" << endl
                                         << "<|                                Press (D) to Change Transaction Password             |>" << endl
                                         << "<|                                Press (E) to Transfer Funds                          |>" << endl
                                         << "<|                                Press (F) to View Transaction Details                |>" << endl
                                         << "<|                                Press (G) to View Branch Code                        |>" << endl
                                         << "<|                                Press (H) to Change Login Password                   |>" << endl
                                         << "<|                                Press (I) to Close your Account                      |>" << endl
                                         << "<|                                Press (J) to Transfer to a different Branch          |>" << endl
                                         << "<|                                Press (K) to View Branch Manager Name                |>" << endl
                                         << "<|                                Press (L) to Contact Branch                          |>" << endl
                                         << "<|                                Press (M) to View Branch Location                    |>" << endl
                                         << "<|                                Press (N) to change Debit Card PIN                   |>" << endl
                                         << "<|                                Press (O) to Get Loan                                |>" << endl
                                         << "<|                                Press (P) to Pay Loan                                |>" << endl
                                         << "<|                                Press (0) to Log Out                                 |>" << endl
                                         << endl;
                                    cin >> choice;

                                    switch (choice)
                                    {
                                    case 'A':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "Balance : Rs." << ACCount.GetBalance() << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }
                                    case 'B':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        ACCount.DisplayAccountDetails();
                                        cout << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }
                                    case 'C':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_RED);
                                        cout << "-----<Virtual Debit Card Details>-----" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "__________________________________________" << endl;
                                        cout << "|            FAST BANK LIMITED            |" << endl;
                                        cout << "|            " << ACCount.GetName() << "            |" << endl;
                                        cout << "|                                         |" << endl;
                                        cout << "|         -<" << ACCount.GetDebitCardNumber() << ">-         |" << endl;
                                        cout << "|                 (VISA)                  |" << endl;
                                        cout << "|    Date of Issue      Date of Expire    |" << endl;
                                        cout << "|   -<(" << ACCount.GetDebitCardIssueDate() << ")>-    -<(" << ACCount.GetDebitCardExpireDate() << ")>-    |" << endl;
                                        cout << "|              -(CVV:" << ACCount.GetDebitCardCVV() << ")-                |" << endl;
                                        cout << "|             **(" << ACCount.GetDebitCardCategory() << ")**              |" << endl;
                                        cout << "|_________________________________________|" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }
                                    case 'D':
                                    {
                                        int flag = 4;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        while (flag != 0)
                                        {
                                            cout << "-------------------------------------------------------------------------------------" << endl
                                                 << endl;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            cout << "Enter New Transaction Password : ";
                                            string transPassword;
                                            cin >> transPassword;
                                            if (GetPasswordValidity(transPassword))
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Press (1) to Confirm New Transaction Password" << endl
                                                     << "Press (2) to Re-Enter Transaction Password" << endl
                                                     << "Press (0) to Go Back" << endl;
                                                cin >> flag;
                                                if (flag == 1)
                                                {
                                                    ACCount.SetTransactionPassword(transPassword);
                                                    SetConsoleColor(FOREGROUND_GREEN);
                                                    cout << "Transaction Password Changed Successfully!" << endl;
                                                    flag = 0;
                                                }
                                                else if (flag == 2)
                                                {
                                                    SetConsoleColor(FOREGROUND_RED);
                                                    cout << "Enter Transaction Password Again" << endl;
                                                }
                                            }
                                            else
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters to maximum 16 characters" << endl;
                                            }
                                        }
                                        break;
                                    }
                                    case 'E':
                                    {
                                        char choose;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "Select Your Account Branch where you have to Transfer Amount" << endl;
                                        SetConsoleColor(FOREGROUND_RED);
                                        cout << "Press (1) for Gulshan Branch(1001)" << endl
                                             << "Press (2) for Defence Branch(1002)" << endl
                                             << "Press (3) for FAST-NUCES Main Campus(1003)" << endl
                                             << "Press (4) for Nazimabad Branch(1004)" << endl
                                             << "Press (5) for PECHS Branch(1005)" << endl;
                                        cin >> choose;

                                        switch (choose)
                                        {
                                        case '1':
                                        {
                                            int count = 0;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            vector<Account> ACCOUNTS = branch[0].getAccounts();
                                            cout << "Enter Account Number (or) IBAN Number to Transfer Amount : ";
                                            string accountIBANNumber;
                                            cin >> accountIBANNumber;
                                            for (int k = 0; k < branch[0].getNumberOfAccounts(); ++k)
                                            {
                                                if ((ACCOUNTS[k].GetAccountNumber() == accountIBANNumber && ACCOUNTS[k].GetAccountNumber() != ACCount.GetAccountNumber()) || (ACCOUNTS[k].GetIBAN_Number() == accountIBANNumber && ACCOUNTS[k].GetIBAN_Number() != ACCount.GetIBAN_Number()))
                                                {
                                                    Account ACCOUNT = ACCOUNTS[k];
                                                    cout << "Enter Amount You want to Transfer : Rs.";
                                                    long long int amount;
                                                    cin >> amount;
                                                    cout << "Enter Purpose of Transfer : ";
                                                    string purpose;
                                                    cin.ignore();
                                                    getline(cin, purpose);
                                                    cout << "Enter Your Transaction Password : ";
                                                    string transactionPassword;
                                                    cin >> transactionPassword;
                                                    if (ACCount.GetTransactionPassword() == transactionPassword)
                                                    {
                                                        count++;
                                                        if(ACCount.GetBalance()<amount)
                                                        {
                                                            SetConsoleColor(FOREGROUND_RED);
                                                            cout<<"Insufficient Balance!"<<endl;
                                                        }
                                                        else
                                                        {
                                                            string purpose1 = "To Account (" + ACCOUNT.GetIBAN_Number() + ") for " + purpose;
                                                            string purpose2 = "From Account (" + ACCount.GetIBAN_Number() + ") for " + purpose;
                                                            ACCount.UpdateBalance(ACCount.GetBalance()-amount);
                                                            ACCOUNT.UpdateBalance(ACCOUNT.GetBalance()+amount);
                                                            ACCount.updateTransactionsHistory(purpose1,amount);
                                                            ACCOUNT.updateTransactionsHistory(purpose2,amount);
                                                            ACCount.UpdateNumTransactions();
                                                            ACCOUNT.UpdateNumTransactions();
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);  // Account is liyay delete kiya gaya hai q k jis branch mein account object tore hai us mein data update nahin hua hai sirf account k object mein update hua hai to us account k updated data ko dobara store karwaaya usi branch mein aur previous object jo store tha wo delete krwa diya hai
                                                            branch[0].deleteAccount(ACCOUNT);
                                                            branch[0].addAccount(ACCOUNT);
                                                            cout << "Amount Rs." << amount << " Transfered to Account " << ACCOUNT.GetName() << "(" << ACCOUNT.GetIBAN_Number() << ") from " << ACCount.GetName() << "(" << ACCount.GetIBAN_Number() << ")" << endl << endl;
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                                            choice = 0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            if (count == 0)
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Account Not Found (or) Invalid Transaction Password!" << endl;
                                            }
                                        }
                                        break;

                                        case '2':
                                        {
                                            int count = 0;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            vector<Account> ACCOUNTS = branch[1].getAccounts();
                                            cout << "Enter Account Number (or) IBAN Number to Transfer Amount : ";
                                            string accountIBANNumber;
                                            cin >> accountIBANNumber;
                                            for (int k = 0; k < branch[1].getNumberOfAccounts(); ++k)
                                            {
                                                if ((ACCOUNTS[k].GetAccountNumber() == accountIBANNumber && ACCOUNTS[k].GetAccountNumber() != ACCount.GetAccountNumber()) || (ACCOUNTS[k].GetIBAN_Number() == accountIBANNumber && ACCOUNTS[k].GetIBAN_Number() != ACCount.GetIBAN_Number()))
                                                {
                                                    Account ACCOUNT = ACCOUNTS[k];
                                                    cout << "Enter Amount You want to Transfer : Rs.";
                                                    double amount;
                                                    cin >> amount;
                                                    cout << "Enter Purpose of Transfer : ";
                                                    string purpose;
                                                    cin.ignore();
                                                    getline(cin, purpose);
                                                    cout << "Enter Your Transaction Password : ";
                                                    string transactionPassword;
                                                    cin >> transactionPassword;
                                                    if (ACCount.GetTransactionPassword() == transactionPassword)
                                                    {
                                                        count++;
                                                        if(ACCount.GetBalance()<amount)
                                                        {
                                                            SetConsoleColor(FOREGROUND_RED);
                                                            cout<<"Insufficient Balance!"<<endl;
                                                        }
                                                        else
                                                        {
                                                            string purpose1 = "To Account (" + ACCOUNT.GetIBAN_Number() + ") for " + purpose;
                                                            string purpose2 = "From Account (" + ACCount.GetIBAN_Number() + ") for " + purpose;
                                                            ACCount.UpdateBalance(ACCount.GetBalance()-amount);
                                                            ACCOUNT.UpdateBalance(ACCOUNT.GetBalance()+amount);
                                                            ACCount.updateTransactionsHistory(purpose1,amount);
                                                            ACCOUNT.updateTransactionsHistory(purpose2,amount);
                                                            ACCount.UpdateNumTransactions();
                                                            ACCOUNT.UpdateNumTransactions();
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                            branch[1].deleteAccount(ACCOUNT);
                                                            branch[1].addAccount(ACCOUNT);
                                                            cout << "Amount Rs." << amount << " Transfered to Account " << ACCOUNT.GetName() << "(" << ACCOUNT.GetIBAN_Number() << ") from " << ACCount.GetName() << "(" << ACCount.GetIBAN_Number() << ")" << endl << endl;
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                                            choice = 0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            if (count == 0)
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Account Not Found (or) Invalid Transaction Password!" << endl;
                                            }
                                        }
                                        break;

                                        case '3':
                                        {
                                            int count = 0;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            vector<Account> ACCOUNTS = branch[2].getAccounts();
                                            cout << "Enter Account Number (or) IBAN Number to Transfer Amount : ";
                                            string accountIBANNumber;
                                            cin >> accountIBANNumber;
                                            for (int k = 0; k < branch[2].getNumberOfAccounts(); ++k)
                                            {
                                                if ((ACCOUNTS[k].GetAccountNumber() == accountIBANNumber && ACCOUNTS[k].GetAccountNumber() != ACCount.GetAccountNumber()) || (ACCOUNTS[k].GetIBAN_Number() == accountIBANNumber && ACCOUNTS[k].GetIBAN_Number() != ACCount.GetIBAN_Number()))
                                                {
                                                    Account ACCOUNT = ACCOUNTS[k];
                                                    cout << "Enter Amount You want to Transfer : Rs.";
                                                    double amount;
                                                    cin >> amount;
                                                    cout << "Enter Purpose of Transfer : ";
                                                    string purpose;
                                                    cin.ignore();
                                                    getline(cin, purpose);
                                                    cout << "Enter Your Transaction Password : ";
                                                    string transactionPassword;
                                                    cin >> transactionPassword;
                                                    if (ACCount.GetTransactionPassword() == transactionPassword)
                                                    {
                                                        count++;
                                                        if(ACCount.GetBalance()<amount)
                                                        {
                                                            SetConsoleColor(FOREGROUND_RED);
                                                            cout<<"Insufficient Balance!"<<endl;
                                                        }
                                                        else
                                                        {
                                                            string purpose1 = "To Account (" + ACCOUNT.GetIBAN_Number() + ") for " + purpose;
                                                            string purpose2 = "From Account (" + ACCount.GetIBAN_Number() + ") for " + purpose;
                                                            ACCount.UpdateBalance(ACCount.GetBalance()-amount);
                                                            ACCOUNT.UpdateBalance(ACCOUNT.GetBalance()+amount);
                                                            ACCount.updateTransactionsHistory(purpose1,amount);
                                                            ACCOUNT.updateTransactionsHistory(purpose2,amount);
                                                            ACCount.UpdateNumTransactions();
                                                            ACCOUNT.UpdateNumTransactions();
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                            branch[2].deleteAccount(ACCOUNT);
                                                            branch[2].addAccount(ACCOUNT);
                                                            cout << "Amount Rs." << amount << " Transfered to Account " << ACCOUNT.GetName() << "(" << ACCOUNT.GetIBAN_Number() << ") from " << ACCount.GetName() << "(" << ACCount.GetIBAN_Number() << ")" << endl << endl;
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                                            choice = 0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            if (count == 0)
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Account Not Found (or) Invalid Transaction Password!" << endl;
                                            }
                                        }
                                        break;

                                        case '4':
                                        {
                                            int count = 0;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            vector<Account> ACCOUNTS = branch[3].getAccounts();
                                            cout << "Enter Account Number (or) IBAN Number to Transfer Amount : ";
                                            string accountIBANNumber;
                                            cin >> accountIBANNumber;
                                            for (int k = 0; k < branch[3].getNumberOfAccounts(); ++k)
                                            {
                                                if ((ACCOUNTS[k].GetAccountNumber() == accountIBANNumber && ACCOUNTS[k].GetAccountNumber() != ACCount.GetAccountNumber()) || (ACCOUNTS[k].GetIBAN_Number() == accountIBANNumber && ACCOUNTS[k].GetIBAN_Number() != ACCount.GetIBAN_Number()))
                                                {
                                                    Account ACCOUNT = ACCOUNTS[k];
                                                    cout << "Enter Amount You want to Transfer : Rs.";
                                                    double amount;
                                                    cin >> amount;
                                                    cout << "Enter Purpose of Transfer : ";
                                                    string purpose;
                                                    cin.ignore();
                                                    getline(cin, purpose);
                                                    cout << "Enter Your Transaction Password : ";
                                                    string transactionPassword;
                                                    cin >> transactionPassword;
                                                    if (ACCount.GetTransactionPassword() == transactionPassword)
                                                    {
                                                        count++;
                                                        if(ACCount.GetBalance()<amount)
                                                        {
                                                            SetConsoleColor(FOREGROUND_RED);
                                                            cout<<"Insufficient Balance!"<<endl;
                                                        }
                                                        else
                                                        {
                                                            string purpose1 = "To Account (" + ACCOUNT.GetIBAN_Number() + ") for " + purpose;
                                                            string purpose2 = "From Account (" + ACCount.GetIBAN_Number() + ") for " + purpose;
                                                            ACCount.UpdateBalance(ACCount.GetBalance()-amount);
                                                            ACCOUNT.UpdateBalance(ACCOUNT.GetBalance()+amount);
                                                            ACCount.updateTransactionsHistory(purpose1,amount);
                                                            ACCOUNT.updateTransactionsHistory(purpose2,amount);
                                                            ACCount.UpdateNumTransactions();
                                                            ACCOUNT.UpdateNumTransactions();
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                            branch[3].deleteAccount(ACCOUNT);
                                                            branch[3].addAccount(ACCOUNT);
                                                            cout << "Amount Rs." << amount << " Transfered to Account " << ACCOUNT.GetName() << "(" << ACCOUNT.GetIBAN_Number() << ") from " << ACCount.GetName() << "(" << ACCount.GetIBAN_Number() << ")" << endl << endl;
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                                            choice=0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            if (count == 0)
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Account Not Found (or) Invalid Transaction Password!" << endl;
                                            }
                                        }
                                        break;

                                        case '5':
                                        {
                                            int count = 0;
                                            SetConsoleColor(FOREGROUND_BLUE);
                                            vector<Account> ACCOUNTS = branch[4].getAccounts();
                                            cout << "Enter Account Number (or) IBAN Number to Transfer Amount : ";
                                            string accountIBANNumber;
                                            cin >> accountIBANNumber;
                                            for (int k = 0; k < branch[4].getNumberOfAccounts(); ++k)
                                            {
                                                if ((ACCOUNTS[k].GetAccountNumber() == accountIBANNumber && ACCOUNTS[k].GetAccountNumber() != ACCount.GetAccountNumber()) || (ACCOUNTS[k].GetIBAN_Number() == accountIBANNumber && ACCOUNTS[k].GetIBAN_Number() != ACCount.GetIBAN_Number()))
                                                {
                                                    Account ACCOUNT = ACCOUNTS[k];
                                                    cout << "Enter Amount You want to Transfer : Rs.";
                                                    long long int amount;
                                                    cin >> amount;
                                                    cout << "Enter Purpose of Transfer : ";
                                                    string purpose;
                                                    cin.ignore();
                                                    getline(cin, purpose);
                                                    cout << "Enter Your Transaction Password : ";
                                                    string transactionPassword;
                                                    cin >> transactionPassword;
                                                    if (ACCount.GetTransactionPassword() == transactionPassword)
                                                    {
                                                        count++;
                                                        if(ACCount.GetBalance()<amount)
                                                        {
                                                            SetConsoleColor(FOREGROUND_RED);
                                                            cout<<"Insufficient Balance!"<<endl;
                                                        }
                                                        else
                                                        {
                                                            string purpose1 = "To Account (" + ACCOUNT.GetIBAN_Number() + ") for " + purpose;
                                                            string purpose2 = "From Account (" + ACCount.GetIBAN_Number() + ") for " + purpose;
                                                            ACCount.UpdateBalance(ACCount.GetBalance()-amount);
                                                            ACCOUNT.UpdateBalance(ACCOUNT.GetBalance()+amount);
                                                            ACCount.updateTransactionsHistory(purpose1,amount);
                                                            ACCOUNT.updateTransactionsHistory(purpose2,amount);
                                                            ACCount.UpdateNumTransactions();
                                                            ACCOUNT.UpdateNumTransactions();
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                            branch[4].deleteAccount(ACCOUNT);
                                                            branch[4].addAccount(ACCOUNT);
                                                            cout << "Amount Rs." << amount << " Transfered to Account " << ACCOUNT.GetName() << "(" << ACCOUNT.GetIBAN_Number() << ") from " << ACCount.GetName() << "(" << ACCount.GetIBAN_Number() << ")" << endl << endl;
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                                            choice=0;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            if (count == 0)
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout << "Account Not Found (or) Invalid Transaction Password!" << endl;
                                            }
                                        }
                                        break;

                                        default:
                                            SetConsoleColor(FOREGROUND_RED);
                                            cout << "Invalid Input!" << endl;
                                        }
                                        break;
                                    }

                                    case 'F':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        ACCount.DisplayTransactionDetails();
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'G':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "Branch Code : " << branch[i].getBranchCode() << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'H':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        bool confirm = false;
                                        string passWord;
                                        cout << "Enter New Login Password : ";
                                        cin >> passWord;
                                        if (GetPasswordValidity(passWord))
                                        {
                                            cout << "Press (1) to Confirm Login Password" << endl
                                                 << "Press (0) to Go Back" << endl;
                                            cin >> confirm;
                                            if (confirm)
                                            {
                                                ACCount.SetPassword(passWord);
                                                SetConsoleColor(FOREGROUND_GREEN);
                                                cout << "Login Password Changes Successfully!" << endl;
                                            }
                                            else
                                                break;
                                        }
                                        else
                                        {
                                            SetConsoleColor(FOREGROUND_RED);
                                            cout << "Invalid Password Pattern! (Valid->8 to 16 Characters with Mixed Number and Alphabets or Special Characters)" << endl;
                                        }
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'I':
                                    {
                                        // Account Deletion Process //
                                        bool flag10 = false;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl
                                             << endl;
                                        SetConsoleColor(FOREGROUND_RED);
                                        cout << "Press (1) to Confirm Account Closing" << endl
                                             << "Press (0) to Go Back" << endl;
                                        cin >> flag10;
                                        if (flag10)
                                        {
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Account Closed and Deleted Successfully!" << endl;
                                            cout << "You are Requested to Withdraw the Amount of Rs." << ACCount.GetBalance() << " From the Branch " << branch[i].getBranchName() << endl;
                                            cout << "Thank You! It was Good Time Serving You..." << endl;
                                            choice = 0;
                                        }
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'J':
                                    { // Branch Transfer
                                        char chooseBranch;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "     Select Any Branch to Transfer your Account      " << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "     Press (1) to Transfer Account Account in Gulshan Branch" << endl
                                             << "     Press (2) to Transfer Account in Defence Branch" << endl
                                             << "     Press (3) to Transfer Account in FAST-NUCES Main Campus Branch" << endl
                                             << "     Press (4) to Transfer Account in Nazimabad Branch" << endl
                                             << "     Press (5) to Transfer Account in PECHS Branch" << endl;
                                        cin >> chooseBranch;
                                        switch (chooseBranch)
                                        {
                                        case '1':
                                            branch[0].addAccount(ACCount);
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Branch Changed to Gulshan Branch Successfully!" << endl;
                                            choice = '0';
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                            break;
                                        case '2':
                                            branch[1].addAccount(ACCount);
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Branch Changed to Defence Branch Successfully!" << endl;
                                            choice = '0';
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                            break;
                                        case '3':
                                            branch[2].addAccount(ACCount);
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Branch Changed to FAST-NUCES Main Campus Successfully!" << endl;
                                            choice = '0';
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                            break;
                                        case '4':
                                            branch[3].addAccount(ACCount);
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Branch Changed to Nazimabad Branch Successfully!" << endl;
                                            choice = '0';
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                            break;
                                        case '5':
                                            branch[4].addAccount(ACCount);
                                            branch[i].deleteAccount(ACCount);
                                            cout << "Branch Changed to PECHS Branch Successfully!" << endl;
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                            choice = '0';
                                            break;
                                        default:
                                            cout << "Invalid Input" << endl;
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                        }
                                        break;
                                    }

                                    case 'K':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "Branch Manager Name : " << branch[i].getBranchManager() << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'L':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "Branch Contact Number : " << branch[i].getBranchContactNumber() << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'M':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout << "Branch Location : " << branch[i].getBranchLocation() << endl;
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        break;
                                    }

                                    case 'N':
                                    {
                                        SetConsoleColor(FOREGROUND_GREEN);
                                        cout << "-------------------------------------------------------------------------------------" << endl;
                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout<<"Enter Debit Card New PIN : ";
                                        string pin;
                                        cin>>pin;
                                        if(ValidatePin(pin))
                                        {
                                            SetConsoleColor(FOREGROUND_RED);
                                            cout<<"Press (1) to Confirm New PIN"<<endl<<"Press (0) to Go Back"<<endl;
                                            bool FLag;
                                            cin>>FLag;
                                            if(!FLag)
                                            continue;
                                            ACCount.SetDebitCardPIN(pin);
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout<<"Debit Card PIN Changed Successfully!"<<endl;
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                        }
                                        else
                                        {
                                            SetConsoleColor(FOREGROUND_RED);
                                            cout<<"Invalid Debit Card Pattern!"<<endl<<"Enter 4 Digits PIN!"<<endl;
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout << "-------------------------------------------------------------------------------------" << endl;
                                        }
                                    }

                                    case 'O':
                                    {
                                        loan_display:
                                        int TypeLoanChoice;
                                        int CarLoanChoice;
                                        int HomeLoanChoice;
                                        int healthLoanChoice;
                                        int educationalLoanChoice;
                                        double InterestRate;
                                        int Year;
                                        double Amount;
                                        
                                        SetConsoleColor(FOREGROUND_RED);
                                        
                                        cout<<"|<          Welcome To FAST LOAN SERVICES              >|"<<endl<<endl;
                                        cout<<"Here Below Are Loans Provided By Fast Bank"<<endl;
                                        cout<<"|<          (1)  Fast Car Loan System                  >|"<<endl;
                                        cout<<"|<          (2)  Fast Home Loan System                 >|"<<endl; 
                                        cout<<"|<          (3)  Fast Health Loan System               >|"<<endl; 
                                        cout<<"|<          (4)  Fast Education Loan System            >|"<<endl; 

                                        SetConsoleColor(FOREGROUND_BLUE);
                                        cout<<endl<<endl<<"Enter The Type of Loan You Want to Buy Accordng To Sequence Mentioned above(Enter 0 to Return Back): ";
                                        cin>>TypeLoanChoice;

                                        loan.SetAccountForLoan(&ACCount);
                                        while (TypeLoanChoice>=0 || TypeLoanChoice<=4){
                                        switch(TypeLoanChoice){
                                            case 0:
                                            {
                                                SetConsoleColor(FOREGROUND_GREEN);
                                                cout<<"Thanks For Visiting Fast Loan Services"<<endl;
                                                goto end_loop;
                                                break;
                                            }
                                            case 1:
                                            {
                                                loan.showCarLoanDetails();
                                                SetConsoleColor(FOREGROUND_BLUE);
                                                cout<<"Enter the Deal You Want to Choose accoring to sequence mentioned above (Enter 0 to Return Back): "<<endl;
                                                cin>>CarLoanChoice;
                                                
                                                while (CarLoanChoice>=0 || CarLoanChoice<=4){
                                                switch(CarLoanChoice){
                                                    case 0:
                                                    {
                                                        SetConsoleColor(FOREGROUND_GREEN);
                                                        cout<<"Thanks For Visiting Fast Car Loan Services"<<endl;
                                                        goto end_loop;
                                                    }
                                                    case 1:{
                                                        InterestRate=8.5;
                                                        Amount=2000000;
                                                        Year=4;
                                                        if (loan.isCarLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(20,Amount);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 2 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Thanks For Buying Car Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                    
                                                        break;

                                                    case 2:{
                                                        InterestRate=7;
                                                        Amount=1500000;
                                                        Year=3;
                                                        if (loan.isCarLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(20,Amount);
                                                            ACCount.DepositAmount(Amount-loan.getDownPayment(15,Amount));
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 1.5 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Car Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }

                                                        break;
                                                    }
                                                    
                                                    case 3:
                                                    {
                                                        InterestRate=10;
                                                        Amount=3000000;
                                                        Year=7;
                                                        if (loan.isCarLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(10,Amount);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 3 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Car Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                        break;


                                                    }
                                                    default:
                                                        SetConsoleColor(FOREGROUND_RED);
                                                        cout<<"Invalid Input. Please Enter again!"<<endl;
                                                        goto loan_display;

                                                    }
                                                }
                                            }
                                            break;
                                            }
                                            case 2:
                                            {
                                                long int propertyWorth;
                                                loan.showHomeLoanDetails();
                                                SetConsoleColor(FOREGROUND_BLUE);
                                                cout<<"Enter the Deal You Want to Choose accoring to sequence mentioned above (Enter 0 to Return Back): "<<endl;
                                                cin>>HomeLoanChoice;

                                                cout<<"Enter the Property Worth: ";
                                                cin>>propertyWorth;
                                                
                                                while (HomeLoanChoice>=0 || HomeLoanChoice<=4){
                                                switch(HomeLoanChoice){
                                                    case 0:
                                                    {
                                                        SetConsoleColor(FOREGROUND_GREEN);
                                                        cout<<"Thanks For Visiting Fast Health Loan Services"<<endl;
                                                        goto end_loop;
                                                    }
                                                    case 1:{
                                                        InterestRate=7.5;
                                                        Amount=10000000;
                                                        Year=15;
                                                        if (loan.isHomeLoanEligible() || (!ACCount.getLoanExistance()) || getAge(year)>=21){
                                                            ACCount.deductDownPaymentAmount(20,propertyWorth);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 10 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Home Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                    
                                                        break;

                                                    case 2:{
                                                        InterestRate=8.25;
                                                        Amount=15000000;
                                                        Year=20;
                                                        if (loan.isCarLoanEligible() || (!ACCount.getLoanExistance()) || getAge(year)>=21){
                                                            ACCount.deductDownPaymentAmount(15,propertyWorth);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 15 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Home Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }

                                                        break;
                                                    }
                                                    
                                                    case 3:
                                                    {
                                                        InterestRate=8.75;
                                                        Amount=20000000;
                                                        Year=20;
                                                        if (loan.isHomeLoanEligible() || (!ACCount.getLoanExistance()) || getAge(year)>=21){
                                                            ACCount.deductDownPaymentAmount(10,propertyWorth);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 3 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Home Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                        break;


                                                    }
                                                    default:
                                                        SetConsoleColor(FOREGROUND_RED);
                                                        cout<<"Invalid Input. Please Enter again!"<<endl;
                                                        goto loan_display;

                                                    }
                                                }
                                            }
                                            break;
                                            }

                                            case 3:
                                            {
                                                loan.showHealthLoanDetails();
                                                SetConsoleColor(FOREGROUND_BLUE);
                                                cout<<"Enter the Deal You Want to Choose accoring to sequence mentioned above (Enter 0 to Return Back): "<<endl;
                                                cin>>healthLoanChoice;
                                                
                                                while (healthLoanChoice>=0 || healthLoanChoice<=4){
                                                switch(healthLoanChoice){
                                                    case 0:
                                                    {
                                                        SetConsoleColor(FOREGROUND_GREEN);
                                                        cout<<"Thanks For Visiting Fast Health Loan Services"<<endl;
                                                        goto end_loop;
                                                    }
                                                    case 1:{
                                                        InterestRate=5;
                                                        Amount=500000;
                                                        Year=10;
                                                        if (loan.isHealthLoanEligible() || !ACCount.getLoanExistance() || (getAge(year)>=21 && getAge(year)<=60)){
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 5 Lakh Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Health Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                    
                                                        break;

                                                    case 2:{
                                                        InterestRate=7;
                                                        Amount=1000000;
                                                        Year=15;
                                                        if (loan.isHealthLoanEligible() || (!ACCount.getLoanExistance()) || (getAge(year)>=21) && getAge(year)<=60){
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 1 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Health Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }

                                                        break;
                                                    }
                                                    
                                                    case 3:
                                                    {
                                                        InterestRate=7;
                                                        Amount=2000000;
                                                        Year=20;
                                                        if (loan.isHealthLoanEligible() || (!ACCount.getLoanExistance()) || (getAge(year)>=21 && getAge(year)<=60)){
                                                            ACCount.deductDownPaymentAmount(10,Amount);
                                                            ACCount.DepositAmount(Amount-loan.getDownPayment(10,Amount));
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 2 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Health Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                        break;


                                                    }
                                                    default:
                                                        SetConsoleColor(FOREGROUND_RED);
                                                        cout<<"Invalid Input. Please Enter again!"<<endl;
                                                        goto loan_display;

                                                    }
                                                }
                                            }
                                            break;
                                            }
                                            case 4:
                                            {
                                                 loan.showEducationLoanDetails();
                                                 SetConsoleColor(FOREGROUND_BLUE);
                                                cout<<"Enter the Deal You Want to Choose accoring to sequence mentioned above (Enter 0 to Return Back): "<<endl;
                                                cin>>educationalLoanChoice;
                                                
                                                while (educationalLoanChoice>=0 || educationalLoanChoice<=4){
                                                switch(educationalLoanChoice){
                                                    case 0:
                                                    {
                                                        SetConsoleColor(FOREGROUND_GREEN);
                                                        cout<<"Thanks For Visiting Fast Car Loan Services"<<endl;
                                                        goto end_loop;
                                                    }
                                                    case 1:{
                                                        InterestRate=8.25;
                                                        Amount=2500000;
                                                        Year=10;
                                                        if (loan.isEducationLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(20,Amount);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 2.5 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Education Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                    
                                                        break;

                                                    case 2:{
                                                        InterestRate=7.5;
                                                        Amount=3500000;
                                                        Year=15;
                                                        if (loan.isEducationLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(20,Amount);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 3.5 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Education Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }

                                                        break;
                                                    }
                                                    
                                                    case 3:
                                                    {
                                                        InterestRate=8.25;
                                                        Amount=4500000;
                                                        Year=7;
                                                        if (loan.isEducationLoanEligible() || (!ACCount.getLoanExistance())){
                                                            ACCount.deductDownPaymentAmount(10,Amount);
                                                            ACCount.DepositAmount(Amount);
                                                            ACCount.setLoanExistance(true);
                                                            perMonthAmount=loan.calculatePerMonthAmount(InterestRate,Year,Amount);

                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Congratulations. PKR 4.5 Million Has Been succesfully Transfered to your account!"<<endl;
                                                            cout<<"You Have to Pay PKR "<<perMonthAmount<<" each Month"<<endl;
                                                            cout<<"Failure To Pay Loan before Due Date will result in automatic deduction of amount from your account with 1% additional Interest Rate!"<<endl;
                                                            cout<<"Thanks For Buying Education Loan From Fast Bank!"<<endl;
                                                            branch[i].deleteAccount(ACCount);
                                                            branch[i].addAccount(ACCount);
                                                        }
                                                        else{
                                                            SetConsoleColor(FOREGROUND_GREEN);
                                                            cout<<"Thanks For Visiting!"<<endl;
                                                            goto end_loop;
                                                        }
                                                        break;


                                                    }
                                                    default:
                                                        SetConsoleColor(FOREGROUND_RED);
                                                        cout<<"Invalid Input. Please Enter again!"<<endl;
                                                        goto loan_display;

                                                    }
                                                }
                                            }
                                            break;
                                            }

                                            default:
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout<<"Invalid Input. Please Enter Again!"<<endl;
                                                goto loan_display;
                                            }
                                        }
                                    }
                                    break;    
                                    }

                                    case 'P':
                                    {
                                        long int B=ACCount.GetBalance();
                                        if(ACCount.getLoanExistance())
                                        {
                                            if (loan.BalanceOverInstallment(perMonthAmount,B))
                                            {
                                                ACCount.setLoanAmount(perMonthAmount);
                                                SetConsoleColor(FOREGROUND_GREEN);
                                                cout<<"PKR "<<perMonthAmount<<" has been deducted from your account successfully!"<<endl;
                                                branch[i].deleteAccount(ACCount);
                                                branch[i].addAccount(ACCount);
                                                goto end_loop;
                                            }
                                            else
                                            {
                                                SetConsoleColor(FOREGROUND_RED);
                                                cout<<"Sorry! You Dont have enough balance to pay loan!"<<endl;
                                            }
                                        }
                                        else
                                        {
                                            SetConsoleColor(FOREGROUND_GREEN);
                                            cout<<"You Don't have any Loan to Pay"<<endl;
                                        }
                                        break;
                                    }

                                    case '0':
                                    {
                                        break;
                                    }
                                    default:
                                    {
                                        SetConsoleColor(FOREGROUND_RED);
                                        cout << "Invalid Input! Re-Enter" << endl;
                                    }
                                    }
                                }
                            }
                            if(isFound)
                            break;
                        }
                    }
                }
                if (!isFound)
                {
                    SetConsoleColor(FOREGROUND_RED);
                    cout << "Account Not Found (or) Invalid Email or Password!" << endl;
                }
            }
        }
        break;

        case '2':
        {
            bool Continue = false;
            SetConsoleColor(FOREGROUND_RED);
            cout << "Press (1) to Confirm Proceeding Sign-up" << endl
                 << "Press (0) to Get to the Home Page" << endl;
            cin >> Continue;
            if (!Continue)
                break;
            char chooseBranch;
            SetConsoleColor(FOREGROUND_RED);
            cout << "Press (1) to Open Account Account in Gulshan Branch" << endl
                 << "Press (2) to Open Account in Defence Branch" << endl
                 << "Press (3) to Open Account in FAST-NUCES Main Campus Branch" << endl
                 << "Press (4) to Open Account in Nazimabad Branch" << endl
                 << "Press (5) to Open Account in PECHS Branch" << endl;
            cin >> chooseBranch;
            switch (chooseBranch) // Branch 1
            {
                case '1':
                {
                    vector<Account> AccounT = branch[0].getAccounts();
                    Account account;
                    // Set Name
                    string name;
                    bool flag = false;
                    while (!flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Account Holder Name : ";
                        cin.ignore();
                        getline(cin, name);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Confirm Name" << endl
                            << "Press (0) to Re-Enter" << endl;
                        cin >> flag;
                        if (flag)
                        {
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Holder Name Set Successfully!" << endl;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Enter Again!" << endl;
                        }
                    }
                    account.SetName(name);

                    // Set CNIC Number
                    string CNIC_Number;
                    bool flag1 = false;

                    while (!flag1)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number (#####-#######-#) : ";
                        cin >> CNIC_Number;
                        if (VerifyCNIC(CNIC_Number) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm CNIC"<<endl<<"Press (0) to Re-Enter"<<endl;
                            cin>>flag1;
                            if(flag1)
                            {
                                account.SetCNIC(CNIC_Number);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "CNIC Number Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter CNIC Number"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid CNIC Number! Enter Again!" << endl;
                        }
                    }

                    // Set Mr and Ms for Gender
                    char num = CNIC_Number[CNIC_Number.size() - 1];
                    int digit = num - '0';
                    string Gender;
                    SetConsoleColor(FOREGROUND_RED);
                    if (digit % 2 == 0)
                    {
                        account.SetGender("Ms");
                    }
                    else
                    {
                        account.SetGender("Mr");
                    }
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Gender Set Successfully!" << endl;

                    // Set Email
                    bool Flag = false;
                    string Email;
                    while (!Flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Email (______________@gmail.com) : ";
                        cin >> Email;
                        int found = 0;
                        for (int k = 0; k < branch[0].getNumberOfAccounts(); ++k)
                        {
                            if (AccounT[k].GetEmail() == Email)
                                ++found;
                        }
                        if (ValidateEmail(Email) == true && found == 0)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm Email"<<endl<<"Press (0) to Enter Again"<<endl;
                            cin>>Flag;
                            if(Flag)
                            {
                                account.SetEmail(Email);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Email Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter Email"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Email! (or) Email Already Used!" << endl
                                << " Enter Again!" << endl;
                        }
                    }

                    // Set Cell Number
                    bool FLAG = false;
                    string CellNumber;
                    while (!FLAG)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Cell Phone Number(03##-#######) : ";
                        cin >> CellNumber;
                        cout<<endl;
                        if (ValidateCellNumber(CellNumber) == true)
                        {
                            account.SetCellNumber(CellNumber);
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Cell Number Set Successfully!" << endl;
                            FLAG = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Cell Number must be in Pattern-->[03##-#######]..." << endl
                                << "Re-Enter" << endl;
                        }
                    }

                    // Set Date of Birth
                    int day, month;
                    bool flag2 = false;
                    while (!flag2)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Your Day of Birth : ";
                        cin >> day;
                        cout << "Enter Your Month of Birth : ";
                        cin >> month;
                        cout << "Entr Your Year of Birth :  ";
                        cin >> year;

                        if (DateOfBirthValidity(day, month, year) == true)
                        {
                            account.SetDateOfBirth(GetDateOfBirth(day, month, year));
                            flag2 = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Date! Enter Again!" << endl;
                        }
                    }

                    // Set Account Type
                    char Choice = '3';
                    while (Choice != '1' && Choice != '2')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Open Current Account" << endl
                            << "Press (2) to Open Saving Account" << endl;
                        cin >> Choice;

                        switch (Choice)
                        {
                        case '1':
                            account.SetAccountType("Current");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        case '2':
                            account.SetAccountType("Saving");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Choice! Enter Again!" << endl;
                        }
                    }

                    SetConsoleColor(FOREGROUND_GREEN);
                    // Account Number Assign
                    account.SetAccountNumber(GenerateAccountNumber());
                    cout << "Account Number Issued!" << endl;
                    // IBAN Number Assign
                    account.SetIBAN_Number(GenerateIBAN_Number());
                    cout << "IBAN Number Issued!" << endl;

                    // Select Debit Card Category
                    char Category = '4';
                    while (Category != '1' && Category != '2' && Category != '3')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) for Silver Visa Virtual Debit Card(Rs.1500/Year)" << endl
                            << "Press (2) for Gold Visa Virtual Debit Card(Rs.2500/Year)" << endl
                            << "Press (3) for Platinum Visa Debit Card(Rs.3500/Year)" << endl;
                        cin >> Category;

                        switch (Category)
                        {
                        case '1':
                            account.SetDebitCardCategory(" Silver ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '2':
                            account.SetDebitCardCategory("  Gold  ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '3':
                            account.SetDebitCardCategory("Platinum");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Entry Try Again!" << endl;
                        }
                    }

                    // Debit Card Assign
                    account.DebitCard(GenerateVirtualDebitCard());

                    // Debit Card PIN Set
                    bool flag3 = false;
                    string pin;
                    SetConsoleColor(FOREGROUND_BLUE);
                    cout << "Set Virtual Debit Card : " << endl;
                    while (!flag3)
                    {
                        cout << "Set Virtual Debit Card PIN(####) : ";
                        cin >> pin;
                        if (ValidatePin(pin) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm PIN" << endl
                                << "Press (0) to Enter Again!" << endl;
                            cin >> flag3;
                            if (flag3)
                            {
                                account.SetDebitCardPIN(pin);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Virtual Debit Card PIN Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid PIN Pattern! Enter Again!" << endl;
                        }
                    }
                    cout << "Virtual Debit Card Issued!" << endl;

                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Virtual Debit Card Issued on : " << GetCurrentDate() << endl;
                    account.SetDebitCardIssueDate(GetCurrentDate());
                    account.SetDebitCardExpireDate(DebitCardExpiry());
                    account.SetDebitCardCVV(GenerateCVV());
                    cout << "Account Opening Date : " << GetCurrentDate() << endl;

                    // Set Password
                    bool flag5 = false;
                    string Password;
                    while (!flag5)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Your Password of minimum 8 Characters : ";
                        cin >> Password;
                        if (GetPasswordValidity(Password) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Password" << endl
                                << "Press (0) to Re-Enter" << endl;
                            cin >> flag5;
                            if (flag5)
                            {
                                account.SetPassword(Password);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Password Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters" << endl;
                        }
                    }

                    // Set Transaction Password
                    string TransPassword;
                    bool flag7 = false;
                    while (!flag7)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Transaction Password : ";
                        cin >> TransPassword;
                        if (ValidateTransactionPassword(TransPassword) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Transaction Password" << endl
                                << "Press (0) to Enter Again" << endl;
                            cin >> flag7;
                            if (flag7)
                            {
                                account.SetTransactionPassword(TransPassword);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Transaction Password Set Successfully!" << endl;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Password must be of minimum 8 characters and without gap! Re-Enter" << endl;
                        }
                    }
                    branch[0].addAccount(account);
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout<<"-----<Account Created Successfully>-----"<<endl;
                }
                break;

                case '2': // Branch 2
                {
                    vector<Account> AccounT = branch[1].getAccounts();
                    Account account;
                    // Set Name
                    string name;
                    bool flag = false;
                    while (!flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Account Holder Name : ";
                        cin.ignore();
                        getline(cin, name);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Confirm Name" << endl
                            << "Press (0) to Re-Enter" << endl;
                        cin >> flag;
                        if (flag)
                        {
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Holder Name Set Successfully!" << endl;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Enter Again!" << endl;
                        }
                    }
                    account.SetName(name);

                    // Set CNIC Number
                    string CNIC_Number;
                    bool flag1 = false;

                    while (!flag1)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number (#####-#######-#) : ";
                        cin >> CNIC_Number;
                        if (VerifyCNIC(CNIC_Number) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm CNIC"<<endl<<"Press (0) to Re-Enter"<<endl;
                            cin>>flag1;
                            if(flag1)
                            {
                                account.SetCNIC(CNIC_Number);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "CNIC Number Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter CNIC Number"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid CNIC Number! Enter Again!" << endl;
                        }
                    }

                    // Set Mr and Ms for Gender
                    char num = CNIC_Number[CNIC_Number.size() - 1];
                    int digit = num - '0';
                    string Gender;
                    SetConsoleColor(FOREGROUND_RED);
                    if (digit % 2 == 0)
                    {
                        account.SetGender("Ms");
                    }
                    else
                    {
                        account.SetGender("Mr");
                    }
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Gender Set Successfully!" << endl;

                    // Set Email
                    bool Flag = false;
                    string Email;
                    while (!Flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Email (______________@gmail.com) : ";
                        cin >> Email;
                        int found = 0;
                        for (int k = 0; k < branch[1].getNumberOfAccounts(); ++k)
                        {
                            if (AccounT[k].GetEmail() == Email)
                                ++found;
                        }
                        if (ValidateEmail(Email) == true && found == 0)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm Email"<<endl<<"Press (0) to Enter Again"<<endl;
                            cin>>Flag;
                            if(Flag)
                            {
                                account.SetEmail(Email);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Email Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter Email"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Email! (or) Email Already Used!" << endl
                                << " Enter Again!" << endl;
                        }
                    }

                    // Set Cell Number
                    bool FLAG = false;
                    string CellNumber;
                    while (!FLAG)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Cell Phone Number(03##-#######) : ";
                        cin >> CellNumber;
                        cout<<endl;
                        if (ValidateCellNumber(CellNumber) == true)
                        {
                            account.SetCellNumber(CellNumber);
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Cell Number Set Successfully!" << endl;
                            FLAG = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Cell Number must be in Pattern-->[03##-#######]..." << endl
                                << "Re-Enter" << endl;
                        }
                    }

                    // Set Date of Birth
                    int day, month, year;
                    bool flag2 = false;
                    while (!flag2)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Your Day of Birth : ";
                        cin >> day;
                        cout << "Enter Your Month of Birth : ";
                        cin >> month;
                        cout << "Entr Your Year of Birth :  ";
                        cin >> year;

                        if (DateOfBirthValidity(day, month, year) == true)
                        {
                            account.SetDateOfBirth(GetDateOfBirth(day, month, year));
                            flag2 = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Date! Enter Again!" << endl;
                        }
                    }

                    // Set Account Type
                    char Choice = '3';
                    while (Choice != '1' && Choice != '2')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Open Current Account" << endl
                            << "Press (2) to Open Saving Account" << endl;
                        cin >> Choice;

                        switch (Choice)
                        {
                        case '1':
                            account.SetAccountType("Current");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        case '2':
                            account.SetAccountType("Saving");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Choice! Enter Again!" << endl;
                        }
                    }

                    SetConsoleColor(FOREGROUND_GREEN);
                    // Account Number Assign
                    account.SetAccountNumber(GenerateAccountNumber());
                    cout << "Account Number Issued!" << endl;
                    // IBAN Number Assign
                    account.SetIBAN_Number(GenerateIBAN_Number());
                    cout << "IBAN Number Issued!" << endl;

                    // Select Debit Card Category
                    char Category = '4';
                    while (Category != '1' && Category != '2' && Category != '3')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) for Silver Visa Virtual Debit Card(Rs.1500/Year)" << endl
                            << "Press (2) for Gold Visa Virtual Debit Card(Rs.2500/Year)" << endl
                            << "Press (3) for Platinum Visa Debit Card(Rs.3500/Year)" << endl;
                        cin >> Category;

                        switch (Category)
                        {
                        case '1':
                            account.SetDebitCardCategory(" Silver ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '2':
                            account.SetDebitCardCategory("  Gold  ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '3':
                            account.SetDebitCardCategory("Platinum");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Entry Try Again!" << endl;
                        }
                    }

                    // Debit Card Assign
                    account.DebitCard(GenerateVirtualDebitCard());

                    // Debit Card PIN Set
                    bool flag3 = false;
                    string pin;
                    SetConsoleColor(FOREGROUND_BLUE);
                    cout << "Set Virtual Debit Card : " << endl;
                    while (!flag3)
                    {
                        cout << "Set Virtual Debit Card PIN(####) : ";
                        cin >> pin;
                        if (ValidatePin(pin) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm PIN" << endl
                                << "Press (0) to Enter Again!" << endl;
                            cin >> flag3;
                            if (flag3)
                            {
                                account.SetDebitCardPIN(pin);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Virtual Debit Card PIN Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid PIN Pattern! Enter Again!" << endl;
                        }
                    }
                    cout << "Virtual Debit Card Issued!" << endl;

                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Virtual Debit Card Issued on : " << GetCurrentDate() << endl;
                    account.SetDebitCardIssueDate(GetCurrentDate());
                    account.SetDebitCardExpireDate(DebitCardExpiry());
                    account.SetDebitCardCVV(GenerateCVV());
                    cout << "Account Opening Date : " << GetCurrentDate() << endl;

                    // Set Password
                    bool flag5 = false;
                    string Password;
                    while (!flag5)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Your Password of minimum 8 Characters : ";
                        cin >> Password;
                        if (GetPasswordValidity(Password) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Password" << endl
                                << "Press (0) to Re-Enter" << endl;
                            cin >> flag5;
                            if (flag5)
                            {
                                account.SetPassword(Password);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Password Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters" << endl;
                        }
                    }

                    // Set Transaction Password
                    string TransPassword;
                    bool flag7 = false;
                    while (!flag7)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Transaction Password : ";
                        cin >> TransPassword;
                        if (ValidateTransactionPassword(TransPassword) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Transaction Password" << endl
                                << "Press (0) to Enter Again" << endl;
                            cin >> flag7;
                            if (flag7)
                            {
                                account.SetTransactionPassword(TransPassword);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Transaction Password Set Successfully!" << endl;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Password must be of minimum 8 characters and without gap! Re-Enter" << endl;
                        }
                    }
                    branch[1].addAccount(account);
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout<<"-----<Account Created Successfully>-----"<<endl;
                }
                break;

                case '3': // Branch 3
                {
                    vector<Account> AccounT = branch[2].getAccounts();
                    Account account;
                    // Set Name
                    string name;
                    bool flag = false;
                    while (!flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Account Holder Name : ";
                        cin.ignore();
                        getline(cin, name);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Confirm Name" << endl
                            << "Press (0) to Re-Enter" << endl;
                        cin >> flag;
                        if (flag)
                        {
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Holder Name Set Successfully!" << endl;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Enter Again!" << endl;
                        }
                    }
                    account.SetName(name);

                    // Set CNIC Number
                    string CNIC_Number;
                    bool flag1 = false;

                    while (!flag1)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number (#####-#######-#) : ";
                        cin >> CNIC_Number;
                        if (VerifyCNIC(CNIC_Number) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm CNIC"<<endl<<"Press (0) to Re-Enter"<<endl;
                            cin>>flag1;
                            if(flag1)
                            {
                                account.SetCNIC(CNIC_Number);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "CNIC Number Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter CNIC Number"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid CNIC Number! Enter Again!" << endl;
                        }
                    }

                    // Set Mr and Ms for Gender
                    char num = CNIC_Number[CNIC_Number.size() - 1];
                    int digit = num - '0';
                    string Gender;
                    SetConsoleColor(FOREGROUND_RED);
                    if (digit % 2 == 0)
                    {
                        account.SetGender("Ms");
                    }
                    else
                    {
                        account.SetGender("Mr");
                    }
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Gender Set Successfully!" << endl;

                    // Set Email
                    bool Flag = false;
                    string Email;
                    while (!Flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Email (______________@gmail.com) : ";
                        cin >> Email;
                        int found = 0;
                        for (int k = 0; k < branch[2].getNumberOfAccounts(); ++k)
                        {
                            if (AccounT[k].GetEmail() == Email)
                                ++found;
                        }
                        if (ValidateEmail(Email) == true && found == 0)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm Email"<<endl<<"Press (0) to Enter Again"<<endl;
                            cin>>Flag;
                            if(Flag)
                            {
                                account.SetEmail(Email);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Email Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter Email"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Email! (or) Email Already Used!" << endl
                                << " Enter Again!" << endl;
                        }
                    }

                    // Set Cell Number
                    bool FLAG = false;
                    string CellNumber;
                    while (!FLAG)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Cell Phone Number(03##-#######) : ";
                        cin >> CellNumber;
                        cout<<endl;
                        if (ValidateCellNumber(CellNumber) == true)
                        {
                            account.SetCellNumber(CellNumber);
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Cell Number Set Successfully!" << endl;
                            FLAG = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Cell Number must be in Pattern-->[03##-#######]..." << endl
                                << "Re-Enter" << endl;
                        }
                    }

                    // Set Date of Birth
                    int day, month, year;
                    bool flag2 = false;
                    while (!flag2)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Your Day of Birth : ";
                        cin >> day;
                        cout << "Enter Your Month of Birth : ";
                        cin >> month;
                        cout << "Enter Your Year of Birth :  ";
                        cin >> year;

                        if (DateOfBirthValidity(day, month, year) == true)
                        {
                            account.SetDateOfBirth(GetDateOfBirth(day, month, year));
                            flag2 = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Date! Enter Again!" << endl;
                        }
                    }

                    // Set Account Type
                    char Choice = '3';
                    while (Choice != '1' && Choice != '2')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Open Current Account" << endl
                            << "Press (2) to Open Saving Account" << endl;
                        cin >> Choice;

                        switch (Choice)
                        {
                        case '1':
                            account.SetAccountType("Current");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        case '2':
                            account.SetAccountType("Saving");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Choice! Enter Again!" << endl;
                        }
                    }

                    SetConsoleColor(FOREGROUND_GREEN);
                    // Account Number Assign
                    account.SetAccountNumber(GenerateAccountNumber());
                    cout << "Account Number Issued!" << endl;
                    // IBAN Number Assign
                    account.SetIBAN_Number(GenerateIBAN_Number());
                    cout << "IBAN Number Issued!" << endl;

                    // Select Debit Card Category
                    char Category = '4';
                    while (Category != '1' && Category != '2' && Category != '3')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) for Silver Visa Virtual Debit Card(Rs.1500/Year)" << endl
                            << "Press (2) for Gold Visa Virtual Debit Card(Rs.2500/Year)" << endl
                            << "Press (3) for Platinum Visa Debit Card(Rs.3500/Year)" << endl;
                        cin >> Category;

                        switch (Category)
                        {
                        case '1':
                            account.SetDebitCardCategory(" Silver ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '2':
                            account.SetDebitCardCategory("  Gold  ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '3':
                            account.SetDebitCardCategory("Platinum");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Entry Try Again!" << endl;
                        }
                    }

                    // Debit Card Assign
                    account.DebitCard(GenerateVirtualDebitCard());

                    // Debit Card PIN Set
                    bool flag3 = false;
                    string pin;
                    SetConsoleColor(FOREGROUND_BLUE);
                    cout << "Set Virtual Debit Card : " << endl;
                    while (!flag3)
                    {
                        cout << "Set Virtual Debit Card PIN(####) : ";
                        cin >> pin;
                        if (ValidatePin(pin) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm PIN" << endl
                                << "Press (0) to Enter Again!" << endl;
                            cin >> flag3;
                            if (flag3)
                            {
                                account.SetDebitCardPIN(pin);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Virtual Debit Card PIN Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid PIN Pattern! Enter Again!" << endl;
                        }
                    }
                    cout << "Virtual Debit Card Issued!" << endl;

                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Virtual Debit Card Issued on : " << GetCurrentDate() << endl;
                    account.SetDebitCardIssueDate(GetCurrentDate());
                    account.SetDebitCardExpireDate(DebitCardExpiry());
                    account.SetDebitCardCVV(GenerateCVV());
                    cout << "Account Opening Date : " << GetCurrentDate() << endl;

                    // Set Password
                    bool flag5 = false;
                    string Password;
                    while (!flag5)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Your Password of minimum 8 Characters : ";
                        cin >> Password;
                        if (GetPasswordValidity(Password) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Password" << endl
                                << "Press (0) to Re-Enter" << endl;
                            cin >> flag5;
                            if (flag5)
                            {
                                account.SetPassword(Password);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Password Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters" << endl;
                        }
                    }

                    // Set Transaction Password
                    string TransPassword;
                    bool flag7 = false;
                    while (!flag7)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Transaction Password : ";
                        cin >> TransPassword;
                        if (ValidateTransactionPassword(TransPassword) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Transaction Password" << endl
                                << "Press (0) to Enter Again" << endl;
                            cin >> flag7;
                            if (flag7)
                            {
                                account.SetTransactionPassword(TransPassword);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Transaction Password Set Successfully!" << endl;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Password must be of minimum 8 characters and without gap! Re-Enter" << endl;
                        }
                    }
                    branch[2].addAccount(account);
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout<<"-----<Account Created Successfully>-----"<<endl;
                }
                break;

                case '4': // branch 4
                {
                    vector<Account> AccounT = branch[3].getAccounts();
                    Account account;
                    // Set Name
                    string name;
                    bool flag = false;
                    while (!flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Account Holder Name : ";
                        cin.ignore();
                        getline(cin, name);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Confirm Name" << endl
                            << "Press (0) to Re-Enter" << endl;
                        cin >> flag;
                        if (flag)
                        {
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Holder Name Set Successfully!" << endl;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Enter Again!" << endl;
                        }
                    }
                    account.SetName(name);

                    // Set CNIC Number
                    string CNIC_Number;
                    bool flag1 = false;

                    while (!flag1)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number (#####-#######-#) : ";
                        cin >> CNIC_Number;
                        if (VerifyCNIC(CNIC_Number) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm CNIC"<<endl<<"Press (0) to Re-Enter"<<endl;
                            cin>>flag1;
                            if(flag1)
                            {
                                account.SetCNIC(CNIC_Number);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "CNIC Number Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter CNIC Number"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid CNIC Number! Enter Again!" << endl;
                        }
                    }

                    // Set Mr and Ms for Gender
                    char num = CNIC_Number[CNIC_Number.size() - 1];
                    int digit = num - '0';
                    string Gender;
                    SetConsoleColor(FOREGROUND_RED);
                    if (digit % 2 == 0)
                    {
                        account.SetGender("Ms");
                    }
                    else
                    {
                        account.SetGender("Mr");
                    }
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Gender Set Successfully!" << endl;

                    // Set Email
                    bool Flag = false;
                    string Email;
                    while (!Flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Email (______________@gmail.com) : ";
                        cin >> Email;
                        int found = 0;
                        for (int k = 0; k < branch[3].getNumberOfAccounts(); ++k)
                        {
                            if (AccounT[k].GetEmail() == Email)
                                ++found;
                        }
                        if (ValidateEmail(Email) == true && found == 0)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm Email"<<endl<<"Press (0) to Enter Again"<<endl;
                            cin>>Flag;
                            if(Flag)
                            {
                                account.SetEmail(Email);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Email Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter Email"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Email! (or) Email Already Used!" << endl
                                << " Enter Again!" << endl;
                        }
                    }

                    // Set Cell Number
                    bool FLAG = false;
                    string CellNumber;
                    while (!FLAG)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Cell Phone Number(03##-#######) : ";
                        cin >> CellNumber;
                        cout<<endl;
                        if (ValidateCellNumber(CellNumber) == true)
                        {
                            account.SetCellNumber(CellNumber);
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Cell Number Set Successfully!" << endl;
                            FLAG = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Cell Number must be in Pattern-->[03##-#######]..." << endl
                                << "Re-Enter" << endl;
                        }
                    }

                    // Set Date of Birth
                    int day, month, year;
                    bool flag2 = false;
                    while (!flag2)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Your Day of Birth : ";
                        cin >> day;
                        cout << "Enter Your Month of Birth : ";
                        cin >> month;
                        cout << "Entr Your Year of Birth :  ";
                        cin >> year;

                        if (DateOfBirthValidity(day, month, year) == true)
                        {
                            account.SetDateOfBirth(GetDateOfBirth(day, month, year));
                            flag2 = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Date! Enter Again!" << endl;
                        }
                    }

                    // Set Account Type
                    char Choice = '3';
                    while (Choice != '1' && Choice != '2')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Open Current Account" << endl
                            << "Press (2) to Open Saving Account" << endl;
                        cin >> Choice;

                        switch (Choice)
                        {
                        case '1':
                            account.SetAccountType("Current");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        case '2':
                            account.SetAccountType("Saving");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Choice! Enter Again!" << endl;
                        }
                    }

                    SetConsoleColor(FOREGROUND_GREEN);
                    // Account Number Assign
                    account.SetAccountNumber(GenerateAccountNumber());
                    cout << "Account Number Issued!" << endl;
                    // IBAN Number Assign
                    account.SetIBAN_Number(GenerateIBAN_Number());
                    cout << "IBAN Number Issued!" << endl;

                    // Select Debit Card Category
                    char Category = '4';
                    while (Category != '1' && Category != '2' && Category != '3')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) for Silver Visa Virtual Debit Card(Rs.1500/Year)" << endl
                            << "Press (2) for Gold Visa Virtual Debit Card(Rs.2500/Year)" << endl
                            << "Press (3) for Platinum Visa Debit Card(Rs.3500/Year)" << endl;
                        cin >> Category;

                        switch (Category)
                        {
                        case '1':
                            account.SetDebitCardCategory(" Silver ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '2':
                            account.SetDebitCardCategory("  Gold  ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '3':
                            account.SetDebitCardCategory("Platinum");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Entry Try Again!" << endl;
                        }
                    }

                    // Debit Card Assign
                    account.DebitCard(GenerateVirtualDebitCard());

                    // Debit Card PIN Set
                    bool flag3 = false;
                    string pin;
                    SetConsoleColor(FOREGROUND_BLUE);
                    cout << "Set Virtual Debit Card : " << endl;
                    while (!flag3)
                    {
                        cout << "Set Virtual Debit Card PIN(####) : ";
                        cin >> pin;
                        if (ValidatePin(pin) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm PIN" << endl
                                << "Press (0) to Enter Again!" << endl;
                            cin >> flag3;
                            if (flag3)
                            {
                                account.SetDebitCardPIN(pin);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Virtual Debit Card PIN Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid PIN Pattern! Enter Again!" << endl;
                        }
                    }
                    cout << "Virtual Debit Card Issued!" << endl;

                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Virtual Debit Card Issued on : " << GetCurrentDate() << endl;
                    account.SetDebitCardIssueDate(GetCurrentDate());
                    account.SetDebitCardExpireDate(DebitCardExpiry());
                    account.SetDebitCardCVV(GenerateCVV());
                    cout << "Account Opening Date : " << GetCurrentDate() << endl;

                    // Set Password
                    bool flag5 = false;
                    string Password;
                    while (!flag5)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Your Password of minimum 8 Characters : ";
                        cin >> Password;
                        if (GetPasswordValidity(Password) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Password" << endl
                                << "Press (0) to Re-Enter" << endl;
                            cin >> flag5;
                            if (flag5)
                            {
                                account.SetPassword(Password);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Password Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters" << endl;
                        }
                    }

                    // Set Transaction Password
                    string TransPassword;
                    bool flag7 = false;
                    while (!flag7)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Transaction Password : ";
                        cin >> TransPassword;
                        if (ValidateTransactionPassword(TransPassword) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Transaction Password" << endl
                                << "Press (0) to Enter Again" << endl;
                            cin >> flag7;
                            if (flag7)
                            {
                                account.SetTransactionPassword(TransPassword);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Transaction Password Set Successfully!" << endl;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Password must be of minimum 8 characters and without gap! Re-Enter" << endl;
                        }
                    }
                    branch[3].addAccount(account);
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout<<"-----<Account Created Successfully>-----"<<endl;
                }
                break;

                case '5': // Branch 5
                {
                    vector<Account> AccounT = branch[4].getAccounts();
                    Account account;
                    // Set Name
                    string name;
                    bool flag = false;
                    while (!flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Account Holder Name : ";
                        cin.ignore();
                        getline(cin, name);
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Confirm Name" << endl
                            << "Press (0) to Re-Enter" << endl;
                        cin >> flag;
                        if (flag)
                        {
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Holder Name Set Successfully!" << endl;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Enter Again!" << endl;
                        }
                    }
                    account.SetName(name);

                    // Set CNIC Number
                    string CNIC_Number;
                    bool flag1 = false;

                    while (!flag1)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter CNIC Number (#####-#######-#) : ";
                        cin >> CNIC_Number;
                        if (VerifyCNIC(CNIC_Number) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm CNIC"<<endl<<"Press (0) to Re-Enter"<<endl;
                            cin>>flag1;
                            if(flag1)
                            {
                                account.SetCNIC(CNIC_Number);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "CNIC Number Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter CNIC Number"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid CNIC Number! Enter Again!" << endl;
                        }
                    }

                    // Set Mr and Ms for Gender
                    char num = CNIC_Number[CNIC_Number.size() - 1];
                    int digit = num - '0';
                    string Gender;
                    SetConsoleColor(FOREGROUND_RED);
                    if (digit % 2 == 0)
                    {
                        account.SetGender("Ms");
                    }
                    else
                    {
                        account.SetGender("Mr");
                    }
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Gender Set Successfully!" << endl;

                    // Set Email
                    bool Flag = false;
                    string Email;
                    while (!Flag)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Email (______________@gmail.com) : ";
                        cin >> Email;
                        int found = 0;
                        for (int k = 0; k < branch[4].getNumberOfAccounts(); ++k)
                        {
                            if (AccounT[k].GetEmail() == Email)
                                ++found;
                        }
                        if (ValidateEmail(Email) == true && found == 0)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout<<"Press (1) to Confirm Email"<<endl<<"Press (0) to Enter Again"<<endl;
                            cin>>Flag;
                            if(Flag)
                            {
                                account.SetEmail(Email);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Email Set Successfully!" << endl;
                            }
                            else
                            {
                                SetConsoleColor(FOREGROUND_RED);
                                cout<<"Re-Enter Email"<<endl;
                                continue;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Email! (or) Email Already Used!" << endl
                                << " Enter Again!" << endl;
                        }
                    }

                    // Set Cell Number
                    bool FLAG = false;
                    string CellNumber;
                    while (!FLAG)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Cell Phone Number(03##-#######) : ";
                        cin >> CellNumber;
                        cout<<endl;
                        if (ValidateCellNumber(CellNumber) == true)
                        {
                            account.SetCellNumber(CellNumber);
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Cell Number Set Successfully!" << endl;
                            FLAG = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Cell Number must be in Pattern-->[03##-#######]..." << endl
                                << "Re-Enter" << endl;
                        }
                    }

                    // Set Date of Birth
                    int day, month, year;
                    bool flag2 = false;
                    while (!flag2)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Enter Your Day of Birth : ";
                        cin >> day;
                        cout << "Enter Your Month of Birth : ";
                        cin >> month;
                        cout << "Entr Your Year of Birth :  ";
                        cin >> year;

                        if (DateOfBirthValidity(day, month, year) == true)
                        {
                            account.SetDateOfBirth(GetDateOfBirth(day, month, year));
                            flag2 = true;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Date! Enter Again!" << endl;
                        }
                    }

                    // Set Account Type
                    char Choice = '3';
                    while (Choice != '1' && Choice != '2')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) to Open Current Account" << endl
                            << "Press (2) to Open Saving Account" << endl;
                        cin >> Choice;

                        switch (Choice)
                        {
                        case '1':
                            account.SetAccountType("Current");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        case '2':
                            account.SetAccountType("Saving");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Account Type Set Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Choice! Enter Again!" << endl;
                        }
                    }

                    SetConsoleColor(FOREGROUND_GREEN);
                    // Account Number Assign
                    account.SetAccountNumber(GenerateAccountNumber());
                    cout << "Account Number Issued!" << endl;
                    // IBAN Number Assign
                    account.SetIBAN_Number(GenerateIBAN_Number());
                    cout << "IBAN Number Issued!" << endl;

                    // Select Debit Card Category
                    char Category = '4';
                    while (Category != '1' && Category != '2' && Category != '3')
                    {
                        SetConsoleColor(FOREGROUND_RED);
                        cout << "Press (1) for Silver Visa Virtual Debit Card(Rs.1500/Year)" << endl
                            << "Press (2) for Gold Visa Virtual Debit Card(Rs.2500/Year)" << endl
                            << "Press (3) for Platinum Visa Debit Card(Rs.3500/Year)" << endl;
                        cin >> Category;

                        switch (Category)
                        {
                        case '1':
                            account.SetDebitCardCategory(" Silver ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '2':
                            account.SetDebitCardCategory("  Gold  ");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        case '3':
                            account.SetDebitCardCategory("Platinum");
                            SetConsoleColor(FOREGROUND_GREEN);
                            cout << "Virtual Debit Card Category Selected Successfully!" << endl;
                            break;

                        default:
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid Entry Try Again!" << endl;
                        }
                    }

                    // Debit Card Assign
                    account.DebitCard(GenerateVirtualDebitCard());

                    // Debit Card PIN Set
                    bool flag3 = false;
                    string pin;
                    SetConsoleColor(FOREGROUND_BLUE);
                    cout << "Set Virtual Debit Card : " << endl;
                    while (!flag3)
                    {
                        cout << "Set Virtual Debit Card PIN(####) : ";
                        cin >> pin;
                        if (ValidatePin(pin) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm PIN" << endl
                                << "Press (0) to Enter Again!" << endl;
                            cin >> flag3;
                            if (flag3)
                            {
                                account.SetDebitCardPIN(pin);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Virtual Debit Card PIN Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Invalid PIN Pattern! Enter Again!" << endl;
                        }
                    }
                    cout << "Virtual Debit Card Issued!" << endl;

                    SetConsoleColor(FOREGROUND_GREEN);
                    cout << "Virtual Debit Card Issued on : " << GetCurrentDate() << endl;
                    account.SetDebitCardIssueDate(GetCurrentDate());
                    account.SetDebitCardExpireDate(DebitCardExpiry());
                    account.SetDebitCardCVV(GenerateCVV());
                    cout << "Account Opening Date : " << GetCurrentDate() << endl;

                    cout << "Debit Card Number : " << account.GetDebitCardNumber() << endl;

                    // Set Password
                    bool flag5 = false;
                    string Password;
                    while (!flag5)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Your Password of minimum 8 Characters : ";
                        cin >> Password;
                        if (GetPasswordValidity(Password) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Password" << endl
                                << "Press (0) to Re-Enter" << endl;
                            cin >> flag5;
                            if (flag5)
                            {
                                account.SetPassword(Password);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Password Set Successfully!" << endl;
                            }
                            else
                                continue;
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Incorrect Password Pattern! Enter Again! Password must be minimum of 8 characters" << endl;
                        }
                    }

                    // Set Transaction Password
                    string TransPassword;
                    bool flag7 = false;
                    while (!flag7)
                    {
                        SetConsoleColor(FOREGROUND_BLUE);
                        cout << "Set Transaction Password : ";
                        cin >> TransPassword;
                        if (ValidateTransactionPassword(TransPassword) == true)
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Press (1) to Confirm Transaction Password" << endl
                                << "Press (0) to Enter Again" << endl;
                            cin >> flag7;
                            if (flag7)
                            {
                                account.SetTransactionPassword(TransPassword);
                                SetConsoleColor(FOREGROUND_GREEN);
                                cout << "Transaction Password Set Successfully!" << endl;
                            }
                        }
                        else
                        {
                            SetConsoleColor(FOREGROUND_RED);
                            cout << "Password must be of minimum 8 characters and without gap! Re-Enter" << endl;
                        }
                    }
                    branch[4].addAccount(account);
                    SetConsoleColor(FOREGROUND_GREEN);
                    cout<<"-----<Account Created Successfully>-----"<<endl;
                }
                break;

                default:
                {
                    SetConsoleColor(FOREGROUND_RED);
                    cout << "Invalid Input!" << endl;
                }
            }
        }
        break;
        
        case '0':
        exit(0);

        default:
        {
            SetConsoleColor(FOREGROUND_RED);
            cout << "Invalid Input!" << endl;
        }
        break;
        }
    }
}