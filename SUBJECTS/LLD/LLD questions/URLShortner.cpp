#include <bits/stdc++.h>
using namespace std;

class URLShortner{
  public:
    URLShortner(){
      srand(time(nullptr));
    }

    string shortenURL(string &longurl){
      string shortenURL = GenerateShortenURL(longurl);
      longurlTOshorturl[shortenURL] = longurl;
      return shortenURL;
    }

    string longerURL(string &shortenurl){
      if(longurlTOshorturl.find(shortenurl) == longurlTOshorturl.end()){
        return "URL NOT FOUND";
      }
      return longurlTOshorturl[shortenurl];
    }
    
  private:
    map<string, string> longurlTOshorturl;

    string GenerateShortenURL(string &longurl){
      string hashkey = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
      string generatedShorturl;
      int shortenUrlLen = 7;
      while(true){
        for(int i=0;i<shortenUrlLen;i++){
          generatedShorturl += hashkey[rand()%(hashkey.size()-1)];
        }
        if(longurlTOshorturl.find(generatedShorturl)==longurlTOshorturl.end()){
          break;
        }else{
           generatedShorturl = "";
        }
      }
      
      return generatedShorturl;
    }
};

int32_t main(){
  string url = "https:://leetcode.com/unknown_015";

  URLShortner urlShortner;
  string ans = urlShortner.shortenURL(url);
  printf("%s\n", ans.c_str());
  return 0;
}