/*
 * ====================== leet_633.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 633. 平方数之和
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_633 {//~




// 5%  50%
class S{
public:

    // 双指针检测  8%, 50%
    // c非负
    bool judgeSquareSum_2(int c) {
        
        if(c==0){ return true; }
        uint32_t uc = static_cast<uint32_t>(c);

        std::vector<uint32_t> sqs { 0 };
        for( uint32_t i=1; i<=uc; i++ ){
            uint32_t sq = i*i;
            if( sq>uc ){ break; }
            sqs.push_back(sq);
        }
        size_t l=0;
        size_t r=sqs.size()-1;
        while( l<=r ){
            uint32_t sum = sqs.at(l) + sqs.at(r);
            if( sum>uc ){
                r--;
            }else if( sum<uc ){
                l++;
            }else{// ==
                return true;
            }
        }
        return false;
    }


    // 排榜高分解
    // 并没有事先计算所有 值
    // 而是先求得 最大值，然后边算边对比 
    bool judgeSquareSum_3(int c) {
        long int d = 0, a = 0, b = 0, sum = 0;
        while(d * d < c){
            ++d;
        }
        b = d;
        while(b >= a){
            sum = b * b + a * a;
            if(sum == c)
                return 1;
            else if(sum < c)
                ++a;
            else
                --b;
        }
        return 0;
    }

};





//=========================================================//
void main_(){


    cout<<"ret:"<<S{}.judgeSquareSum_2(5)<<endl;

    
    debug::log( "\n~~~~ leet: 633 :end ~~~~\n" );
}
}//~
