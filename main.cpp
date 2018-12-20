//
// Created by skulish on 20.12.18.
//

#include "include/AVLTree.h"
#include <iostream>

int main(){
    std::cout<<"HELLO"<<std::endl;
    AVLTree<int> tree;
    int val = 1;
    tree.insertRecord(val);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);
    tree.insertRecord(val+=1);

    std::cout<<tree.getHeight()<<std::endl;
    std::cout<<tree.getRoot()->key<<::std::endl;
    int del_val = 8;
    tree.deleteRecord(del_val);
    std::cout<<tree.getHeight()<<std::endl;
    std::cout<<tree.getRoot()->key<<::std::endl;

    return 0;
}