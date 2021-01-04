#include "multiplizierer.hpp"
class multiplizierer_optimierer : public multiplizierer
{
private:
    multiplizierer& multiplizierer_;
public:
    multiplizierer_optimierer(multiplizierer& multiplizierer) : multiplizierer_(multiplizierer) {}
    long mult(int a, int b) override
    {
        if (a > b)
            return multiplizierer_.mult(b, a);
        else
            return multiplizierer_.mult(a, b);
    }
};
