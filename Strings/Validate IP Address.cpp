https://leetcode.com/problems/validate-ip-address/description/

class Solution {
public:
    vector<string>split(string ip, char c){
        stringstream ss(ip);
        string temp;
        vector<string>part;

        while(getline(ss, temp, c)){
           cout << temp << endl;
           part.push_back(temp);
        }

        return part;
    }
    bool isValidIPv4(string ip){
        if(count(ip.begin() , ip.end() , '.') != 3) return false; 

        vector<string>parts = split(ip, '.');

        if(parts.size() != 4) return false; 

        for(auto part:parts){
            if(part.empty() || (part.size() > 1 && part[0] == '0') || part.size() > 3) return false;

            for(char c:part){
                if(!isdigit(c)) return false;
            }

            if(stoi(part) > 255) return false;
        }

        return true;
    }

    bool isValidIPv6(string ip){
        if(count(ip.begin() , ip.end() , ':') != 7) return false; 

        vector<string>parts = split(ip, ':');

        if(parts.size() != 8) return false; 

        for(auto part:parts){
            if(part.empty() || part.size() > 4) return false;

            for(char c:part){
                if(isdigit(c) || (tolower(c) >= 'a' && tolower(c) <= 'f')) continue;
                else return false;
            }

        }

        return true;

    }
    string validIPAddress(string queryIP) {
        return isValidIPv4(queryIP) ? "IPv4" : (isValidIPv6(queryIP) ? "IPv6" : "Neither");
    }
};