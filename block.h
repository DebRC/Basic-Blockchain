#include<iostream>
#include<string>
#include <functional>
#include "transaction.h"

// Set Maximum Number of TXN in a Block
#define MAXIMUM_TXN_LIMIT 10

using namespace std;

class Block{
    private:
        size_t prevBlockHash;
        size_t currBlockHash;
        Transaction *transactions[MAXIMUM_TXN_LIMIT];
        int transactionCount;

        // Updates the current hash
        void updateHash(){
            size_t hashValue = 0;
            
            // Hash Prev Block
            hash<size_t> hashHash;
            hashValue=hashHash(prevBlockHash);

            // Hash Trans. Count
            hash<int> hashInt;
            hashValue^=hashInt(transactionCount);

            // Hash Transactions
            for(int i=0;i<transactionCount;i++){
                hashValue^=transactions[i]->getHash();
            }

            // Update the curr block hash value
            this->currBlockHash=hashValue;
        }

    public:

        // Constructor
        Block(size_t previousHash){
            this->prevBlockHash=previousHash;
            this->transactionCount=0;
            this->updateHash();
        }

        // Adds a transaction
        bool addTransaction(Transaction* transaction){
            // Check if Block is Already full
            if (transactionCount==10) return false;

            // Increment TXN Count and Add the TXN
            transactionCount++;
            transactions[transactionCount-1]=transaction;

            // Updates the Current Hash Value
            updateHash();
            return true;
        }

        // Returns the Hash Value of the Block
        size_t getHash(){
            return currBlockHash;
        }

        // Returns the Hash Value of the Previous Block
        size_t getPrevHash(){
            return prevBlockHash;
        }

        // Frees the allocated memory
        void freeBlock(){}

        void displayBlock(){
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
            cout<<"CURRENT BLOCK HASH :: "<<currBlockHash<<endl;
            cout<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
            cout<<"PREVIOUS BLOCK HASH :: "<<prevBlockHash<<endl;
            cout<<endl;
            cout<<"---------------------------------------"<<endl;
            cout<<endl;
            cout<<"         TRANSACTION(S) LIST"<<endl;
            cout<<endl;
            for(int i=0;i<transactionCount;i++){
                transactions[i]->displayTransaction();
                cout<<endl;
            }
            cout<<"---------------------------------------"<<endl;
        }
};