#include "bitset.hpp"

// TODO
Bitset::Bitset() {
    v_bitWidth = 8;//valid bitset of width 8
    p_boolPointer = new bool[v_bitWidth];
    for (uint8_t temp = 0; temp < v_bitWidth; temp++) {
        p_boolPointer[temp] = false;// with all bits set to 0
    }
    v_objectStatus = 1;//set validity
}

Bitset::Bitset(intmax_t size) {
    if (size <= 0) {
        v_objectStatus = 2;
    } else {
        v_bitWidth = size;//valid bitset of width 8
        p_boolPointer = new bool[v_bitWidth];
        for (uint8_t temp = 0; temp < v_bitWidth; temp++) {
            p_boolPointer[temp] = false;// with all bits set to 0
        }
        v_objectStatus = 1;//set validity
    }
}

Bitset::Bitset(const std::string &value) {
    v_bitWidth = value.size();
    p_boolPointer = new bool[v_bitWidth];
    v_objectStatus = 1;
    for (uint8_t temp = 0; temp < v_bitWidth; temp++) {
        char l_tempChar = value[temp];
        if (l_tempChar == '0') {
            p_boolPointer[temp] = false;
        } else if (l_tempChar == '1') {
            p_boolPointer[temp] = true;
        } else {
            v_objectStatus = 2;//set validity
            break;
        }
    }
}

Bitset::~Bitset() {
    if (p_boolPointer != nullptr)
        delete[] p_boolPointer;
}

intmax_t Bitset::size() const {
    return v_bitWidth;
}

bool Bitset::good() const {
    switch (v_objectStatus) {
        case 1:
            return true;
            break;
        default:
            return false;
    }
}

void Bitset::set(intmax_t index) {
    if (index < 0 || index > (v_bitWidth - 1)) {
        v_objectStatus = 2;//then the bitset becomes invalid
    } else {
        p_boolPointer[index] = true;
    }
}

void Bitset::reset(intmax_t index) {
    if (index < 0 || index > (v_bitWidth - 1)) {
        v_objectStatus = 2;//then the bitset becomes invalid
    } else {
        p_boolPointer[index] = false;
    }
}

void Bitset::toggle(intmax_t index) {
    if (index < 0 || index > (v_bitWidth - 1)) {
        v_objectStatus = 2;//then the bitset becomes invalid
    } else {
        p_boolPointer[index] = !(p_boolPointer[index]);// toggle the nth bit
    }
}

bool Bitset::test(intmax_t index) {
    if (index < 0 || index > (v_bitWidth - 1)) {
        v_objectStatus = 2;//then the bitset becomes invalid
        return false;
    } else {
        return p_boolPointer[index];
    }
}

std::string Bitset::asString() const{
    char stringToReturn[v_bitWidth+1];
    for(uint8_t temp=0;temp<v_bitWidth;temp++){
        if(p_boolPointer[temp])
            stringToReturn[temp]='1';//append char
        else
            stringToReturn[temp]='0';//append char
    }
    stringToReturn[v_bitWidth]='\0';//append char of terminating char
    return stringToReturn;
}
