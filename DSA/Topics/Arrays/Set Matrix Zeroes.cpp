class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> row,col;
        int m = mat.size();
        int n = mat[0].size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(int i =0;i<m;i++){
           if(row.find(i)!=row.end()){
             for(int j = 0;j<n;j++){
                mat[i][j]=0;
            }
           }
        }
        for(int i =0;i<n;i++){
           if(col.find(i)!=col.end()){
             for(int j = 0;j<m;j++){
                mat[j][i]=0;
            }
           }
        }
        cout<<endl;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

        return ;



    }
};