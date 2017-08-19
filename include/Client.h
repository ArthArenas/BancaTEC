#ifndef CLIENT_H
#define CLIENT_H
#include "Account.h"
#include <iostream>

using namespace std;

class Client
{
    public:
        /// Constructors
        Client();
        Client(string sID, string sName, string sPhone, string sEmail, string sPassword);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void SetbBlocked(bool bBlocked);
        void SetiBlockTime();
        void SetiAttempts(int iAttempts);
        void SetsID(string sID);
        void SetsName(string sName);
        void SetsPhone(string sPhone);
        void SetsEmail(string sEmail);
        void SetsPassword(string sPassword);
        void SetaAccounts(Account* aAccountsB[], int iNumAccounts);

        string GetsID();
        string GetsName();
        string GetsPhone();
        string GetsEmail();
        string GetsPassword();
        bool GetbBlocked();
        int GetiBlockTime();
        int GetiAttempts();
        void GetaAccounts(Account* aAccountsB[], int& iNumAccounts);
        int GetiNumAccounts();
        Account* GetAccount(int iIndex);

        /// Operations
        void addAccount(Account* a);
        void display();
        void displayAccounts();

    private:
        string sID;
        string sName;
        string sPhone;
        string sEmail;
        string sPassword;
        int iNumAccounts;
        bool bBlocked;
        int iBlockTime;
        int iAttempts;
        Account* aAccounts[15];
};

#endif // CLIENT_H
