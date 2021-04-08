#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <qcombobox.h>
#include <QTextEdit>
#include <QLineEdit>
#include "../../zcpp_vs/zcpp_vs/src/models/model.hpp"

class ModelConsole : public QFrame
{
	Q_OBJECT
public:
	explicit ModelConsole(QFrame* parent = nullptr);
	QTextEdit* console;
};

class ModelCreate : public QFrame
{
	Q_OBJECT
public:
	explicit ModelCreate(QFrame* parent = nullptr, Model* model = nullptr, ModelConsole* model_console = nullptr);
	Model* model;
	void handle_layer_button();
private:
	ModelConsole* model_console;
	QTextEdit* combobox_layers_text;
	QComboBox* combobox_layers;
	QTextEdit* input_size_text;
	QLineEdit* input_size;
	QTextEdit* output_size_text;
	QLineEdit* output_size;
	QPushButton* button_add_layer;
};

class ModelType : public QFrame
{
	Q_OBJECT
public:
	explicit ModelType(QFrame* parent = nullptr, Model* model = nullptr, ModelCreate* _model_create = nullptr, ModelConsole* model_console = nullptr);
	Model* model;
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
	ModelCreateLoad(QFrame* parent = nullptr, Model* model = nullptr, ModelType* _model_type = nullptr, ModelConsole* model_console = nullptr);
	Model* model;
	void handle_load_button();
	void handle_create_button();
private:
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
	Model model;
private:
	ModelCreateLoad* model_create_load;
	ModelType* model_type;
	ModelCreate* model_create;
	ModelConsole* model_console;
};
#endif