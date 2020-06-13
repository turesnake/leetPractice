/*
 * ====================== leet_448.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 448. 找到所有数组中消失的数字
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_448 {//~


// 很奇怪的方法: 基于下标交换元素法


//  39%   7%
// 以 based on 1 的方数去遍历数组，将每个数，放到自己对应的 idx位上去
// 所有交换完毕后，再做一次遍历，看看 哪些位上的数，不等于自己的 idx
class S{
public:
    // 1 ≤ a[i] ≤ n ( n = 数组大小 ) 
    std::vector<int> findDisappearedNumbers( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        for( int idx=1; idx<=N; idx++ ){// based on 1
            int i = idx;
            int v = nums.at(i-1);
            bool isChange = false;
            while( v!=i && v!=idx ){
                if(!isChange){ isChange=true; }
                int tmp = nums.at(v-1);// tmp
                nums.at(v-1) = v;
                i = v;
                v = tmp;
            }
            if(isChange){ nums.at(idx-1) = v; }
            //cout<<"==== idx:"<<idx<<" ====="<<endl;
            //cout<<"  i:"<<i<<", v:"<<v<<endl;
            //cout<<"  nums: "; for( int i : nums ){ cout<<i<<", "; }cout<<endl;
        }
        // 现在，所有存在的元素，都进入自己的 位置了，
        // 查找那些 位置和值不相符的，他们就是缺失的元素
        std::vector<int> outs {};
        for( int i=1; i<=N; i++ ){
            if( nums.at(i-1) != i ){
                outs.push_back(i);
            }
        }
        return outs;
    }
};





//=========================================================//
void main_(){

    //std::vector<int> v { 4,3,2,7,8,2,3,1 };
    //std::vector<int> v {  };

    //std::vector<int> v { 2,1 };
    std::vector<int> v { 5,9,3,8,6,4,2,7,1 };


    auto ret = S{}.findDisappearedNumbers(v);
    cout<<"ret:"<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;



    
    debug::log( "\n~~~~ leet: 448 :end ~~~~\n" );
}
}//~
