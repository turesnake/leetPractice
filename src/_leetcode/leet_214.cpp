/*
 * ====================== leet_214.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 214. 最短回文串
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_214 {//~

// ==1== 将字符串反转，然后求两个str 的 最长 公共子串
//       此时就要用到 KMP 算法


// ==2== 直接求 最长回文字段
//       最快的方法就是 马拉车算法
//      


//  马拉车   91%   100%
class S{
public:
    std::string shortestPalindrome( std::string s ){

        int N = static_cast<int>(s.size());

        std::string v ( N*2+1, '#' );
        for( int i=0; i<N; i++ ){
            v[i*2+1] = s[i];
        }

        int Nv = static_cast<int>(v.size());

        std::vector<int> mv (Nv,0);// 记录 马拉车数据

        int maxR = 0;
        int center = 0;
        int maxLen = 1;// 能覆盖首字母的 最长回文串 的长度

        for( int i=0; i<Nv; i++ ){

            if( i < maxR ){
                int mirror = 2*center-i;
                mv[i] = std::min( maxR-i, mv[mirror] );// 核心
            }

            int l = i - mv[i] - 1;
            int r = i + mv[i] + 1;
            for(; l>=0 && r<Nv && v[l]==v[r]; mv[i]++,l--,r++ ){}

            if( i+mv[i] > maxR ){
                maxR = i+mv[i];
                center = i;
            }
            if( i==mv[i] ){
                maxLen = mv[i]; // 恰好是 回文长度
            }
        }
        //cout<<"mv:"; for(int i : mv){ cout<<i<<","; }cout<<endl;
        //---//
        std::string ans ( s, maxLen, N-maxLen );// 后半段
        std::reverse( ans.begin(), ans.end() );
        ans.append( s.begin(), s.end() );
        return ans;

    }
};




class S_Show{
public:
    std::string shortestPalindrome( std::string s) {

    	int len = s.length();
    	std::vector<int> dp(2*len+1,0);
    	dp[0] = 1;
    	int mid = 0;
    	int maxL = 1;
    	int maxLen = 0;
    	for(int i =1;i<2*len+1;i++){
    		if(i<maxL){
    			dp[i] = std::min(dp[2*mid-i],maxL-i);//边界限制
    		}else{
    			if(i%2==0){//为偶数，说明这个字符是#,最多只能确定它本身
    				dp[i] = 1;
    			}
    			else//为奇数，说明这个是s中的字符，非填充的#,那么旁边肯定有#,所以长度至少为2
    				dp[i] = 2;
    		}

    		int j =dp[i];//边界
    		while( i-j>=0 && i+j<len*2+1 && s[(i-j)/2]==s[(i+j)/2] ){//向两边扩展
    			j+=2;//跳过中间的#
    		}
    		dp[i]=j;//更新长度
    		if(dp[i]+i>maxL){//更新右边界
    			mid = i;
    			maxL = dp[i]+i;
    		}
    		if(dp[i]==i+1){//判断起点是否包含在回文串中
    			maxLen = dp[i]-1;
    		}
    	}
    	std::string sub_str = s.substr(maxLen);
    	reverse(sub_str.begin(),sub_str.end());
    	return sub_str+s;
    }
};





//=========================================================//
void main_(){

    std::string s = "abakabajj";

    auto ret = S{}.shortestPalindrome(s);
    cout<<"ret:"<<ret<<endl;






    debug::log( "\n~~~~ leet: 214 :end ~~~~\n" );
}
}//~
