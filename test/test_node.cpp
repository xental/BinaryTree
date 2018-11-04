//
// Created by skulish on 20.10.18.
//

#include <gtest/gtest.h>
#include "../include/Node.h"
#include <string>

using std::string;


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

TEST(Node_Comparison, EQ_works_with_float){
    Node<float> node;
    Node<float> node_two;
    float val = 5.5128f;
    node.key = val;
    node_two.key = val;

    ASSERT_TRUE(node==node_two);
}

TEST(Node_Comparison, More_works_with_float){
    Node<float> node;
    Node<float> node_two;
    float val = 5.5128f;
    float val1 = 5.6128f;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node<node_two);
}

TEST(Node_Comparison, Less_works_with_float){
    Node<float> node;
    Node<float> node_two;
    float val = 5.5128f;
    float val1 = 5.6128f;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node_two>node);
}

TEST(Node_Comparison, EQ_works_with_int){
    Node<int> node;
    Node<int> node_two;
    int val = 5;
    node.key = val;
    node_two.key = val;

    ASSERT_TRUE(node==node_two);
}

TEST(Node_Comparison, More_works_with_int){
    Node<int> node;
    Node<int> node_two;
    int val = 5;
    int val1 = 6;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node<node_two);
}

TEST(Node_Comparison, Less_works_with_int){
    Node<int> node;
    Node<int> node_two;
    int val = 5;
    int val1 = 6;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node_two>node);
}

TEST(Node_Comparison, EQ_works_with_double){
    Node<double> node;
    Node<double> node_two;
    double val = 5.5128;
    node.key = val;
    node_two.key = val;

    ASSERT_TRUE(node==node_two);
}

TEST(Node_Comparison, More_works_with_double){
    Node<double> node;
    Node<double> node_two;
    double val = 5.5128;
    double val1 = 5.6128;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node<node_two);
}

TEST(Node_Comparison, Less_works_with_double){
    Node<double> node;
    Node<double> node_two;
    double val = 5.5128;
    double val1 = 5.6128;
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node_two>node);
}

TEST(Node_Comparison, EQ_works_with_string){
    Node<string> node;
    Node<string> node_two;
    string val = "a";
    node.key = val;
    node_two.key = val;

    ASSERT_TRUE(node==node_two);
}

TEST(Node_Comparison, More_works_with_string){
    Node<string> node;
    Node<string> node_two;
    string val = "a";
    string val1 = "b";
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node<node_two);
}

TEST(Node_Comparison, Less_works_with_string){
    Node<string> node;
    Node<string> node_two;
    string val = "a";
    string val1 = "b";
    node.key = val;
    node_two.key = val1;

    ASSERT_TRUE(node_two>node);
}