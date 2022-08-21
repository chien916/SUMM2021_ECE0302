#ifndef BITSET_HPP
#define BITSET_HPP

#include <stdint-gcc.h>
#include <iostream>//DELETE THIS AFTER!
#include <string>//DELETE THIS AFTER!

class Bitset {
public:

    /**
     * default construction of a valid bitset of width 8, with all bits set to 0
     */
    Bitset();

    /**
    * construction of a valid bitset of width N, where N is of type intmax_t,
    * with all bits set to 0, the bitset is invalid if N <= 0.
    *
    * @param size type intmax_t of the width of bitset
    */
    Bitset(intmax_t size);

    /**
    * construction of a valid bitset initialized with a string of the form 00010000.
    * If the string contains any character other than 0 or 1, the bitset is invalid.
    *
    * @param value type string of the bitset
    */
    Bitset(const std::string &value);

    /**
    * destructor that destruct the Bitset object
    */
    ~Bitset();

    Bitset(const Bitset &) = delete;

    Bitset &operator=(const Bitset &) = delete;

    /**
    * a method to return the size of the bitset
    *
    * @return type intmax_t of the width of this Bitset
    */
    intmax_t size() const;

    /**
    * a method to determine if the bitset is valid
    *
    * @return type bool of the validity of thie Bitset
    */
    bool good() const;

    /**
     * a method to set the nth bit to 1
     * if n not in [0, size-1] then the bitset becomes invalid
     *
     * @param index type intmax_t of the index of which in Bitset looking for
     */
    void set(intmax_t index);

    /**
     * a method to reset the nth bit to 0, if n not in [0, size-1] then the bitset becomes invalid
     *
     * @param index type intmax_t of the index of which in Bitset looking for
     */
    void reset(intmax_t index);

    /**
     * a method to toggle the nth bit (1 to 0 or 0 to 1)
     * if n not in [0,size-1] then the bitset becomes invalid
     *
     * @param index type intmax_t of the index of which in Bitset looking for
     */
    void toggle(intmax_t index);

    /**
     * a method to test if the nth bit is set by
     * returning a bool value of true if set and false if not,
     * if n not in [0,size-1] then the bitset becomes invalid and false is returned
     *
     * @param index type intmax_t of the index of which in Bitset looking for
     * @return type bool of the bit tested resulting
     */
    bool test(intmax_t index);

    /**
     * a  method  to  return  the  bitset  as  a  std::string  of 0 or 1 characters
     * This  should  be represented left-to-right with the most significant bit first
     *
     * @return type string of the string representation of this Bitset
     */
    std::string asString() const;

private:

    uint8_t v_objectStatus = 0;//0-Uninitialized 1-Valid 2-Invalid
    intmax_t v_bitWidth = 0;
    bool *p_boolPointer = nullptr;
};

#endif
