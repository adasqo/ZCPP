#include "gui.h"
#include "../../zcpp_vs/zcpp_vs/src/models/sequential.hpp"
#include "../../zcpp_vs/zcpp_vs/src/models/models.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/layers.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/dense.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/softmax.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/relu.hpp"
#include "../../zcpp_vs/zcpp_vs/src/layers/activation/sigmoid.hpp"
#include "../../zcpp_vs/zcpp_vs/src/data_management/data_updater_loader.hpp"
#include <iostream>

ModelConsole::ModelConsole(QFrame* parent) : QFrame(parent)
{
	setFixedSize(450, 350);
	setFrameStyle(QFrame::Panel);
	console = new QTextEdit(this);
	console->setFrameStyle(QFrame::NoFrame);
	console->setGeometry(QRect(QPoint(25, 25), QSize(400, 300)));
	console->setText("Output console:");
	console->setReadOnly(true);
}
ModelCreateLoad::ModelCreateLoad(QFrame* parent, Model** _model, ModelType* _model_type, ModelConsole* _model_console, ModelPredict* _model_predict):
	QFrame(parent), model_type(_model_type), model_console(_model_console), model_predict(_model_predict)
{
	model = _model;
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
	*model = new Model();
	*model = (*model)->load(QFileDialog::getOpenFileName(this, "Load input filename", "").toStdString());
	model_console->console->append("Model loaded.");
	setEnabled(false);
	model_predict->setEnabled(true);
}
void ModelCreateLoad::handle_create_button()
{
	button_load_model->setEnabled(false);
	model_console->console->append("Create model option chosen.");
	setEnabled(false);
	model_type->setEnabled(true);
}
ModelType::ModelType(QFrame* parent, Model** _model, ModelCreate* _model_create, ModelConsole* _model_console) :
	QFrame(parent), model_create(_model_create), model_console(_model_console)
{
	model = _model;
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
		*model = new Sequential();
		model_console->console->append("Sequential model chosen.");
	}
	model_create->setEnabled(true);
	setEnabled(false);
}
ModelCreate::ModelCreate(QFrame* parent, Model** _model, ModelConsole* _model_console, ModelTrain* _model_train) :
	QFrame(parent), model_console(_model_console), model_train(_model_train)
{
	model = _model;
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
	button_add_layer->setGeometry(QRect(QPoint(25, 125), QSize(175, 50)));
	button_add_layer->setText("Add layer");
	connect(button_add_layer, &QPushButton::released, this, &ModelCreate::handle_layer_button);

	button_confirm = new QPushButton(this);
	button_confirm->setGeometry(QRect(QPoint(225, 125), QSize(175, 50)));
	button_confirm->setText("Confirm");
	connect(button_confirm, &QPushButton::released, this, &ModelCreate::handle_confirm_button);
};
void ModelCreate::handle_layer_button()
{
	update(); int m = input_size->text().toInt();
	if (combobox_layers->currentText() == "Dense")
	{
		(*model)->add(new Dense(input_size->text().toInt(), output_size->text().toInt()));
		model_console->console->append("Dense layer added with input size " + input_size->text() + 
			" and output size " + output_size->text() + ".");
	}
	if (combobox_layers->currentText() == "Softmax")
	{
		(*model)->add(new Softmax(input_size->text().toInt()));
		model_console->console->append("Softmax layer with input size " + input_size->text() + " added.");
	}
	if (combobox_layers->currentText() == "ReLU")
	{
		(*model)->add(new ReLU(input_size->text().toInt()));
		model_console->console->append("ReLU layer with input size " + input_size->text() + " added.");
	}
	if (combobox_layers->currentText() == "Sigmoid")
	{
		(*model)->add(new Sigmoid(input_size->text().toInt()));
		model_console->console->append("Sigmoid layer with input size " + input_size->text() + " added.");
	}
}
void ModelCreate::handle_confirm_button()
{
	model_train->setEnabled(true);
	setEnabled(false);
}
ModelTrain::ModelTrain(QFrame* parent, Model** _model, ModelConsole* _model_console, ModelPredict* _model_predict, QPushButton* _button_save) :
	QFrame(parent), model(_model), model_console(_model_console), model_predict(_model_predict), button_save(_button_save)
{
	setEnabled(false);
	setFixedSize(425, 200);
	setFrameStyle(QFrame::Panel);

	epochs_text = new QTextEdit(this);
	epochs_text->setFrameStyle(QFrame::NoFrame);
	epochs_text->setGeometry(QRect(QPoint(25, 25), QSize(125, 25)));
	epochs_text->setText("Number of epochs:");
	epochs_text->setReadOnly(true);

	epochs_size = new QLineEdit(this);
	epochs_size->setText("10");
	epochs_size->setGeometry(QRect(QPoint(150, 25), QSize(50, 25)));

	batch_size_text = new QTextEdit(this);
	batch_size_text->setFrameStyle(QFrame::NoFrame);
	batch_size_text->setGeometry(QRect(QPoint(225, 25), QSize(75, 25)));
	batch_size_text->setText("Batch size:");
	batch_size_text->setReadOnly(true);

	batch_size = new QLineEdit(this);
	batch_size->setText("10");
	batch_size->setGeometry(QRect(QPoint(325, 25), QSize(50, 25)));

	alpha_text = new QTextEdit(this);
	alpha_text->setFrameStyle(QFrame::NoFrame);
	alpha_text->setGeometry(QRect(QPoint(25, 75), QSize(50, 25)));
	alpha_text->setText("Alpha:");
	alpha_text->setReadOnly(true);

	alpha = new QLineEdit(this);
	alpha->setGeometry(QRect(QPoint(100, 75), QSize(50, 25)));
	alpha->setText("1");

	samples_number_text = new QTextEdit(this);
	samples_number_text->setFrameStyle(QFrame::NoFrame);
	samples_number_text->setGeometry(QRect(QPoint(175, 75), QSize(125, 25)));
	samples_number_text->setText("Number of samples:");
	samples_number_text->setReadOnly(true);

	samples_number = new QLineEdit(this);
	samples_number->setGeometry(QRect(QPoint(325, 75), QSize(50, 25)));
	samples_number->setText("1");

	button_load_train_data = new QPushButton(this);
	button_load_train_data->setGeometry(QRect(QPoint(25, 125), QSize(175, 50)));
	button_load_train_data->setText("Choose data for training");
	connect(button_load_train_data, &QPushButton::released, this, &ModelTrain::handle_data_button);

	button_train = new QPushButton(this);
	button_train->setGeometry(QRect(QPoint(225, 125), QSize(175, 50)));
	button_train->setText("Train");
	connect(button_train, &QPushButton::released, this, &ModelTrain::handle_train_button);
};
void ModelTrain::handle_data_button()
{
	DataLoader loader = DataLoader();
	model_console->console->append("Loading data.");
	data = loader.load_data(QFileDialog::getOpenFileName(this, "Load input filename", "").toStdString(), samples_number->text().toInt());
	model_console->console->append("Data loaded.");
	button_load_train_data->setEnabled(false);
	epochs_size->setEnabled(false);
	batch_size->setEnabled(false);
	alpha->setEnabled(false);
	alpha->setEnabled(false);
	samples_number->setEnabled(false);
}
void ModelTrain::handle_train_button()
{
	std::string info = (*model)->train(epochs_size->text().toInt(), batch_size->text().toInt(), alpha->text().toInt(), std::get<0>(data), std::get<1>(data));
	model_console->console->append(info.c_str());
	model_predict->setEnabled(true);
	setEnabled(false);
	button_save->setEnabled(true);
}
ModelPredict::ModelPredict(QFrame* parent, Model** _model, ModelConsole* _model_console) :
	QFrame(parent), model(_model), model_console(_model_console)
{
	setEnabled(false);
	setFixedSize(450, 450);
	setFrameStyle(QFrame::Panel);

	button_predict = new QPushButton(this);
	button_predict->setGeometry(QRect(QPoint(175, 375), QSize(100, 50)));
	button_predict->setText("Predict");
	connect(button_predict, &QPushButton::released, this, &ModelPredict::handle_predict_button);

	painter = new QPainter(this);
};
void ModelPredict::handle_predict_button()
{
	Matrix<float> m = Matrix<float>(28 * 28, 1);
	for (int i = 0; i < 28; ++i)
		for (int j = 0; j < 28; ++j)
			if (pixels[i][j] == 1)
				m(i * 28 + j, 0) = 1;

	std::string info = (*model)->predict(m);
	model_console->console->append(info.c_str());

	for (int i = 0; i < 28; ++i)
		for (int j = 0; j < 28; ++j)
			pixels[i][j] = 0;
};
void ModelPredict::paintEvent(QPaintEvent* event)
{
	painter->begin(this);
	QPen pen(Qt::black);
	pen.setWidth(1);
	painter->setPen(pen);
	for (int i = 0; i <= 28; i++)
		painter->drawLine(x + i * width, y, x + i * width, y + height);
	for (int i = 0; i <= 28; i++)
		painter->drawLine(x, y + i * width, x + height, y + i * width);
	for (int i = 0; i < 28; ++i)
		for (int j = 0; j < 28; ++j)
			if (pixels[i][j] == 1)
			{
				QPainterPath path;
				path.addRect(x + i * width, y + j * width, width, width);
				painter->fillPath(path, Qt::black);
			};
	QFrame::paintEvent(event);
	painter->end();
}
void ModelPredict::mousePressEvent(QMouseEvent* event)
{
	QPoint position = event->pos();
	if (position.x() < x || position.x() > x + height || position.y() < y || position.y() > y + height)
		return;
	int pos_x = (position.x() - x) / width;
	int pos_y = (position.y() - y) / width;
	pixels[pos_x][pos_y] = 1;
	QFrame::mousePressEvent(event);
	update();
}
void MainWindow::handle_save_button()
{
	model->save(QFileDialog::getOpenFileName(this, "Save model", "").toStdString());
	model_console->console->append("Model saved.");
	button_save->setEnabled(false);
}
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	setFixedSize(1000, 900);

	model_console = new ModelConsole((QFrame*)this);
	model_console->setGeometry(QRect(QPoint(525, 525), QPoint(200, 300)));

	button_save = new QPushButton(this);
	button_save->setGeometry(QRect(QPoint(175, 800), QSize(175, 50)));
	button_save->setText("Save model");
	connect(button_save, &QPushButton::released, this, &MainWindow::handle_save_button);
	button_save->setEnabled(false);

	model_predict = new ModelPredict((QFrame*)this, &model, model_console);
	model_predict->setGeometry(QRect(QPoint(525, 50), QPoint(200, 200)));

	model_train = new ModelTrain((QFrame*)this, &model, model_console, model_predict, button_save);
	model_train->setGeometry(QRect(QPoint(50, 565), QPoint(200, 100)));

	model_create = new ModelCreate((QFrame*)this, &model, model_console, model_train);
	model_create->setGeometry(QRect(QPoint(50, 345), QPoint(200, 100)));

	model_type = new ModelType((QFrame*)this, &model, model_create, model_console);
	model_type->setGeometry(QRect(QPoint(50, 170), QPoint(200, 75)));

	model_create_load = new ModelCreateLoad((QFrame*)this, &model, model_type, model_console, model_predict);
	model_create_load->setGeometry(QRect(QPoint(50, 50), QPoint(200, 100)));

}