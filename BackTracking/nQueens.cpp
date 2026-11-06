class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        string s="";
        for(int i=0;i<n;i++){
            s=s+".";
        }
        vector<string> curr(n,s);
        set<int> cols;
        set<int> pd;
        set<int> nd;
        int x=0;
        int c=0;
        auto bk=[&](auto&& self,int r)->void{
            if(r==n){
                sol.push_back(curr);
                return;
            }
            for(int c=0;c<n;c++){
                if(!cols.count(c) && !pd.count(r+c) && !nd.count(r-c)){
                    cols.insert(c);
                    pd.insert(r+c);
                    nd.insert(r-c);
                    curr[r][c]='Q';
                    self(self,r+1);
                    cols.erase(c);
                    pd.erase(r+c);
                    nd.erase(r-c);
                    curr[r][c]='.';
                }
            }
        };
        bk(bk,0);
        return sol;
    }
};