#include <iostream>

const int bit = 8 * sizeof(int);

template <size_t number>
class Bitset {
    
    int m_set[number];
    
public:
    
    Bitset ();
    ~Bitset ();
    
    void set (int );
    void unset (int );
    int get (int );
};

template <size_t number>
Bitset<number>::Bitset ()
{
    std::fill(m_set, m_set + number , 0);
}

template <size_t number>
Bitset<number>::~Bitset ()
{
    std::cout << "Destructor is invoked !" << std::endl;
}

template <size_t number>
void Bitset<number>::set (int pos) 
{
    m_set[pos / bit] |= (1 << (pos % bit));
}

template <size_t number>
void Bitset<number>::unset (int pos) 
{
    m_set[pos / bit] &= !(1 << (pos % bit));
}


template <size_t number>
int Bitset<number>::get (int pos)
{
    m_set[pos / bit] &= (1 << (pos % bit));
    if (m_set[pos / bit] == 0)
       return 0;
    return 1;
}

int main()
{
 Bitset<5> bitset;
 bitset.set(27);
 int tmp = bitset.get(27);
 std::cout << tmp <<std::endl;
 bitset.unset(27);
 tmp = bitset.get(27);
 std::cout << tmp << std::endl;
return 0;
}
