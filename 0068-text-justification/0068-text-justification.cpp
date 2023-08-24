class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mx) {

        vector<string> ans;
        int n=words.size(),tmp=0,i,j;

        for(j=0,i=0;j<n;j++){

            int sz=words[j].size();

            if(tmp+j+sz-i<=mx){
                tmp+=sz;
            }
            else{
                int space=mx-tmp;
                string sentence="";
                while(i<j){
                    if(j-i-1==0){
                        sentence+=words[i];
                        string result(space,' ');
                        sentence+=result;
                    }
                    else{
                        sentence+=words[i];

                        int lodu=space/(j-i-1);
                        if(space%(j-i-1)==0){
                            string result(lodu,' ');
                            sentence+=result;
                            space=space-lodu;
                        }
                        else{
                            string result(lodu+1,' ');
                            sentence+=result;
                            space=space-lodu-1;
                        }
                    }
                    ++i;
                }

                ans.push_back(sentence);
                tmp=words[j].size();
            }


            if(j==n-1){
                string sentence="";
                int space=mx-tmp;
                while(i<=j){
                    sentence+=words[i];
                    if(j!=i){
                        sentence+=" ";
                        --space;
                    }
                    ++i;
                }
                if(space>0){
                    string result(space,' ');
                    sentence+=result;
                }
                ans.push_back(sentence);

            }
        }
        
        return ans;
    }
};