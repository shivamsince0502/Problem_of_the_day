class TimeMap {

public:
    map<pair<string, int>, string> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[{key, timestamp}] = value;
        return;
    }
    
    string get(string key, int timestamp) {
        for(int i = timestamp; i >= 1; i--){
            if(map[{key, i}] != "")
                return map[{key, i}];
        }
        return "";
    }
};
