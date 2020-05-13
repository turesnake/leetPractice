/*
 * ====================== leet_698.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 698. 划分为k个相等的子集
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_698 {//~




class S{
public:


    class Sett{
    public:
        Sett()=default;
        void insert( int v_ ){
            sum += v_;
            if( sum==maxSum ){ isFull=true; }
        }
        void erase( int v_ ){
            sum -= v_;
            if( sum!=maxSum ){ isFull=false; }  
        }
        bool is_suit( int v_ )const{ return (sum+v_)<=maxSum; }
        bool is_full()const{ return isFull; }
        static void set_maxSum( int v_ ){ maxSum = v_; }
    private:
        int  sum         {0};
        bool isFull     {false};
        inline static int maxSum {0};
    };


    // 递归 回溯
    // 这个版本的回溯，速度很慢，可能需要优化
    // return 是否匹配到 正确的方法
    bool rec( std::vector<int> &nums_, std::vector<Sett> &sets_, int elemIdx_  ){

        int elem = nums_.at( elemIdx_ );
        
        for( size_t i=0; i<sets_.size(); i++ ){
            Sett &setRef = sets_.at(i);
            if( setRef.is_full() ){ continue; }
            if( !setRef.is_suit(elem) ){ continue; }
            //--
            setRef.insert( elem );
            
            if( elemIdx_ == static_cast<int>(nums_.size())-1 ){ 
                return setRef.is_full(); // last elem
            }
           
            if( rec( nums_, sets_, elemIdx_+1 ) ){ 
                return true; 
            }
            setRef.erase( elem ); // check next
        }
        return false;
    }



    // 数组元素都是 正整数
    // 1 <= k <= nums.size() <= 16
    bool canPartitionKSubsets( std::vector<int>& nums, int k ) {

        int totalSum {0};
        for( const int i : nums ){
            totalSum += i;
        }
        if( totalSum % k != 0 ){ cout<<"-1-"<<endl; return false; }// 无法整除

        std::sort( nums.begin(), nums.end(), std::greater<int>{} ); // 从大到小

        int subSum = totalSum / k;
        if( subSum < nums.front() ){ cout<<"-2-"<<endl; return false; }
        Sett::set_maxSum( subSum );

        int numOff = static_cast<int>(nums.size()) - k;
        if( numOff<k && subSum!=nums.front() ){ cout<<"-3-"<<endl; return false; }// 一定有子集为单元素

        std::vector<Sett> sets (k);
        return rec( nums, sets, 0 );
    }

};



//=========================================================//
void main_(){

    //std::vector<int> v { 4, 3, 2, 3, 5, 2, 1 };
    std::vector<int> v { 10,10,10,7,7,7,7,7,7,6,6,6 };

    auto ret = S{}.canPartitionKSubsets( v, 3 );

    debug::log( "ret = {}", ret );


    debug::log( "\n~~~~ leet: 617 :end ~~~~\n" );
}
}//~
