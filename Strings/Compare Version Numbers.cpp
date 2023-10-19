https://leetcode.com/problems/compare-version-numbers/description/

class Solution {
public:
    string ignoreLeadingZeroes(string s){
        int i=0;
        while(i < s.length() && s[i] == '0') i++;
        
        if(i == s.length()) return "0";
        else return s.substr(i);
    }

    vector<string>split(string s){
        stringstream ss(s);
        
        vector<string>res;
        string temp;
        
        while(getline(ss, temp, '.')){
            res.push_back(temp);
        }
        
        return res;
    }

    int compareVersion(string A, string B) {
        vector<string>version1 = split(A);
        vector<string>version2 = split(B);
        
        int n1 = version1.size(), n2 = version2.size();
        
        for(int i=0;i < max(n1, n2);i++){
            string i1 = (i < n1) ? ignoreLeadingZeroes(version1[i]) : "0";
            string i2 = (i < n2) ? ignoreLeadingZeroes(version2[i]) : "0";
            
            if(i1.size() != i2.size()){
                return (i1.size() > i2.size()) ?  1 :  -1;
            }else if(i1 != i2){
                return (i1 > i2) ? 1 : -1;
            }
        }
        
        return 0;
    }
};

//One pass  do not handle int overflow

class Solution {
public:
    pair<int, int>getNextChunk(string &version, int p, int n){
        if(p > n-1) return {0, p};

        int pEnd = p;

        while(pEnd < n && version[pEnd] != '.'){
            pEnd++;
        }

        int i = stoi(version.substr(p, pEnd - p));

        return {i, pEnd+1};
    }

    int compareVersion(string version1, string version2) {
        int n1 = version1.size() , n2 = version2.size();

        int p1 = 0, p2 = 0;

        while(p1 < n1 || p2 < n2){
            auto pair1 = getNextChunk(version1 , p1, n1);
            int i1 = pair1.first;
            p1 = pair1.second;

            auto pair2 = getNextChunk(version2 , p2, n2);
            int i2 = pair2.first;
            p2 = pair2.second;

            if(i1 != i2){
                return (i1 > i2) ? 1 : -1;
            }
        }

        return 0;
    }
};