#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
    public:
        /// Constructors
        Settings();
        Settings(double dInterest, double dComission, int iMinBalance, int iBlockTime);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void SetdInterest(double dInterest);
        void SetdCommission(double dCommission);
        void SetiMinBalance(int iMinBalance);
        void SetiBlockTime(int iBlockTime);

        double GetdInterest();
        double GetdCommission();
        int GetiMinBalance();
        int GetiBlockTime();

        /// Operations
        Settings GetSettings();
        void display();

    private:
        double dInterest;
        double dCommission;
        int iMinBalance;
        int iBlockTime;
};

#endif // SETTINGS_H
