#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace dsn 
{
    class RegularPolygon 
    {
        private:
        double length;
        int sides;

        public:
        //default constructor 
        RegularPolygon() : length(1), sides(3) {}

        //Copy Constructor
        RegularPolygon(const RegularPolygon& obj)
        {
            length = obj.length;
            sides = obj.sides;
        }

        RegularPolygon(int sides) : RegularPolygon() 
        {
            setSides(sides);
        }

        RegularPolygon(double length, int sides) : RegularPolygon()
        {
            if(length > 0 && sides >= 3)
            {
                this->length = length;
                this->sides = sides; 
            }
        }

        //Assignment 
        RegularPolygon& operator=(const RegularPolygon& rhs)
        {
            if(this != &rhs)
            {
                length = rhs.length;
                sides = rhs.sides;
            }
            return *this;
        }

        //Destructor 
        virtual ~RegularPolygon() {}

        //Getter Methods
        double getLength() const {return length;}
        
        int getSides() const {return sides;}

        //Setter Methods
        void setLength(double value)
        {
            if(value > 0)
            {
                length = 0;
            }
        }

        void setSides(int value)
        {
            if(value >= 3)
            {
                sides = value;
            }
        }

        virtual RegularPolygon& increment() 
        {
            length += 1;
            return *this;
        }

        double perimeter() const {return length * sides;}

        virtual std::string toString() const 
        {
            std::stringstream out;
            out << std::fixed << std::setprecision(2);
            out << "[" << sides << ":" << length << "]";
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out,const RegularPolygon& obj)
        {
            return out << obj.toString();
        }
    };

    //Derived Class (Subclass)
    class Square : public RegularPolygon 
    {
        private: 
        using RegularPolygon::getLength;
        using RegularPolygon::setLength;
        using RegularPolygon::setSides;
        using RegularPolygon::getSides;

        public:
        Square() : RegularPolygon(4) {}

        Square(double length) : RegularPolygon(length,4) {}

        Square(const Square& obj) : RegularPolygon(static_cast<const RegularPolygon&>(obj)) {} 

        Square& operator=(const Square& rhs)
        {
            if(this != &rhs)
            {
                RegularPolygon::operator=(static_cast<const RegularPolygon&>(rhs));
            }
            return *this;
        }

        ~Square() {}

        double getSide() const {return RegularPolygon::getLength();}

        void setSide(double value)
        {
            RegularPolygon::setLength(value);
        }

        Square& increment() override 
        {
            RegularPolygon::increment().RegularPolygon::increment();
            return *this;
        }

        std::string toString() const override
        {
            std::stringstream out;
            out << std::fixed << std::setprecision(1);
            out << "[" << RegularPolygon::getLength() << "]";
            return out.str();
        }

    };
}

#endif