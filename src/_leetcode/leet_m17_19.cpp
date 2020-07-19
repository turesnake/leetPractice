/*
 * ====================== leet_m17_19.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_19 {//~

// 当前数组个数为 Nn,
// 理想个数为 N, N=Nn+2;
// 理想区间 [1, Nn+2]



// 三种方案 都需要 记住 ！！！



//  思路1
//  求出了 a+b, 然后获得 mid-left-val
//  其中，左侧的目标值，一定在 [1,mlVal] 区间内
//  单独找出 l，进而获得 r

//   70%  100%
class S{
public:
    // nums.length <= 30000
    std::vector<int> missingTwo( std::vector<int>& nums ){

        int Nn = static_cast<int>(nums.size());
        int N = Nn+2;// 理论上的最大值

        // a+b
        int sumTwo = (1+N)*N/2;
        for( int i : nums ){
            sumTwo -= i;
        }
        //---//
        int mlVal = sumTwo/2;//mid-left-val
        int sum = (1+mlVal)*mlVal/2;
        for( int i : nums ){
            if( i<=mlVal ){ sum -= i; }
        }
        //---//
        int l = sum;
        return { l, sumTwo-l };


    }
};



// 和 思路1 相似的 操作
// 首先，求得 xor = a^b;
// 然后，获得 ab 两数的某个 相异位： int lb = xor&(-xor);
// 相异位 可以成为一个 划分条件，将所有元素，划分为 相同的，不同的
// ab 两数，一定分别在 两侧
// 然后就可以单独求出 a
// 进而获得 b

//   84%   100%
class S2{
public:
    // nums.length <= 30000
    std::vector<int> missingTwo( std::vector<int>& nums ){

        int Nn = static_cast<int>(nums.size());
        int N = Nn+2;// 理论上的最大值

        // a^b
        int xxor = 0;
        for( int i=1; i<=N; i++ ){// 理论值
            xxor ^= i;
        }
        for( int i=0; i<Nn; i++ ){// 实际值
            xxor ^= nums[i];
        }

        int diff = xxor & (-xxor);
        int tn = 0;
        for( int i=1; i<=N; i++ ){// 理论值
            if( (i&diff)>0 ){ tn ^= i; }
        }
        for( int i=0; i<Nn; i++ ){// 实际值
            if( (nums[i]&diff)>0 ){ tn ^= nums[i]; }
        }
        //---//
        int a = tn;
        return { a,  xxor^a  };


    }
};



// 元素交换法   39%   100%
class S3{
public:
    // nums.length <= 30000
    // 1 <= [i] <= Nn+2
    std::vector<int> missingTwo( std::vector<int>& nums ){

        int Nn = static_cast<int>(nums.size());
        int N = Nn+2;// 理论上的最大值

        // 补完数组
        nums.insert( nums.end(), 2, -9 );

        for( int i=1; i<=N; i++ ){
            while( nums[i-1]!=-9 && i!=nums[i-1] && nums[i-1]!=nums[nums[i-1]-1] ){
                std::swap( nums[i-1], nums[nums[i-1]-1] );
            }
        }
        cout<<"v: "; for( int i : nums ){ cout<<i<<", "; }cout<<endl;
        std::vector<int> outs {};
        for( int i=0; i<N; i++ ){
            if( nums[i]==-9 ){
                outs.push_back( i+1 );
            }
        }
        return outs;


    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 1, 2, 3, 4, 6, 7, 9, 10 };

    auto ret = S3{}.missingTwo(v);

    cout<<endl;
    for( int i : ret ){
        cout<<i<<", ";
    }cout<<endl;




    debug::log( "\n~~~~ leet: m17_19 :end ~~~~\n" );
}
}//~
