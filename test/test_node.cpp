//
// Created by skulish on 20.10.18.
//

#include <gtest/gtest.h>
#include "../include/Node.h"
#include <string>

using std::string;

TEST(Node_Creation, Can_create_int_node){
    ASSERT_NO_THROW(Node<int> node);
}

TEST(Node_Creation, Can_create_ptr_to_int_node){
    ASSERT_NO_THROW(Node<int>* node = new Node<int>());
}

TEST(Node_Creation, Can_set_intval_to_node){
    Node<int> node;
    int val = 5;
    ASSERT_NO_THROW(node.key = val);
    ASSERT_EQ(node.key, val);
}

TEST(Node_Creation, Can_set_intval_to_ptr_node){
    Node<int>* node = new Node<int>();
    int val = 5;
    ASSERT_NO_THROW(node->key = val);
    ASSERT_EQ(node->key, val);
}

TEST(Node_Creation, Can_create_string_node){
    ASSERT_NO_THROW(Node<string> node);
}

TEST(Node_Creation, Can_create_ptr_to_string_node){
    ASSERT_NO_THROW(Node<string>* node = new Node<string>());
}

TEST(Node_Creation, Can_set_stringval_to_node){
    Node<string> node;
    string val = "str";
    ASSERT_NO_THROW(node.key = val);
    ASSERT_EQ(node.key, val);
}

TEST(Node_Creation, Can_set_stringval_to_ptr_node){
    Node<string>* node = new Node<string>();
    string val = "str";
    ASSERT_NO_THROW(node->key = val);
    ASSERT_EQ(node->key, val);
}

TEST(Node_Creation, Can_create_double_node){
    ASSERT_NO_THROW(Node<double> node);
}

TEST(Node_Creation, Can_create_ptr_to_double_node){
    ASSERT_NO_THROW(Node<double>* node = new Node<double>());
}

TEST(Node_Creation, Can_set_doubleval_to_node){
    Node<double> node;
    double val = 5.5128;
    ASSERT_NO_THROW(node.key = val);
    ASSERT_EQ(node.key, val);
}

TEST(Node_Creation, Can_set_doubleval_to_ptr_node){
    Node<double>* node = new Node<double>();
    double val = 5.5128;
    ASSERT_NO_THROW(node->key = val);
    ASSERT_EQ(node->key, val);
}

TEST(Node_Creation, Can_create_float_node){
    ASSERT_NO_THROW(Node<float> node);
}

TEST(Node_Creation, Can_create_ptr_to_float_node){
    ASSERT_NO_THROW(Node<float>* node = new Node<float>());
}

TEST(Node_Creation, Can_set_floatval_to_node){
    Node<float> node;
    float val = 5.5128f;
    ASSERT_NO_THROW(node.key = val);
    ASSERT_EQ(node.key, val);
}

TEST(Node_Creation, Can_set_floatval_to_ptr_node){
    Node<float>* node = new Node<float>();
    float val = 5.5128f;
    ASSERT_NO_THROW(node->key = val);
    ASSERT_EQ(node->key, val);
}
