# Project of Neural Network for MNIST digits classification

The goal of this project is to create a functionality for building neural network for multiclass classification. 
It's written from scrach in C++. 
In addition, I also created a GUI in QT Framework, which enables to build network easily and see results of its performance quickly.


## Assumptions
### General
1. The project is adjusted for specific kind of problem, which is multiclass classification for [MNIST dataset](http://yann.lecun.com/exdb/mnist/).
2. Every digit consitis of 28 x 28 pixels, which represent it on the grid. As a consequence, first dense layer of the network must contain 28 * 28 = 784 neurons.
3. There are 10 possible outputs (from 0 to 9), so the last layer, which must be Softmax (an activation layer for multiclass classification), must have 10 neurons.
4. There is on specific model type implemented: Sequential model.
5. There are 4 kinds of layers implemented: Dense, ReLU (activation layer), Sigmoid (activation layer), Softmax (activation layer).
6. Number of neurons in layers must cause a smooth reduction from 784 to 10 (e.g. Dense: (784, 128), Sigmoid: (128), Dense: (128, 10), Softmax: (10)). 
7. You can see an example of the run in zcpp_vs/zcpp_vs/tests/main/main.cpp file.
 
### Code
1. I used Visual Studio and you can find projects ready to build in the repo.
2. Dense layer contain weights representing neurons as generic matrix Martix<float> (this class wasw implemented from scrach as well).
3. Model implements some simplified interfaces (train, predict, save, load) more or less consistent with tensorflow library.
### GUI
1. GUI is built in QT framework (vesion 5.15.2).
2. There are some custom widgets implemented for building and training the model. There's also a console that shows results of actions and a 28 x 28 grid, where a user
can draw a digit (pixel by pixel).

## Code structure
1. Source code for neural network is in zcpp_vs/zcpp_vs/src folder. There you can find:
	1.1. data_management - package used for loading the data from csv files. 
	1.2. layers - package with layers.
	1.3. matrix - folder with generic matrix implementation. 
	1.4. models - package with models.
2. An example run of the neural network is located in zcpp_vs/zcpp_vs/tests/main.cpp. 
3. Source code for GUI can be found in giu/gui/ folder (gui.hpp and gui.cpp files).
4. In folder utils there is a training dataset stored and some saved model.