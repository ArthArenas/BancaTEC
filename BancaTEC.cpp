/*
BancaTEC.cpp

This program runs an ATM and has some settings and clients
already configured

by Arturo Arenas Esparza
Instituto Tecnológico y de Estudios Superiores de Monterrey
May 5, 2017
Version 1.0
*/
#include <iostream>
#include <ctime>
#include <fstream>
#include "Date.h"
#include "Settings.h"
#include "Transaction.h"
#include "Deposit.h"
#include "List.h"
#include "List.cpp"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Client.h"

using namespace std;

/////////////////////////////////////   BOOTING UP FUNCTIONS   ///////////////////////////////////////////////////////////

/*
getSize

This function gets the amount of lines a given file has

Parameters:
    string sFile    Stores the given file
Returns:
    int iC          Stores the amount of lines from the file
*/
int getSize(string sFile) {
    // Declare the data
    int iC = 0;
    string sTrash;
    // Set the input file
    ifstream input(sFile);
    // Traverse the file line by line
    while(getline(input, sTrash)){
        iC++;
    }
    // Clean up
    input.clear();
    input.seekg(0, input.beg);
    return iC;
}

/*
downloadSettings

This function loads the settings from an input file

Parameters:
    string sFile    Stores the given file
Returns:
    Settings s      Stores the 'Settings' objects created from the input file
*/
Settings downloadSettings(string sFile) {
    // Declare data
    double dInterests;
    double dCommission;
    double dMinBalance;
    double dBlockTime;
    // Set the input file
    ifstream input(sFile);
    // Read data
    input >> dInterests >> dCommission >> dMinBalance >> dBlockTime;
    Settings s(dInterests, dCommission, dMinBalance, dBlockTime);
    // Clean up
    input.clear();
    input.seekg(0, input.beg);
    return s;
}

/*
downloadClients

This function loads the clients from an input file

Parameters:
    string sFile    Stores the given file
    Client aC[]     Stores the array of clients
Returns:
    void
*/
void downloadClients(string sFile, Client aC[]) {
    // Declare data
    int i;
    int j = 0;
    string sTrash;
    // Set the input file
    ifstream input(sFile);
    while(getline(input, sTrash)){
        // Declare data
        string sID;
        string sName;
        string sPassword;
        string sPhone;
        string sEmail;
        i = 0;
        // Split the information from one line into its different strings
        while(sTrash[i] != '\t'){
            // Read ID
            sID += sTrash[i];
            i++;
        }
        i++;
        while(sTrash[i] != '\t'){
            // Read name
            sName += sTrash[i];
            i++;
        }
        i++;
        while(sTrash[i] != '\t'){
            // Read phone
            sPhone += sTrash[i];
            i++;
        }
        i++;
        while(sTrash[i] != '\t'){
            // Read email
            sEmail += sTrash[i];
            i++;
        }
        i++;
        while(sTrash[i]){
            // Read password
            sPassword += sTrash[i];
            i++;
        }
        Client c(sID, sName, sPhone, sEmail, sPassword);
        aC[j] = c;
        j++;
    }
    // Clear up
    input.clear();
    input.seekg(0, input.beg);
}

/*
downloadAccounts

This function loads the accounts from an input file

Parameters:
    string sFile    Stores the given file
    Client aC[]     Stores the array of clients
    int iSize       Stores the amount of clients
    Settings s      Stores the pre-configured settings
Returns:
    void
*/

void downloadAccounts(string sFile, Client aC[], int iSize, Settings s) {
    // Set the input file
    ifstream input(sFile);
    // Declare data
    string sID;
    string sType;
    string sAccount;
    int iInitialBalance;
    int iI;
    while(input >> sID){
        // Find the matching client's ID
        for(iI = 0; iI < iSize; iI++){
            if(sID == aC[iI].GetsID()){
                break; // iI will store the index of the corresponding client
            }
        }
        bool bIsChecking;
        // Read data
        input >> sType >> sAccount >> iInitialBalance;
        // Solve the type of the account
        if(sType == "2"){
            bIsChecking = true;
        }
        else{
            bIsChecking = false;
        }
        // Add the new account to the array of accounts
        if(bIsChecking){
            Checking* ch = new Checking(sAccount, s.GetdCommission(), iInitialBalance, s);
            aC[iI].addAccount(ch);
        }
        else{
            Savings* sv = new Savings(sAccount, (s.GetdInterest()/100), iInitialBalance, s);
            aC[iI].addAccount(sv);
        }
    }
    // Clear up
    input.clear();
    input.seekg(0, input.beg);
}

