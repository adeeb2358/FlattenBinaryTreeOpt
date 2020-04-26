//
//  main.cpp
//  FlattenBinaryTreeOpt
//
//  Created by adeeb mohammed on 27/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left = NULL;
    BinaryTree *right = NULL;
    BinaryTree(int value);
};

BinaryTree* getLeftMostNode(BinaryTree *tree){
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

void connectNodes(BinaryTree *leftNode, BinaryTree *rightNode){
    if (leftNode!= NULL && rightNode !=NULL) {
        leftNode->right = rightNode;
        rightNode->left = leftNode;
    }
}

std::vector<BinaryTree*> flattenTree(BinaryTree *node){
   
    // pointers for left and right node
    BinaryTree *leftMost = nullptr;
    BinaryTree *rightMost = nullptr;
    
    if (node == NULL) {
        return {leftMost,rightMost};
    }
    
    // finding the left most node and linking all of the left side.
    if(node->left == NULL){
        leftMost = node;
    }else{
        std::vector<BinaryTree*> leftAndRightNode = flattenTree(node->left);
        connectNodes(leftAndRightNode[1],node);
        leftMost=leftAndRightNode[0];
    }
    
    //finding the right most node and linking all of the right nodes.
    if(node->right == NULL){
        rightMost = node;
    }else{
        std::vector<BinaryTree*> leftAndRightNode = flattenTree(node->right);
        connectNodes(node,leftAndRightNode[0]);
        rightMost = leftAndRightNode[1];
    }
    return {leftMost,rightMost};
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
    flattenTree(root);
    BinaryTree *leftMostNode = getLeftMostNode(root);
    return leftMostNode;
}

int main(int argc, const char * argv[]) {
    std::cout << "Optimized version of flattening a binary tree." << std::endl;
    return 0;
}
