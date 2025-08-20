// #include <bits/stdc++.h>
// using namespace std;

// class TicTacToe{
//   private:
//     vector<vector<char>>matrix;
//     bool isWinner(int x, int y, char ch){
//       int row = 0, col = 0, ld = 0, rd = 0;
//       int n = matrix.size();
//       for(int i=0;i<matrix.size();i++){
//         if(matrix[x][i]==ch) row++;
//         if(matrix[i][y]==ch) col++;
//         if(x==y){
//           if(matrix[i][i]==ch) ld++;
//           if(matrix[i][n-1-i]==ch) rd++;
//         }
//       }
//       return (row==n || col==n || ld==n || rd==n);
//     }
//   public:
//     TicTacToe(int n){
//       matrix.resize(n, vector<char>(n, '_'));
//     }
//     int move(int x, int y, int playerId){
//       char ch = (playerId==1?'X':'O');
//       matrix[x][y] = ch;
//       if(isWinner(x, y, ch)){
//         return (playerId==1?1:2);
//       }
//       return 0;
//     }
// };

// int main(){
//   TicTacToe *T1 = new TicTacToe(3);
//   cout<<T1->move(0, 0, 1)<<endl;
//   cout<<T1->move(0, 2, 2)<<endl;
//   cout<<T1->move(2, 2, 1)<<endl;
//   cout<<T1->move(1, 1, 2)<<endl;
//   cout<<T1->move(2, 0, 1)<<endl;
//   cout<<T1->move(1, 0, 2)<<endl;
//   cout<<T1->move(2, 1, 1)<<endl;
  
//   return 0;
// }