/*
downloadTransactions

This function loads the transactions from the input file

Parameters:
    string sFile    Stores the given file
    Client aC[]     Stores the array of clients
    int iSize       Stores the amount of clients
Returns:
    void
*/
void downloadTransactions(string sFile, Client aC[], int iSize) {
    // Declare data
    string sID;
    string sAccount;
    string sType;
    int iDay;
    int iMonth;
    int iYear;
    int iHour;
    int iMinute;
    int iSecond;
    double dAmount;
    int iI;
    int iJ;
    // Set input file
    ifstream input(sFile);
    // Read until EOF
    while(input >> sID){
        // Find the matching client's ID
        for(iI = 0; iI < iSize; iI++){
            if(sID == aC[iI].GetsID()){
                break; // iI will store the index of the corresponding client
            }
        }
        // Read data
        input >> sAccount >> sType >> iDay >> iMonth >> iYear >> iHour >> iMinute >> iSecond >> dAmount;
        // Find the matching account
        for(iJ = 0; iJ < aC[iI].GetiNumAccounts(); iJ++){
            if(aC[iI].GetAccount(iJ) -> GetsAccount() == sAccount){
                Date someDate(iDay, iMonth, iYear, iHour, iMinute, iSecond);
                // Solve the type of transaction
                if(sType == "d"){
                    aC[iI].GetAccount(iJ) -> deposit(dAmount, someDate);
                }
                else if(sType == "r"){
                    aC[iI].GetAccount(iJ) -> withdraw(dAmount, someDate);
                }
                else{
                    aC[iI].GetAccount(iJ) -> balance(dAmount, someDate);
                }
                break;
            }
        }
    }
    // Clean up
    input.clear();
    input.seekg(0, input.beg);
}

/*
getFileName

This function creates the file name for the account status

Parameters:
    Client c        Stores the owner of the account
    int iIndex      Stores the index of the account from the array of accounts
    Date someDate   Stores the date of the transaction
Returns:
    string sFile    Stores the resulting name of the Account Status file
*/
string getFileName(Client c, int iIndex, Date someDate) {
    // Declare data
    // Append my own student ID from Monterrey's Tech
    string sFile = "A00820982";
    sFile += "_";
    // Append account number
    sFile += c.GetAccount(iIndex) -> GetsAccount();
    sFile += "_";
    // Append date and hour
    sFile += someDate.getHourDateFormat("_", "_");
    sFile += "_";
    // Append type of account
    sFile += c.GetAccount(iIndex) -> GetsType();
    sFile += ".txt";
    return sFile;
}

/*
downloadHistory

This function loads the historical information

Parameters:
    Client aClients[]   Stores the array of clients
    int iNumClients     Stores the amount of clients
    Settings& s         Stores the pre-configured settings
Returns:
    void
*/
void downloadHistory(Settings& s, Client aClients[], int iNumClients) {
    // Declare data
    string sSettingsFile = "Configuracion.txt";
    string sClientsFile = "Clientes.txt";
    string sAccountsFile = "Cuentas.txt";
    string sTransactionsFile = "Transacciones.txt";
    int i;
    int j;
    // Download settings
    s = downloadSettings(sSettingsFile);
    // Download clients
    downloadClients(sClientsFile, aClients);
    // Download accounts
    downloadAccounts(sAccountsFile, aClients, iNumClients, s);
    // Download transactions
    downloadTransactions(sTransactionsFile, aClients, iNumClients);
    // For every client
    for(i = 0; i < iNumClients; i++){
        // For every account - print Account Status
        for(j = 0; j < aClients[i].GetiNumAccounts(); j++){
            Date someDate;
            string sFile = getFileName(aClients[i], j, someDate);
            ofstream output(sFile);
            output << "\t\tBancaTEC" << endl;
            output << "Name of the client: " << aClients[i].GetsName() << endl;
            aClients[i].GetAccount(j) -> printAS(output);
        }
    }
    // Final boot up adjustment
    ofstream output("Transacciones.txt", ios::app);
    output << '\n';
}

