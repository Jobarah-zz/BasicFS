//
// Created by jobar on 2/2/2017.
//

#include <fstream>
#include "BasicFileSystem.h"
#include <iostream>

using namespace std;

BasicFileSystem::BasicFileSystem() { };
bool BasicFileSystem::writeBlock(string diskName, int blockNumber, Block* block, int blockSize) {
    ofstream out;
    out.open(diskName, ios::out|ios::binary|ios::app);
    char * memBlock = (char*)calloc(1, blockSize);
    memcpy(memBlock, block, blockSize);
    out.seekp(blockNumber * blockSize);
    out.write(memBlock, blockSize);
    delete [] memBlock;
    out.close();
    return false;
}

Block BasicFileSystem::readBlock(string diskName, int blockNumber, int blockSize) {

    ifstream in;
    Block *returnBlock = new Block();
    in.open(diskName, ios::in|ios::binary);
    in.seekg(blockNumber * blockSize);
    in.read((char*)&returnBlock, blockSize);
    in.close();
    return *returnBlock;
}

//in.open(path,ios::in|ios::binary);
//in.seekg(0);
//SuperBlock * superblock = new SuperBlock();
//in.read((char*)&superblock,sizeof(SuperBlock));
//in.close();
//return superblock->tamanoDeBloques;

//in.open(diskName, ios::out|ios::binary|ios::app);
//char * memBlock = (char*)calloc(1, blockSize);
//memcpy(memBlock, block, blockSize);
//out.seekp(blockNumber * blockSize);
//out.write(memBlock, blockSize);
//delete [] memBlock;
//out.close();