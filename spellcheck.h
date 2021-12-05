#include <vector>

using namespace std;

vector<string> extraLetter(const HashTable & dict, string word){
    vector<string> result;
    if(dict.find(word)){
        result.push_back(word);
    } else {
        for(int i = 0; i < word.size(); ++i){
            auto tmp = word;
            tmp.erase(i, 1);
            if(dict.find(tmp)){
                if(find(result.begin(), result.end(), tmp) == result.end())
                    result.push_back(tmp);
            }
        }
    }
    return result;
}

vector<string> transposition(const HashTable & dict, string word){
    vector<string> result;
    if(dict.find(word)){
        result.push_back(word);
    } else {
        for(int i = 0; i < word.size(); ++i){
            auto tmp = word;
            tmp[i] = word[i+1];
            tmp[i+1] = word[i];
            if(dict.find(tmp)){
                result.push_back(tmp);
            }
        }
    }
    return result;
}

vector<string> missingSpace(const HashTable & dict, string word){
    vector<string> result;
    if(dict.find(word)){
        result.push_back(word);
    } else {
        for(int i = 1; i < word.size(); ++i){
            auto str1 = word.substr(0, i);
            auto str2 = word.substr(i);
            if(dict.find(str1) && dict.find(str2)){
                result.push_back(str1.append(" ").append(str2));
            }
        }
    }
    return result;
}

vector<string> missingLetter(const HashTable & dict, string word){
    vector<string> result;
    if(dict.find(word)){
        result.push_back(word);
    } else {
        for(int i = 0; i <= word.size(); ++i){
            string flg;
            for(char flag = 'a'; flag <= 'z'; flag++){
                auto tmp = word;
                flg = flag;
                tmp.insert(i, flg);
                if(dict.find(tmp)){
                    result.push_back(tmp);
                }
            }
        }
    }
    return result;
}

vector<string> incorrectLetter(const HashTable & dict, string word){
    vector<string> result;
    if(dict.find(word)){
        result.push_back(word);
    } else {
        for(int i = 0; i < word.size(); ++i){
            string flg;
            for(char flag = 'a'; flag <= 'z'; flag++){
                auto tmp = word;
                tmp[i] = flag;
                if(dict.find(tmp)){
                    result.push_back(tmp);
                }
            }
        }
    }
    return result;
}

