//
// Created by jobar on 2/2/2017.
//

#ifndef BASICFS_BLOCK_H
#define BASICFS_BLOCK_H


class Block {
public:
    Block();
    int blockId;
    int nextBlockId;
    char * data;

};


#endif //BASICFS_BLOCK_H
