// #include <bits/stdc++.h>
// using namespace std;



// class SQL{
//   private:
//     map<string, vector<vector<string>>> tables;
//     map<pair<string, int>, bool> deletedRow;
//   public:
//     SQL(vector<string> names, vector<int> columns){
//       for(int i=0;i<names.size();i++){
//         tables[names[i]] = vector<vector<string>>(0, vector<string>(columns[i]));
//       }
//     }
//     void insertRow(string name, vector<string> row){
//       tables[name].push_back(row);
//     }
//     void deleteRow(string name, int rowId){
//       if(deletedRow.find({name, rowId-1})!=deletedRow.end()){
//         deletedRow[{name, rowId-1}] = true;
//       }else{
//         cout<<"Already Deleted"<<endl;
//       }
      
//     }
//     string selectCell(string name, int rowId, int colId){
//       if(deletedRow.find({name, rowId-1}) != deletedRow.end()){
//         return tables[name][rowId-1][colId-1];
//       }
//       return "";
//     }
// };

// int main(){
//   SQL obj({"T1", "T2", "T3"}, {3, 4, 7});
//   return 0;
// }