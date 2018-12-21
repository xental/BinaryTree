#include <gtest/gtest.h>
#include "../include/SplayTree.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

TEST(SplayTreeCreate, Can_create_int_splay_tree){
    SplayTree<int> tree;
}

TEST(SplayTreeCreate, Can_create_float_splay_tree){
    SplayTree<float> tree;
}


TEST(SplayTreeCreate, Can_create_double_splay_tree){
    SplayTree<double> tree;
}


TEST(SplayTreeCreate, Can_create_string_splay_tree){
    SplayTree<std::string> tree;
}


TEST(SplayTreeCreate, Can_insert_int_val_tree){
    splay<int>* root = nullptr;
    splay<int>* elem = nullptr;
    SplayTree<int> tree;

    int val1 = 5;
    int val2 = 3;
    int val3 = 7;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);

    elem = tree.Search(val3, root);
    ASSERT_EQ(elem->key, val3);
}

TEST(SplayTreeCreate, Can_insert_float_val_tree){
    splay<float>* root = nullptr;
    splay<float>* elem = nullptr;
    SplayTree<float> tree;

    float val1 = 5.4;
    float val2 = 3.2;
    float val3 = 7.8;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);

    elem = tree.Search(val3, root);
    ASSERT_EQ(elem->key, val3);
}

TEST(SplayTreeCreate, Can_insert_double_val_tree){
    splay<double>* root = nullptr;
    splay<double>* elem = nullptr;
    SplayTree<double> tree;

    double val1 = 5.4;
    double val2 = 3.2;
    double val3 = 7.8;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);

    elem = tree.Search(val3, root);
    ASSERT_EQ(elem->key, val3);
}

TEST(SplayTreeCreate, Can_insert_string_val_tree){
    splay<std::string>* root = nullptr;
    splay<std::string>* elem = nullptr;
    SplayTree<std::string> tree;

    std::string val1 = "4";
    std::string val2 = "3";
    std::string val3 = "8";

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);

    elem = tree.Search(val3, root);
    ASSERT_EQ(elem->key, val3);
}


TEST(SplayTreeCreate, Can_delete_int_val_tree){
    splay<int>* root = nullptr;
    splay<int>* elem_del = nullptr;
    SplayTree<int> tree;

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

TEST(SplayTreeCreate, Can_delete_float_val_tree){
    splay<float>* root = nullptr;
    splay<float>* elem_del = nullptr;
    SplayTree<float> tree;

    float val1 = 5;
    float val2 = 3;
    float val3 = 9;
    float val4 = 7;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);
    root = tree.Insert(val4, root);

    root = tree.Delete(val2, root);
    elem_del = tree.Search(val2, root);
    ASSERT_NE(elem_del->key, val2);
}

TEST(SplayTreeCreate, Can_delete_double_val_tree){
    splay<double>* root = nullptr;
    splay<double>* elem_del = nullptr;
    SplayTree<double> tree;

    double val1 = 5;
    double val2 = 3;
    double val3 = 9;
    double val4 = 7;

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);
    root = tree.Insert(val4, root);

    root = tree.Delete(val2, root);
    elem_del = tree.Search(val2, root);
    ASSERT_NE(elem_del->key, val2);
}


TEST(SplayTreeCreate, Can_delete_string_val_tree){
    splay<std::string>* root = nullptr;
    splay<std::string>* elem_del = nullptr;
    SplayTree<std::string> tree;

    std::string val1 = "5";
    std::string val2 = "3";
    std::string val3 = "9";
    std::string val4 = "8";

    root = tree.Insert(val1, root);
    root = tree.Insert(val2, root);
    root = tree.Insert(val3, root);
    root = tree.Insert(val4, root);

    root = tree.Delete(val2, root);
    elem_del = tree.Search(val2, root);
    ASSERT_NE(elem_del->key, val2);
}

TEST(SplayTreeCreate, Can_insert_data_tree){
    std::srand(unsigned(std::time(0)));
    splay<int>* root = nullptr;
    splay<int>* elem = nullptr;
    SplayTree<int> tree;

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

TEST(SplayTreeCreate, Can_delete_data_tree){
    splay<int>* root = nullptr;
    splay<int>* elem_del = nullptr;
    SplayTree<int> tree;

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
