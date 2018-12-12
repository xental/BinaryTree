#include <gtest/gtest.h>
#include "../include/SplayTree.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

TEST(SplayTree, Can_create_splay_tree){
    SplayTree tree;
}

TEST(SplayTree, Can_insert_val_tree){
    splay* root = nullptr;
    splay* elem = nullptr;
    SplayTree tree;

    int val1 = 5;
    int val2 = 3;
    int val3 = 7;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);

    elem = tree.Search(val3, root);
    ASSERT_EQ(elem->key, val3);
}

TEST(SplayTree, Can_delete_val_tree){
    splay* root = nullptr;
    splay* elem_del = nullptr;
    SplayTree tree;

    int val1 = 5;
    int val2 = 3;
    int val3 = 9;
    int val4 = 7;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);
    root = tree.Insert(val4, root);

    root = tree.Delete(val2, root);
    elem_del = tree.Search(val2, root);
    ASSERT_NE(elem_del->key, val2);
}

TEST(SplayTree, Can_insert_data_tree){
    std::srand(unsigned(std::time(0)));
    splay* root = nullptr;
    splay* elem = nullptr;
    SplayTree tree;

    std::vector<int> data;

    for (size_t i = 0; i < 1e6; i++) {
        int value = std::rand();
        data.push_back(value);
        root = tree.Insert(value, root);
    }

    const int index = 1111;
    elem = tree.Search(data[index], root);
    ASSERT_EQ(elem->key, data[index]);
}

TEST(SplayTree, Can_delete_data_tree){
    splay* root = nullptr;
    splay* elem_del = nullptr;
    SplayTree tree;

    std::vector<int> data;

    for (size_t i = 0; i < 1e6; i++) {
        int value = std::rand();
        data.push_back(value);
        root = tree.Insert(value, root);
    }

    const int index = 3333;
    root = tree.Delete(data[index], root);
    elem_del = tree.Search(data[index], root);
    ASSERT_NE(elem_del->key, data[index]);
}
