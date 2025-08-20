// #include <bits/stdc++.h>
// using namespace std;

// class StringIterator{
//   private:
//     vector<pair<char, int>> d;
//     int curr;
//   public:
//     StringIterator(string str){
//       curr = 0;
//       int i = 0;
//       while(i<str.size()){
//         char ch = str[i++];
//         int val = 0;
        
//         while(i<str.size() && (str[i]>='0' && str[i]<='9')){
//           val = val*10 + (str[i]-'0');
//           i++;
//         }
//         d.push_back({ch, val});
//       }
//     }

//     char next(){
//       if(!hasnext()) return ' ';
//       char ch = d[curr].first;
//       d[curr].second-=1;
//       if(d[curr].second==0){
//         curr++;
//       }
//       return ch;
//     }
//     bool hasnext(){
//       if(curr<d.size() && d[curr].second>0) return true;
//       return false;
//     }
// };

// int main(){
//   StringIterator *T1 = new StringIterator("L1e2t1C1o1d1e1");
//   cout<<T1->next()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->hasnext()<<endl;
//   cout<<T1->next()<<endl;
//   cout<<T1->hasnext()<<endl;
//   return 0;
// }