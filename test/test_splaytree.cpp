#include <gtest/gtest.h>
#include "../include/SplayTree.h"
#include <iostream>

TEST(SplayTree, Can_create_int_splay_tree){
    SplayTree tree;
}


// TEST(AVL_Tree_Creation, Can_create_float_avl_tree){
    // AVLTree<float> tree;
// }


// TEST(AVL_Tree_Creation, Can_create_double_avl_tree){
    // AVLTree<double> tree;
// }


// TEST(AVL_Tree_Creation, Can_create_string_avl_tree){
    // AVLTree<std::string> tree;
// }


// TEST(AVL_Tree_Creation, Can_insert_int_val_tree){
    // AVLTree<int> tree;
    // int val1 = 5;
    // int val2 = 3;
    // int val3 = 7;

    // tree.insertRecord(val1);
    // tree.insertRecord(val2);
    // tree.insertRecord(val3);

    // ASSERT_EQ(tree.getRecord(val3)->key, val3);
// }


// TEST(AVL_Tree_Creation, Can_insert_float_val_tree){
    // AVLTree<float> tree;
    // float val1 = 5.3f;
    // float val2 = 3.6f;
    // float val3 = 7.9f;

    // tree.insertRecord(val1);
    // tree.insertRecord(val2);
    // tree.insertRecord(val3);

    // ASSERT_EQ(tree.getRecord(val3)->key, val3);
// }


// TEST(AVL_Tree_Creation, Can_insert_double_val_tree){
    // AVLTree<double> tree;
    // double val1 = 5.3;
    // double val2 = 3.6;
    // double val3 = 7.9;

    // tree.insertRecord(val1);
    // tree.insertRecord(val2);
    // tree.insertRecord(val3);

    // ASSERT_EQ(tree.getRecord(val3)->key, val3);
// }


// TEST(AVL_Tree_Creation, Can_insert_string_val_tree){
    // AVLTree<std::string> tree;
    // std::string val1 = "val1";
    // std::string val2 = "val0";
    // std::string val3 = "val2";

    // tree.insertRecord(val1);
    // tree.insertRecord(val2);
    // tree.insertRecord(val3);

    // ASSERT_EQ(tree.getRecord(val3)->key, val3);
// }

// TEST(AVL_Tree_Creation, Height_setting_properly){
    // AVLTree<int> tree;
    // int val1 = 5;
    // int val2 = 3;
    // int val3 = 7;
    // int val4 = 2;
    // int val5 = 1;
    // int val6 = 4;
    // int val7 = 8;
    // int val8 = 9;
    // int val9 = 10;

    // int expected_height = 5;

    // tree.insertRecord(val1);
    // tree.insertRecord(val2);
    // tree.insertRecord(val3);
    // tree.insertRecord(val4);
    // tree.insertRecord(val5);
    // tree.insertRecord(val6);
    // tree.insertRecord(val7);
    // tree.insertRecord(val8);
    // tree.insertRecord(val9);

    // ASSERT_EQ(tree.getRecord(val1)->height, expected_height);
// }