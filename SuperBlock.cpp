#include <fstream>
#include <cstring>
#include "SuperBlock.h"

SuperBlock::SuperBlock(string diskName, int diskSize, int blockSize) {
    memcpy(this->diskName,diskName.c_str(),30);
    this->diskSize = diskSize;
    this->blockSize = blockSize;
    this->blockCount = diskSize / blockSize;
}

void SuperBlock::writeBlock(string diskName, int blockNumber, Block *block, int blockSize) {
    ofstream out;
    out.open(diskName, ios::out | ios::binary);
    out.seekp(blockNumber * blockSize);
    char * memBlock = (char*)calloc(1, blockSize);
    memcpy(memBlock, block, sizeof(SuperBlock));
    out.write(memBlock, blockSize);
    out.close();
    delete [] memBlock;
}

Block * SuperBlock::readBlock(string diskName, int blockNumber, int blockSize) {
    ifstream input;
    input.open(diskName,ios::in|ios::binary);
    input.seekg(blockNumber*blockSize);
    Block * diskBlock = new SuperBlock();
    char * memBlock = (char*)calloc(1, blockSize);
    input.read(memBlock, blockSize);
    input.close();
    memcpy(diskBlock, memBlock, sizeof(SuperBlock));
    delete[] memBlock;
    return diskBlock;
}

SuperBlock::SuperBlock() {

}
