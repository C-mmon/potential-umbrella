int addTwoNumber(int a, int b)
{
    int carry;
    while (b != 0)
    {
        carry = (a & b) << 1; // carry
        a = a ^ b;            // sum without carry
        b = carry;            // move carry
    }
    return a;
}
