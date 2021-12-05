#include <iostream>
#include <string>

using namespace std;

class HashTable{
    private:
        string * data;
        int total_size;
        int h2val;
        int current_count;

        bool isPrime(const int) const;
        int nextPrime(const int) const;
        string atIndex(const int) const;
        int calcIndex(const string) const;
        int doubleHashIncrement(const string) const;
    public:
        HashTable();
        HashTable(const int);
        HashTable(const HashTable &);
        ~HashTable();
        
        HashTable & operator=(const HashTable& );
        void insert(const string);
        bool find(const string) const;
        int size() const;
        int maxSize() const;
        double loadFactor() const;
};