https://www.interviewbit.com/problems/valid-ip-addresses/

bool isValidIP(string ip){
    
    if(ip.length() > 1 && ip[0] == '0') return false;
    
    return (stoi(ip) >= 0 && stoi(ip) <= 255);
}

void generateValidIps(string s, int index, int part, string current, vector<string>&result){
    if(index == s.length() && part == 4){
        result.push_back(current);
        return;
    }
    
    if(index > s.length() || part > 4) return;
    
    for(int len = 1;len <= 3 && index + len <= s.length();len++){
        string parts = s.substr(index, len);
        if(isValidIP(parts)){
            string separator = part < 3 ? "." : "";
            generateValidIps(s, index+len, part + 1, current + parts + separator, result);
        }
    }
}

vector<string> Solution::restoreIpAddresses(string s) {
    vector<string>result;
    generateValidIps(s, 0, 0, "", result);
    return result;
}
