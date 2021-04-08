#include "gui.h"
#include "../../zcpp_vs/zcpp_vs/src/models/sequential.hpp"
#include "../../zcpp_vs/zcpp_vs/src/models/models.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/layers.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/dense.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/softmax.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/relu.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/sigmoid.hpp"
#include <iostream>

ModelConsole::ModelConsole(QFrame* parent) : QFrame(parent)
{
	setFixedSize(450, 450);
	setFrameStyle(QFrame::Panel);
	console = new QTextEdit(this);
	console->setFrameStyle(QFrame::NoFrame);
	console->setGeometry(QRect(QPoint(25, 25), QSize(400, 400)));
	console->setText("Output console:");
	console->setReadOnly(true);
}
ModelCreateLoad::ModelCreateLoad(QFrame* parent, Model* _model, ModelType* _model_type, ModelConsole* _model_console): 
	QFrame(parent), model(_model), model_type(_model_type), model_console(_model_console)
{
	setFixedSize(425, 100);
	setFrameStyle(QFrame::Panel);
	button_create_model = new QPushButton(this);
	button_create_model->setGeometry(QRect(QPoint(25, 25), QSize(175, 50)));
	button_create_model->setText("Create model");
	connect(button_create_model, &QPushButton::released, this, &ModelCreateLoad::handle_create_button);

	button_load_model = new QPushButton(this);
	button_load_model->setGeometry(QRect(QPoint(225, 25), QSize(175, 50)));
	button_load_model->setText("Load model");
	connect(button_load_model, &QPushButton::released, this, &ModelCreateLoad::handle_load_button);
}
void ModelCreateLoad::handle_load_button()
{
	button_create_model->setEnabled(false);
	model_console->console->append("Load model option chosen.");
	setEnabled(false);
}
void ModelCreateLoad::handle_create_button()
{
	button_load_model->setEnabled(false);
	model_console->console->append("Create model option chosen.");
	setEnabled(false);
	model_type->setEnabled(true);
}
ModelType::ModelType(QFrame* parent, Model* _model, ModelCreate* _model_create, ModelConsole* _model_console) : 
	QFrame(parent), model(_model), model_create(_model_create), model_console(_model_console)
{
	setEnabled(false);
	setFixedSize(425, 150);
	setFrameStyle(QFrame::Panel);
	combobox_model_text = new QTextEdit(this);
	combobox_model_text->setFrameStyle(QFrame::NoFrame);
	combobox_model_text->setGeometry(QRect(QPoint(25, 25), QSize(100, 25)));
	combobox_model_text->setText("Choose model:");
	combobox_model_text->setReadOnly(true);

	combobox_model = new QComboBox(this);
	combobox_model->setGeometry(QRect(QPoint(150, 25), QSize(200, 25)));

	for (int i = 0; i < models.size(); ++i)
		combobox_model->addItem(QString::fromStdString(models[i]));

	button_choose_model = new QPushButton(this);
	button_choose_model->setGeometry(QRect(QPoint(125, 75), QSize(175, 50)));
	button_choose_model->setText("Choose model");
	connect(button_choose_model, &QPushButton::released, this, &ModelType::handle_model_button);
}
void ModelType::handle_model_button()
{
	if (combobox_model->currentText() == "Sequential")
	{
		model = new Sequential();
		model_console->console->append("Sequential model chosen.");
	}
	model_create->setEnabled(true);
	setEnabled(false);
}
ModelCreate::ModelCreate(QFrame* parent, Model* _model, ModelConsole* _model_console) : 
	QFrame(parent), model(_model), model_console(_model_console)
{
	setEnabled(false);
	setFixedSize(425, 200);
	setFrameStyle(QFrame::Panel);
	combobox_layers_text = new QTextEdit(this);
	combobox_layers_text->setFrameStyle(QFrame::NoFrame);
	combobox_layers_text->setGeometry(QRect(QPoint(25, 25), QSize(75, 25)));
	combobox_layers_text->setText("Add layer:");
	combobox_layers_text->setReadOnly(true);

	combobox_layers = new QComboBox(this);
	combobox_layers->setGeometry(QRect(QPoint(150, 25), QSize(200, 25)));
	for (int i = 0; i < layers.size(); ++i)
		combobox_layers->addItem(QString::fromStdString(layers[i]));

	input_size_text = new QTextEdit(this);
	input_size_text->setFrameStyle(QFrame::NoFrame);
	input_size_text->setGeometry(QRect(QPoint(25, 75), QSize(75, 25)));
	input_size_text->setText("Input size:");
	input_size_text->setReadOnly(true);

	input_size = new QLineEdit(this);
	input_size->setText("1");
	input_size->setGeometry(QRect(QPoint(125, 75), QSize(50, 25)));

	output_size_text = new QTextEdit(this);
	output_size_text->setFrameStyle(QFrame::NoFrame);
	output_size_text->setGeometry(QRect(QPoint(200, 75), QSize(80, 25)));
	output_size_text->setText("Output size:");
	output_size_text->setReadOnly(true);

	output_size = new QLineEdit(this);
	output_size->setGeometry(QRect(QPoint(300, 75), QSize(50, 25)));
	output_size->setText("1");

	button_add_layer = new QPushButton(this);
	button_add_layer->setGeometry(QRect(QPoint(125, 125), QSize(175, 50)));
	button_add_layer->setText("Add layer");
	connect(button_add_layer, &QPushButton::released, this, &ModelCreate::handle_layer_button);
};
void ModelCreate::handle_layer_button()
{
	update();
	if (combobox_layers->currentText() == "Dense")
	{
		model->add(Dense(input_size->text().toInt(), output_size->text().toInt()));
		model_console->console->append("Dense layer added with input size " + input_size->text() + 
			" and output size " + output_size->text() + ".");
	}
	if (combobox_layers->currentText() == "Softmax")
	{
		model->add(Softmax(input_size->text().toInt()));
		model_console->console->append("Softmax layer added.");
	}
	if (combobox_layers->currentText() == "ReLU")
	{
		model->add(ReLU(input_size->text().toInt()));
		model_console->console->append("ReLU layer added.");
	}
	if (combobox_layers->currentText() == "Sigmoid")
	{
		model->add(Sigmoid(input_size->text().toInt()));
		model_console->console->append("Sigmoid layer added.");
	}
}
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setFixedSize(1000, 900);

	model_console = new ModelConsole((QFrame*)this);
	model_console->setGeometry(QRect(QPoint(525, 425), QPoint(200, 300)));

	model_create = new ModelCreate((QFrame*)this, &model, model_console);
	model_create->setGeometry(QRect(QPoint(50, 345), QPoint(200, 100)));

	model_type = new ModelType((QFrame*)this, &model, model_create, model_console);
	model_type->setGeometry(QRect(QPoint(50, 170), QPoint(200, 75)));

	model_create_load = new ModelCreateLoad((QFrame*)this, &model, model_type, model_console);
	model_create_load->setGeometry(QRect(QPoint(50, 50), QPoint(200, 100)));
}