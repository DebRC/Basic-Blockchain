#include<iostream>
#include "blockchain.h"

void addNewBlock(Blockchain* blockchain){
    Block *block = new Block(blockchain->getLastBlockHash());
    while(true){
        cout<<"ADD NEW TRANSACTION (Y/N) : ";
        string choice;
        cin>>choice;
        cout<<endl;
        if(choice=="Y"){
            string from,to;
            float amt;
            cout<<"ENTER SENDER : ";
            cin>>from;
            cout<<"ENTER RECEPIENT : ";
            cin>>to;
            cout<<"ENTER AMOUNT : ";
            cin>>amt;
            Transaction* transaction = new Transaction(from,to,amt);

            if(!block->addTransaction(transaction)){
                cout<<"BLOCK IS FULL"<<endl;
                continue;
            }
            cout<<"TRANSACTION ADDED"<<endl;
            cout<<endl;
        }
        else if(choice=="N"){
            blockchain->addBlock(block);
            cout<<"BLOCK ADDED TO BLOCKCHAIN"<<endl;
            return;
        }

    }
}

void displayChain(Blockchain* blockchain){
    blockchain->displayChain();
}

void displayBlock(Blockchain* blockchain){
    size_t hash;
    cout<<"ENTER BLOCK HASH : ";
    cin>>hash;
    cout<<endl;
    blockchain->displayBlock(hash);
}

void checkIfChainValid(Blockchain* blockchain){
    if(blockchain->isChainValid()){
        cout<<"CHAIN IS VALID"<<endl;
    }
    else{
        cout<<"CHAIN IS INVALID"<<endl;
    }
}

void freeBlockchain(Blockchain* blockchain){

}

int main(){

    Blockchain* blockchain = new Blockchain();

    cout<<"YOUR BLOCKCHAIN IS CREATED"<<endl;

    while(true){
        cout<<endl;
        cout<<"**PLEASE SELECT AN OPTION**"<<endl<<endl;
        cout<<"1. ADD NEW BLOCK"<<endl;
        cout<<"2. DISPLAY CHAIN"<<endl;
        cout<<"3. DISPLAY BLOCK"<<endl;
        cout<<"4. CHECK IF CHAIN IS VALID"<<endl;
        cout<<"5. EXIT"<<endl;
        cout<<endl;

        cout<<"ENTER CHOICE : ";

        int choice;
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 1:
            addNewBlock(blockchain);
            break;
        case 2:
            displayChain(blockchain);
            break;
        case 3:
            displayBlock(blockchain);
            break;
        case 4:
            checkIfChainValid(blockchain);
            break;
        case 5:
            freeBlockchain(blockchain);
            exit(0);
        default:
            cout<<"INCORRECT CHOICE"<<endl;
            break;
        }
    }
    return 0;
}