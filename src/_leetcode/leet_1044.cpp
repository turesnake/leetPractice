/*
 * ====================== leet_1044.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1044. 最长重复子串
 */
#include "innLeet.h"


namespace leet_1044 {//~



// 判定一个 子字符串 是不是 重复子串
// parent.rfind(son); 获得 子串 在总字符串中，最后一个的位置
// 只要不等于 第一个，就说明存在重复



// 在题目思路上， 这题只是 1062 的 修改版
// 但是如果直接使用 1062 的暴力法，会超时.....

// 推荐学习并使用 Rabin-Karp 字符串编码术

// 二分查找 + 字符串hash：Rabin-Karp

// 整体思路： 按区间长度从 [1,N-1] 搜索每个长度下的所有区间，看此区间是否符合要求
// 最简单的就是将 区间长度，从 N-1 开始递减
// 但还可以借用 二分查找：
// --- 二分查找 ---
// 假设 最长重复子串 长为 5，那么一定存在 长度为 1,2,3,4 的重复子串
// （其实就是它的一部分）
// 所以，先从 midLen 长度开始搜索，然后不停二分就可以了
// 这能加速 搜索速度
// （在此之前，先检测 1, N-1 长度的区间，是否有符合的...）

// --- hash:Rabin-Karp ---
// 具体查找 重复子串时，将一个区间的字符串编码为一个 hash 值：每个字母转换为 26进制数 然后逐层累加 


class S{


    std::unordered_map<int64_t,int> umap {};// <charHash, fstIdx>

    std::string *sp {};
    int N       {0};
    int maxLen  {0};
    int tgtIdx  {0};
    int MOD     {1000000007};


    // ret: 是否找到 重复字符串
    bool search( int len ){
        
        umap.clear();
        int64_t hash = 0;

        int64_t topBase = 1;
        for( int k=0; k<len-1; k++ ){
            topBase = (topBase*26)%MOD;
        }

        // hash[0]
        for( int i=0; i<len; i++ ){
            hash = (hash*26) + (sp->at(i)-'a');
            hash %= MOD;
        }
        umap.emplace( hash, 0 );

        for( int l=0; l<N-len; l++ ){
            int r = l+len;

            //--- 减去 l 位置字母 ---//
            int64_t lVal = ((sp->at(l)-'a')*topBase)%MOD;
            if( hash <= lVal ){ hash += MOD; }
            hash -= lVal;

            //--- 加上 r 位置字母 ---//
            hash = (hash*26) + (sp->at(r)-'a');
            hash %= MOD;

            //=== 检查 ===//
            auto fit = umap.find(hash);
            if( fit != umap.end() ){// find

                // 二次比较，直接比较两个字符串
                bool isFindDiff = false;
                int a = fit->second;
                int b = l+1;
                for(; b<=r; a++,b++ ){
                    if( sp->at(a) != sp->at(b) ){
                        isFindDiff = true;
                        break;
                    }
                }
                if( !isFindDiff ){ // find same sunstr
                    if( len > maxLen ){
                        maxLen = len;
                        tgtIdx = l+1;
                    }
                    return true;
                }
            }
            // 登记
            umap.emplace( hash, l+1 );
        }
        return false;
    }
    


public:
    // 2 <= S.lenh <= 10^5
    // 小写字母 
    std::string longestDupSubstring( std::string S ){


        N = static_cast<int>(S.size());
        if(N==2){ return S[0]==S[1] ? std::string{S[0]} : ""; }

        sp = &S;

        // ll=1, rr=N-1, 优先搜索这两个极限条件下，是否存在 目标值
        // len = N-1
        bool ret = search( N-1 );
        if(ret){
            return std::string( S, 0, N-1 );
        }
        // 没有长度为 N-1 的重复子串
        
        // len = 1
        for( int i=0; i<N; i++ ){
            if( S.rfind(S[i]) != static_cast<uint64_t>(i) ){// find
                maxLen = 1;
                tgtIdx = i;
                break;
            }
        }
        if( maxLen==0 ){ return ""; } // not find
        
        // 正式使用 二分查找，搜索 [1,N-2] 区间
        int ll = 1; // 包含 
        int rr = N-2;
        while( ll<=rr ){
            if( ll==rr ){
                //cout<<"ll==rr:"<<ll<<endl;
                if( maxLen >= ll ){// 此值已经搜索过
                    return std::string ( S, tgtIdx, maxLen );
                }
                // 此长度 ll 还要再搜索一遍
                bool ret = search( ll );
                if(ret){
                    return std::string( S, tgtIdx, maxLen );
                }
            }
            int midLen = ll+(rr-ll)/2+1;//mid-right
            bool ret = search( midLen );
            if( ret ){// find
                ll = midLen; // 保留到下一回合
            }else{
                rr = midLen-1; // 坚决剔除
            }
        }
        return std::string( S, tgtIdx, maxLen ); // never reach
    
      
    }
};


//=========================================================//
void main_(){

    //std::string s = "addsadawdfsffwsadafegwegwefgrhasdaaadwdafgeasddwdasdaaasdasdwfsafetaaaa";
    //std::string s = "banana";
    std::string s = "moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc";


    //std::string s = "lcxakyjxnampmakyjbqgwby";


    auto ret = S{}.longestDupSubstring(s);

    cout<<"ret:"<<ret<<endl;












    
    debug::log( "\n~~~~ leet: 1044 :end ~~~~\n" );
}
}//~
