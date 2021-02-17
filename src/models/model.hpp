#pragma once
#include "../layers/layer.hpp"
#include <list>
class Model
{
    private:
        void propagate_forward()
        {
            std::list<Layer>::iterator it;
            // for (it = layers.begin(); it != layers.end(); ++it){
                // std::cout << it->name;
            // }
        }
    protected:
        std::list<Layer> layers;
    public:
        Model()
        {
            layers = std::list<Layer>();
        };
        virtual void add(const Layer&);
        // virtual void compile();
        void train()
        {
            propagate_for
        }
};

void Model::add(const Layer& layer)
{
    layers.push_back(layer);
}