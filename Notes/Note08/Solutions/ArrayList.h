#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "Array.h"
#include <stdexcept>

namespace dsn
{
    template <class T>
    class IArrayList 
    {
        public:
        virtual void append(const T&) = 0; //O(1)
        virtual void insert(const T&,size_t) = 0; //O(n)
        virtual void detach() = 0; //O(1)
        virtual void remove(const T&) = 0; //O(n)
        virtual bool empty() const = 0; //O(1)
        virtual size_t length() const = 0; //O(1)
        virtual T& at(size_t) = 0; //O(1)
        virtual const T& at(size_t) const = 0; //O(1) 
        virtual bool contains(const T&) const = 0; //O(n)
        virtual size_t find(const T&) const = 0; //O(n)
    };

    template <class T>
    class ArrayList : public IArrayList<T> 
    {
        private:
        Array data;
        size_t size;

        public:
        ArrayList() : size(0), data(100) {}

        void append(const T& item) override
        {
            if(size < data.size())
            {
                data[size] = item;
                size += 1;
            }
        }

        void insert(const T& item,size_t idx) override 
        {
            if(idx >= 0 && idx <= size && size < data.size())
            {
                for(size_t i = size;i > idx;i -= 1)
                {
                    data[i] = data[i-1];
                }
                data[idx] = item;
                size += 1;
            }
        }

        void detach() override 
        {
            if(size > 0)
            {
                size -= 1;
            }
        }

        void remove(const T& item) override
        {
            size_t i = 0;

            while(i < size && data[i] != item)
            {
                i += 1;
            }

            if(i != size)
            {
                size -= 1;
                
                while(i < size)
                {
                    data[i] = data[i+1];
                    i += 1;
                } 
            }
        }

        bool empty() const override
        {
            return size == 0;
        }

        size_t length() const override 
        {
            return size;
        }

        T& at(size_t idx) override
        {
            if(idx < size) 
            {
                return data[idx];
            }
            throw std::out_of_range("invalid index");
        }

        const T& at(size_t idx) const override
        {
            if(idx < size) 
            {
                return data[idx];
            }
            throw std::out_of_range("invalid index");
        }

        bool contains(const T& item) const override 
        {
            size_t i = 0;

            while(i < size && data[i] != item)
            {
                i += 1;
            }
            return i != size;      
        }

        size_t find(const T& item) const override 
        {
            size_t i = 0;

            while(i < size && data[i] != item)
            {
                i += 1;
            }
            return i;      
        }
        
    };
}
#endif