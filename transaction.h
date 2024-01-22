#include<string.h>
#include<iostream>
#include <functional>

using namespace std;

class Transaction{
    private:
        unsigned long id;
        string from;
        string to;
        float amt;

    public:

        // Constructors
        Transaction(string from, string to, float amt){
            this->from=from;
            this->to=to;
            this->amt=amt;
        }

        void displayTransaction(){
            cout<<from<<" PAID "<<amt<<" TO "<<to<<endl;
        }

        // Returns the Hash Value of the TXN
        size_t getHash(){
            size_t hashValue=0;
            
            hash<string> hashString;
            hashValue^=hashString(from);
            hashValue^=hashString(to);

            hash<float> hashFloat;
            hashValue^=hashFloat(amt);

            return hashValue;
        }
};