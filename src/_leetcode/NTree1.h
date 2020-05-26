/*
 * ========================= NTree1.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * N Tree 1
 */
#ifndef TPR_N_TREE_1_H
#define TPR_N_TREE_1_H

#include "innLeet.h"
#include <stack>


#include <iostream>
using std::cout;
using std::endl;



// N叉树
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};







#endif 
