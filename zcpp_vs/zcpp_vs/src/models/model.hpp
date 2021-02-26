#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        void propagate_forward();
    protected:
        std::list<Layer*> layers;
    public:
        Model();
        virtual void add(Layer&);
        // virtual void compile();
        void train();
};
