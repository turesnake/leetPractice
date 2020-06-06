/*
 * ====================== leet_1213.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1213. 三个有序数组的交集
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1213 {//~


// 50% 25%
class S{
public:
    // 1<= len <= 1000
    // 1<= [i] <= 2000
    std::vector<int> arraysIntersection( std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3 ){

        std::vector<int> outs {};
        int Na = static_cast<int>(arr1.size());
        int Nb = static_cast<int>(arr2.size());
        int Nc = static_cast<int>(arr3.size());
        int a =0;
        int b =0;
        int c =0;
        while( a<Na || b<Nb || c<Nc ){
            int va = a<Na ? arr1.at(a) : INT_MAX;
            int vb = b<Nb ? arr2.at(b) : INT_MAX;
            int vc = c<Nc ? arr3.at(c) : INT_MAX;
            if( va==vb && va==vc ){// all same
                outs.push_back(va);
                a++; b++; c++;
                continue;
            }
            if( va <= vb ){
                if( va <= vc ){// va
                    a++;
                }else{// vc
                    c++;
                }
            }else{
                if( vb <= vc ){// vb
                    b++;
                }else{// vc
                    c++;
                }
            }
        }
        return outs;
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1213 :end ~~~~\n" );
}
}//~
