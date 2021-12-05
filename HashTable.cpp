#include "HashTable.h"

using namespace std;

bool HashTable::isPrime(const int x) const{
    if (x <= 1)  return false;
    if (x <= 3)  return true;
    if (x%2 == 0 || x%3 == 0) return false;

    for (int i = 5; i*i<=x; i=i+6)
        if (x%i == 0 || x%(i+2) == 0)
            return false;

    return true;
}

int HashTable::nextPrime(const int x) const{
    if(x <= 1)
        return 2;

    int prime = x;
    bool found = false;

    while(!found){
        prime++;
        found = isPrime(prime);
    }

    return prime;
}

string HashTable::atIndex(const int x) const {
    return data[x];
}

int HashTable::calcIndex(const string s) const {
    int string_val = s[0] - 96;
    for(int i = 1; i < s.length(); i++){
        string_val = (string_val * 32 + (s[i] - 96)) % total_size;
    }
    return string_val;
}

int HashTable::doubleHashIncrement(const string s) const {
    int string_val = s[0] - 96;
    for(int i = 1; i < s.length(); i++){
        string_val = (string_val * 32 + (s[i] - 96)) % h2val;
    }
    return h2val - string_val;
}

/*----------------------------------------------------------------------------------------------*/

HashTable::HashTable(){
    total_size = 101;
    data = new string[total_size];
    current_count = 0;
    h2val = nextPrime(total_size/2);
}

HashTable::HashTable(const int n){
    total_size = nextPrime(n);
    data = new string[total_size];
    current_count = 0;
    h2val = nextPrime(total_size/2);
}

HashTable::HashTable(const HashTable &ht){
    total_size = ht.maxSize();
    current_count = ht.size();
    data = new string[total_size];
    h2val = nextPrime(total_size/2);
    for(int i = 0; i < total_size; i++){
        data[i] = ht.atIndex(i);
    }
}

HashTable::~HashTable(){
    delete[] data;
}

HashTable & HashTable::operator=(const HashTable &ht){
    if(&ht != this){
        total_size = ht.maxSize();
        current_count = ht.size();
        data = new string[total_size];
        h2val = nextPrime(total_size/2);
        for(int i = 0; i < total_size; i++){
            data[i] = ht.atIndex(i);
        }
    }
    return *this;
}

void HashTable::insert(const string s) {
    if(!find(s)){
        int i = calcIndex(s);
        if(data[i].empty()){
            data[i] = s;
            current_count++;
        } else {
            int c = doubleHashIncrement(s);
            while(!data[i].empty())
                i = i + c;
            data[i] = s;
            current_count++;
        }
    }

    if(loadFactor() > 0.67){
        int newsize = nextPrime(total_size * 2);
        auto tmpdata = new string[newsize];
        for(int i = 0; i < maxSize(); i++)
            tmpdata[i] = data[i];

        total_size = newsize;
        data = tmpdata;
        h2val = nextPrime(total_size/2);
    }
}

bool HashTable::find(const string s) const {
    for(int i = 0; i < maxSize(); i++){
        if(atIndex(i) == s)
            return true;
    }
    return false;
}

int HashTable::size() const {
    return current_count;
}

int HashTable::maxSize() const {
    return total_size;
}

double HashTable::loadFactor() const {
    return ((double)current_count)/((double)total_size);
}