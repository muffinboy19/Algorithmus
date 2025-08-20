// #include <bits/stdc++.h>
// using namespace std;

// class Snake{
//   private:
//     int width, height, score;
//     vector<pair<int,int>> food, snake;

//   public:
//     Snake(int width, int height, vector<pair<int,int>> food){
//       this-> width = width;
//       this-> height = height;
//       this-> food = food;
//       score = 0;
//       snake.push_back({0, 0});
//     }

//     int move(string direction){
//       auto head = snake.front(), tail = snake.back();
//       snake.pop_back();

//       // Cases::
//       if(direction == "U"){
//         head.first-=1;
//       }else if(direction == "D"){
//         head.first+=1;
//       }else if(direction == "L"){
//         head.second-=1;
//       }else{
//         head.second+=1;
//       }

//       // Check whether it cuts to himsef or not OR out of bound::
//       if(count(snake.begin(), snake.end(), head) || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width){
//         return -1;
//       }
//       snake.insert(snake.begin(), head);
//       if(!food.empty() && head == food.front()){
//         food.erase(food.begin());
//         score+=1;
//         snake.push_back(tail);
//       }
//       return score;
//     }
// };

// int main(){
//   Snake snake(4, 4, {{1, 2}, {2, 3}});
// }