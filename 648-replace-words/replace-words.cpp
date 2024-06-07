class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());

        for( int i=0 , j=0;i<s.size() ;){
            // j => starting index
            if(s[i]==' '){
                j= ++i ;
                continue;
                }
            // while to traverse till space
            
            while( i < s.size() && s[i] != ' '){

                if( st.find( s.substr(j,i-j+1) )!= st.end()) {
                    i++;
                    
                    while( i< s.size() && s[i]!= ' '){
                        s.erase(s.begin()+i , s.begin()+i+1);
                    }
                }
                else i++;

            }

        }
        return s;
    }
};