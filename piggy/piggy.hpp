#pragma once
#include <ostream>
#include <string>

namespace tiere {
    class piggy
    {
    private:
        std::string name_;
        int gewicht_;

    public:
        explicit piggy(const std::string name = "nobody") ;
        virtual ~piggy() = default;
        virtual void fressen();
        virtual void set_name(std::string );
        virtual std::string get_name() const;
        virtual int get_gewicht() const;


    };

    std::ostream& operator << (std::ostream& out, const piggy& schwein);

}

