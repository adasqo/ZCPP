#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <qcombobox.h>
#include <QTextEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>

#include "../../zcpp_vs/zcpp_vs/src/models/model.hpp"

class ModelConsole : public QFrame
{
	Q_OBJECT
public:
	explicit ModelConsole(QFrame* parent = nullptr);
	QTextEdit* console;
};

class ModelPredict : public QFrame
{
	Q_OBJECT
public:
	explicit ModelPredict(QFrame* parent = nullptr, Model** model = nullptr, ModelConsole* model_console = nullptr);
	Model** model;
	void handle_predict_button();
	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* event);
private:
	ModelConsole* model_console;
	QPushButton* button_predict;
	QPainter* painter;
	int x = 50;
	int y = 20;
	int width = 12;
	int height = 28 * width;
	int pixels[28][28] = {};
};

class ModelTrain : public QFrame
{
	Q_OBJECT
public:
	explicit ModelTrain(QFrame* parent = nullptr, Model** model = nullptr, ModelConsole* model_console = nullptr, ModelPredict* model_predict = nullptr, QPushButton* button_save = nullptr);
	Model** model;
	void handle_data_button();
	void handle_train_button();
private:
	ModelConsole* model_console;
	ModelPredict* model_predict;
	QPushButton* button_save;
	QTextEdit* epochs_text;
	QLineEdit* epochs_size;
	QTextEdit* batch_size_text;
	QLineEdit* batch_size;
	QTextEdit* alpha_text;
	QLineEdit* alpha;
	QTextEdit* samples_number_text;
	QLineEdit* samples_number;
	QPushButton* button_load_train_data;
	QPushButton* button_train;

	std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> data;
};

class ModelCreate : public QFrame
{
	Q_OBJECT
public:
	explicit ModelCreate(QFrame* parent = nullptr, Model** model = nullptr, ModelConsole* model_console = nullptr, ModelTrain* model_train = nullptr);
	Model** model;
	void handle_layer_button();
	void handle_confirm_button();
private:
	ModelConsole* model_console;
	ModelTrain* model_train;
	QTextEdit* combobox_layers_text;
	QComboBox* combobox_layers;
	QTextEdit* input_size_text;
	QLineEdit* input_size;
	QTextEdit* output_size_text;
	QLineEdit* output_size;
	QPushButton* button_add_layer;
	QPushButton* button_confirm;
};

class ModelType : public QFrame
{
	Q_OBJECT
public:
	explicit ModelType(QFrame* parent = nullptr, Model** model = nullptr, ModelCreate* _model_create = nullptr, ModelConsole* model_console = nullptr);
	Model** model;
	void handle_model_button();
private:
	ModelCreate* model_create;
	ModelConsole* model_console;
	QTextEdit* combobox_model_text;
	QComboBox* combobox_model;
	QPushButton* button_choose_model;

};

class ModelCreateLoad : public QFrame
{
	Q_OBJECT
public:
	ModelCreateLoad(QFrame* parent = nullptr, Model** model = nullptr, ModelType* _model_type = nullptr, ModelConsole* model_console = nullptr, ModelPredict* model_predict = nullptr);
	Model** model;
	void handle_load_button();
	void handle_create_button();
private:
	ModelPredict* model_predict;
	ModelType* model_type;
	ModelConsole* model_console;
	QPushButton* button_load_model;
	QPushButton* button_create_model;
};

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = nullptr);
	Model* model;
private:
	ModelCreateLoad* model_create_load;
	ModelType* model_type;
	ModelCreate* model_create;
	ModelTrain* model_train;
	ModelPredict* model_predict;
	ModelConsole* model_console;
	QPushButton* button_save;
	void handle_save_button();
};
#endif