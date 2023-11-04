#pragma once
#include <string>
class SignSet{
    bool allowed;
    string chain;
    public:
        SignSet() {}
        SignSet(string signs) {
            this->chain = signs;
            this->allowed = false;   
        }
        void setAllowed(bool cond) {
            allowed  = cond;
        }
        bool getAllowed() {
            return allowed;
        }
        int size() {
            return chain.length();
        }
        char getLetterAt(int index) {
            if(index<0 || index>chain.length()-1) {
                return -1;
            }
            return chain[index];
        }
};