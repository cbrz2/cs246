#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> //fixed(), setprecision()
#include <stdexcept>

namespace dsn
{
    //Interface 
    class Object 
    {
        virtual std::string toString() const = 0;

        friend std::ostream& operator<<(std::ostream& out,const Object& obj)
        {
            return out << obj.toString();
        }
    };

    //Interface 
    class Polygon : public Object  
    {
        public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual int sides() const = 0;
    };

    class RegularPolygon : public Polygon 
    {
        private:
        double len;

        public:
        RegularPolygon() : len(1) {}

        RegularPolygon(const RegularPolygon& obj) 
        {
            len = obj.len;
        }

        RegularPolygon& operator=(const RegularPolygon& rhs)
        {
            if(this != &rhs)
            {
                len = rhs.len;
            }
            return *this;
        }

        virtual ~RegularPolygon() {}

        double length() const {return len;}

        void length(double value) 
        {
            if(value > 0)
            {
                len = value;
            }
        }

        double perimeter() const override
        {
            return len * sides();
        }

        std::string toString() const override
        {
            std::stringstream out;

            out << "(";
            out << std::fixed << std::setprecision(2);

            for(int i = 0;i < sides();i += 1)
            {
                out << len;

                if(i + 1 < sides())
                {
                    out << ",";
                }
            }
            out << ")";
            return out.str();
        }
    };

    class Square : public RegularPolygon 
    {
        public: 
        Square() {}
        Square(double value) {length(value);}
        Square(const Square& obj) : RegularPolygon(obj) {}
        
        Square& operator=(const Square& rhs)
        {
            if(this != &rhs)
            {
                RegularPolygon::operator=(rhs);
            }
            return *this;
        }

        ~Square() {}
        int sides() const override {return 4;}
        double area() const override {return pow(length(),2);}
    };

    class EquilateralTriangle : public RegularPolygon 
    {
        public: 
        EquilateralTriangle() {}
        EquilateralTriangle(double value) {length(value);}
        EquilateralTriangle(const EquilateralTriangle& obj) : RegularPolygon(obj) {}
        
        EquilateralTriangle& operator=(const EquilateralTriangle& rhs)
        {
            if(this != &rhs)
            {
                RegularPolygon::operator=(rhs);
            }
            return *this;
        }

        ~EquilateralTriangle() {}
        int sides() const override {return 3;}
        double area() const override {return 0.5 * pow(length(),2) * sin(3.14159265/3);}
    };

    class IrregularPolygon : public Polygon
    {
        private:
        double* lens;
        int count;

        public:
        IrregularPolygon() : IrregularPolygon(3) {}

        IrregularPolygon(int size) : count(size) 
        {
            if(count < 3) 
            {
                count = 3;
            }
            lens = new double[count];

            for(int i = 0;i < count;i += 1)
            {
                lens[i] = 1.0;
            }
        }

        IrregularPolygon(const IrregularPolygon& obj)
        {
            count = obj.count;
            lens = new double[count];

            for(int i = 0;i < count; i += 1)
            {
                lens[i] = obj.lens[i];
            }
        }

        IrregularPolygon& operator=(const IrregularPolygon& obj)
        {
            if(this != &rhs)
            {
                count = rhs.count;
                delete[] lens;
                lens = new double[count];

                for(int i = 0;i < count; i += 1)
                {
                    lens[i] = rhs.lens[i];
                }
            }
            return *this;
        }

        virtual ~IrregularPolygon() {delete[] lens;}

        double length(int idx) const 
        {
            if(idx >= 0 && idx < count)
            {
                return lens[idx];
            }
            throw std::out_of_range("invalid index");
        }

        void length(int idx, double value)
        {
            if(idx >= 0 && idx < count && value > 0)
            {
                lens[idx] = value;
            }
        }

        int sides() const override {return count;}

        double perimeter() const override
        {
            double sum = 0;

            for(int i = 0;i < count;i += 1)
            {
                sum += lens[i];
            }
            return sum;
        }

        std::string toString() const override
        {
            std::stringstream out;

            out << "(";
            out << std::fixed << std::setprecision(2);

            for(int i = 0;i < sides();i += 1)
            {
                out << lens[i];

                if(i + 1 < count)
                {
                    out << ",";
                }
            }
            out << ")";
            return out.str();
        }

    };

    class Rectangle : public IrregularPolygon 
    {
        public:
        Rectangle() {}
        Rectangle(double l,double w) 
        {
            length(0,l);
            length(2,l);
            length(1,w);
            length(3,w);
        }
    }
}

#endif