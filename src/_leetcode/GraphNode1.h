/*
 * ========================= GraphNode1.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 无向图 
 */
#ifndef TPR_GRAPH_NODE_1_H
#define TPR_GRAPH_NODE_1_H

#include "innLeet.h"
#include <stack>


#include <iostream>
using std::cout;
using std::endl;



class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    //---//
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



#endif 