/////////////////////////////////////   ATM INTERNAL WORKINGS   /////////////////////////////////////////////////////////

/*
home

Displays the home screen with welcome message and date and time of access

Parameters:
    void
Returns:
    void
*/
void home() {
    Date rightNow;
    cout << "Welcome to BancaTEC !!!" << endl;
    cout << "Current time: ";
    rightNow.display();
    cout << endl;
}

/*
logIn

This function manages the logger for clients

Parameters:
    Client aC[]         Stores the array of clients
    int& iNumClients    Stores the amount of clients
    Settings s          Stores the pre-configured settings
Returns:
    int iIndex          Stores the index of the client from the array of clients
*/
int logIn(Client aC[], int& iNumClients, Settings s) {
    // Declare data
    int iI;
    string sID;
    string sPassword;
    int iIndex;
    bool bSuccess;
    // Loop until a successful log in occurs
    do{
        bSuccess = false;
        // Read data
        cout << "Input your client ID: ";
        cin >> sID;
        cout << "Password: ";
        cin >> sPassword;
        // Search the matching ID
        for(iI = 0; iI < iNumClients; iI++){
            if(sID == aC[iI].GetsID()){
                iIndex = iI;
                iI = iNumClients + 1;
            }
        }
        // If we have matched the ID
        if(iNumClients != iI){
            // Check if client is blocked
            if(aC[iIndex].GetbBlocked() && int(time(0)) - aC[iIndex].GetiBlockTime() <= s.GetiBlockTime()){
                cout << "Sorry, your access has been blocked, try again later" << endl;
            }
            // If the account is not blocked
            else{
                aC[iIndex].SetbBlocked(false);
                // Check password
                if(sPassword == aC[iIndex].GetsPassword()){
                    bSuccess = true;
                }
                // If the password does not match, see if we will block the account
                else{
                    aC[iIndex].SetiAttempts(aC[iIndex].GetiAttempts() + 1);
                    if(aC[iIndex].GetiAttempts()%3 == 0){
                        aC[iIndex].SetbBlocked(true);
                        cout << "Sorry, your access has now been blocked" << endl;
                        aC[iIndex].SetiBlockTime();
                    }
                }
            }
        }
        // Check if the user succeeded to log in
        if(!bSuccess){
            cout << "Inexistent ID or wrong Password" << endl;
        }
        else{
            cout << "Successful log in" << endl;
        }
    } while(!bSuccess);
    return iIndex;
}

