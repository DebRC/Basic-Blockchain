#include <iostream>
#include <string>
#include <functional>
#include "block.h"

using namespace std;

class Blockchain
{
private:
    vector<Block *> chain;
    size_t lastBlockHash;
    int numOfBlocks;

    // Returns Block by Hash
    Block *getBlockByHash(size_t blockHash)
    {
        if (isBlockPresent(blockHash))
        {
            for (auto block = chain.begin(); block != chain.end(); ++block)
            {
                // Check if hash matches
                if (((*block)->getHash()) == blockHash)
                    return (*block);
            }
        }
        return NULL;
    }

public:
    // Constructor
    Blockchain()
    {
        // Add Genensis Block
        Block *genesisBlock = new Block(0);
        chain.push_back(genesisBlock);
        this->lastBlockHash = genesisBlock->getHash();
        this->numOfBlocks = 1;
    }

    // Adds a new block to the chain
    bool addBlock(Block *block)
    {
        // Check if Block is Already Present
        if (isBlockPresent(block->getHash()))
            return false;

        // Check if parent exist
        if (!isBlockPresent(block->getPrevHash()))
            return false;

        // Add block to the chain
        chain.push_back(block);

        // Update the last block hash
        lastBlockHash = block->getHash();
        numOfBlocks++;
        return true;
    }

    // Checks if a block with given hash is present
    bool isBlockPresent(size_t hash)
    {
        // Iterate over all blocks
        for (auto block = chain.begin(); block != chain.end(); ++block)
        {
            // Check if hash matches
            if (((*block)->getHash()) == hash)
                return true;
        }
        return false;
    }

    // Returns last added block hash
    size_t getLastBlockHash()
    {
        return lastBlockHash;
    }

    // Checks if the chain is valid
    bool isChainValid()
    {
        int i = numOfBlocks;
        size_t currHash = lastBlockHash;
        while (true)
        {
            if (i == 0)
            {
                if (currHash == 0)
                    return true;
                return false;
            }
            if (!isBlockPresent(currHash))
            {
                return false;
            }
            currHash = getBlockByHash(currHash)->getPrevHash();
            i--;
        }
        return false;
    }

    // Displays the block hash of all the blocks in the chain
    void displayChain()
    {
        cout << "---- BLOCKCHAIN ----" << endl;
        // Iterate over all blocks
        for (auto block = chain.begin(); block != chain.end(); ++block)
        {
            // Display block Hash
            cout << "BLOCK : " << (*block)->getHash()<<endl;
        }
        cout <<"--------------------" << endl;
    }

    // Displays the block content
    void displayBlock(size_t blockHash)
    {
        if (isBlockPresent(blockHash))
        {
            Block *block = getBlockByHash(blockHash);
            block->displayBlock();
            return;
        }
        cout << "BLOCK NOT PRESENT" << endl;
    }
};