/*
 * ====================== leet_350.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 350. 两个数组的交集 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_350 {//~



//   73%   7%
class S{
public:
    std::vector<int> intersect( std::vector<int>& nums1, std::vector<int>& nums2) {

        std::unordered_map<int,int> umap {};
        for( int i : nums1 ){
            umap[i]++;
        }

        std::vector<int> outs {};

        for( int i : nums2 ){
            if( umap.count(i)>0 ){
                outs.push_back(i);
                umap.at(i)--;
                if( umap.at(i)==0 ){
                    umap.erase(i);
                }
            }
        }
        return outs;


    }
};




//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 89 :end ~~~~\n" );
}
}//~
