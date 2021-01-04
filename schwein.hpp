#pragma once
#include <ostream>
#include <string>

namespace tiere {
    class schwein
    {
    private:
        std::string name_;
        int gewicht_;

    public:
        explicit schwein(const std::string name = "nobody") ;
        virtual ~schwein() = default;
        virtual void fressen();
        virtual void set_name(std::string );
        virtual std::string get_name() const;
        virtual int get_gewicht() const;


    };

    std::ostream& operator << (std::ostream& out, const schwein& schwein);

}