/*
chooseAccount

Parameters:
    Client c            Stores the client
Returns:
    int iAccountIndex   Stores the index of the account from the array of accounts
*/
int chooseAccount(Client c) {
    // Declare data
    int iI;
    int iAccountIndex;
    string sAns;
    bool bSuccess = false;
    // Validate that the client has any account
    if(c.GetiNumAccounts() > 0){
        string sAnswers[16] = {"quit", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"};
        c.displayAccounts();
        do{
            cout << "Option to choose (type \"quit\" to quit): ";
            cin >> sAns;
            for(iI = 0; iI < 16; iI++){
                // Find the matching answer
                if(sAnswers[iI] == sAns){
                    if(iI > 0){
                        iAccountIndex = iI - 1;
                        if(iI <= c.GetiNumAccounts()){
                            bSuccess = true;
                        }
                    }
                    else{
                        // Signal that the user wants to quit
                        iAccountIndex = -1;
                        bSuccess = true;
                    }
                    iI = 16;
                }
            }
            if(!bSuccess){
                cout << "Invalid option, try again" << endl;
            }
        } while(!bSuccess);
    }
    // If the client has no accounts, we must log out
    else{
        cout << "NO accounts have been found" << endl;
        cout << "Logging out" << endl;
        iAccountIndex = -1;
    }
    return iAccountIndex;
}

/*
chooseAction

This function process the actions chosen by the client on one of his accounts

Parameters:
    Client c    Stores the client
    Account* a  Stores the address of the account the client is using
    int iIndex  Stores the index of the account being used
    Settings s  Stores the pre-configured settings
Returns:
    void
*/
void chooseAction(Client c, Account* a, int iIndex, Settings s) {
    // Declare data
    char cAns;
    bool bQuit = false;
    bool bSuccess = false;
    double dAmount;
    int iNumTransactions;
    // Loop until the user quits
    do{
    cout << "Choose an option" << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Check balance" << endl;
    cout << "4. See Transactions" << endl;
    cout << "5. Print AS" << endl;
    cout << "6. Quit" << endl;
        do{
            cout << "Option: ";
            cin >> cAns;
            if(cAns > '0' && cAns < '7'){
                bSuccess = true;
                switch(cAns)
                {
                    // Perform a deposit
                    case '1':
                        {
                            cout << "Amount to deposit: $ ";
                            cin >> dAmount;
                            Date rightNow;
                            a -> deposit(dAmount, rightNow);
                            // Save deposit in transactions file
                            iNumTransactions = a -> GetiTransactions() - 1;
                            ofstream output("Transacciones.txt", ios::app);
                            output << c.GetsID() << " " << a -> GetsAccount() << " ";
                            a -> GetList() -> GetElement(iNumTransactions) -> save(output);
                            break;
                        }
                    // Perform a withdrawal
                    case '2':
                        {
                            cout << "Amount to withdraw: $ ";
                            cin >> dAmount;
                            Date rightNow;
                            a -> withdraw(dAmount, rightNow);
                            // Save withdrawal
                            iNumTransactions = a -> GetiTransactions() - 1;
                            ofstream output("Transacciones.txt", ios::app);
                            output << c.GetsID() << " " << a -> GetsAccount() << " ";
                            a -> GetList() -> GetElement(iNumTransactions) -> save(output);
                            break;
                        }
                    // Perform the retrieval of a balance
                    case '3':
                        {
                            cout << "Your current balance is: $" << a -> GetdTotBalance() << endl;
                            Date rightNow;
                            a -> balance(a -> GetdTotBalance(), rightNow);
                            // Save retrieval of balance
                            iNumTransactions = a -> GetiTransactions() - 1;
                            ofstream output("Transacciones.txt", ios::app);
                            output << c.GetsID() << " " << a -> GetsAccount() << " ";
                            a -> GetList() -> GetElement(iNumTransactions) -> save(output);
                            break;
                        }
                    // Display transactions
                    case '4':
                        {
                            a -> displayTransactions();
                            break;
                        }
                    // Print Account Status
                    case '5':
                        {
                            bool bProceed = false;
                            // Checking accounts need extra validation for collecting commission
                            if(a -> GetsType() == "Checking"){
                                if(a -> GetdTotBalance() >= s.GetdCommission()){
                                    bProceed = true;
                                }
                            }
                            else{
                                bProceed = true;
                            }
                            if(bProceed){
                                // After validating the printing, we perform it
                                Date someDate;
                                ofstream output(getFileName(c, iIndex, someDate));
                                output << "\t\tBancaTEC" << endl;
                                output << "Name of the client: " << c.GetsName() << endl;
                                a -> printAS(output);
                            }
                            // Failed to print Account Status
                            else{
                                cout << "Sorry, there is not enough money to collect BancaTEC's commission" << endl;
                            }
                            break;
                        }
                    // Quit
                    case '6':
                        {
                            bQuit = true;
                            break;
                        }
                }
            }
            else{
                cout << "Invalid option, try again" << endl;
            }
        } while(!bSuccess);
    } while(!bQuit);
}

//////////////////////////////////////////   MAIN   /////////////////////////////////////////////////////////////

/*
main

This function runs the main program

Parameters:
    void
Returns:
    0
*/
int main() {
    // Declare data
    Settings s;
    string sClientsFile = "Clientes.txt";
    int iNumClients = getSize(sClientsFile);
    int iClientIndex;
    int iAccountIndex;
    bool bQuit;
    Client* aClients = new Client[iNumClients];
    // Booting up
    downloadHistory(s, aClients, iNumClients);
    // Run ATM - loop forever
    do{
        // Home page
        home();
        // Log in
        iClientIndex = logIn(aClients, iNumClients, s);
        bQuit = false;
        do{
            // Choose account
            iAccountIndex = chooseAccount(aClients[iClientIndex]);
            if(iAccountIndex != -1){
                // Choose action
                chooseAction(aClients[iClientIndex], aClients[iClientIndex].GetAccount(iAccountIndex), iAccountIndex, s);
            }
            else{
                bQuit = true;
            }
        } while(!bQuit);
    } while(true);
    // End
    return 0;
}
