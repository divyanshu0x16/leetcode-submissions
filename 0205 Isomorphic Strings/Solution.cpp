class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,char> Map;
      
      unordered_set<char> mapped;
      
      if(s.size() != t.size()) return false;
      
      for(int i=0; i<s.size(); ++i){
        int cs = s[i], ct = t[i];
        
     
        if(Map.count(cs)) {
          if(Map[cs] == ct) continue;
          else return false;
        }
    
        else {
          if(mapped.count(ct)) return false;
          Map[cs] = ct;
          mapped.insert(ct);
        }
      }
      return true;
    }
};