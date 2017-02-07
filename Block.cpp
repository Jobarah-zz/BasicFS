//
// Created by jobar on 2/2/2017.
//

#include <fstream>
#include <cstring>
#include "Block.h"
Block::Block() { }

Block::Block(int blockId) {
    this->blockId = blockId;
    nextBlockId = -1;
}

void Block::writeBlock(string diskName, int blockNumber, Block *block, int blockSize) {
    ofstream out;
    out.open(diskName, ios::out | ios::binary);
    out.seekp(blockNumber * blockSize);
    char * memBlock = (char*)calloc(1, blockSize);
    memcpy(memBlock, block, sizeof(Block));
    out.write(memBlock, blockSize);
    out.close();
    delete [] memBlock;
}

Block * Block::readBlock(string diskName, int blockNumber, int blockSize) {
    ifstream input;
    input.open(diskName,ios::in|ios::binary);
    input.seekg(blockNumber*blockSize);
    Block * diskBlock = new Block();
    char * memBlock = (char*)calloc(1, blockSize);
    input.read(memBlock, blockSize);
    input.close();
    memcpy(diskBlock, memBlock, sizeof(Block));
    delete[] memBlock;
    return diskBlock;
}
