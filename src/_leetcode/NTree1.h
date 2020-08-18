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
class NNode {
public:
    int val;
    std::vector<NNode*> children;

    NNode() {}

    NNode(int _val) { val = _val; }

    NNode(int _val, std::vector<NNode*> _children) {
        val = _val;
        children = _children;
    }
};








#endif 
