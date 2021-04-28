#include "QtWidgetsExsample.h"
#include <string>
#include <QMessageBox>
#include <QFileDialog>
#include <QButtonGroup>

QtWidgetsExsample::QtWidgetsExsample(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
	makeMenu();
	makeStatusBar();
	makeCentralWidget();
	makeLabel();
	makeLineEdit();
	makeTableWidgetVertex();
	makeTableWidgetData();
	makePushButton();
	makeSpinBox();
}


void QtWidgetsExsample::makeMenu()
{
	// メニューを追加
	QMenu* menu_file = new QMenu(QString::fromLocal8Bit("ファイル"), this);

	// セパレータを追加
	QAction* actionDirectoryOpen = new QAction(QString::fromLocal8Bit("開く"), this);
	menu_file->addAction(actionDirectoryOpen);

	connect(actionDirectoryOpen, &QAction::triggered, this, &QtWidgetsExsample::on_pushButtonDirectoryOpen_clicked);

	QAction* actionExit = new QAction(QString::fromLocal8Bit("終了"), this);
	menu_file->addAction(actionExit);
	
	connect(actionExit, &QAction::triggered, this, &QWidget::close);
	menuBar()->addMenu(menu_file);

	// メニューを追加
	QMenu* menu_help = new QMenu(QString::fromLocal8Bit("ヘルプ"), this);
	QAction* actionVersion = new QAction(QString::fromLocal8Bit("バージョン"), this);
	menu_help->addAction(actionVersion);
	
	connect(actionVersion, &QAction::triggered, this, &QtWidgetsExsample::on_menuBarHelp_triggered);
	menuBar()->addMenu(menu_help);
}

void QtWidgetsExsample::makeStatusBar()
{
}

void QtWidgetsExsample::makeCentralWidget()
{
	// 背景色
	ui.centralWidget->setStyleSheet("#centralWidget {background-color: green;}");
}

void QtWidgetsExsample::makeLabel()
{
	ui.labelTitle->setText(QString::fromLocal8Bit("Qt Example Code"));
	ui.labelTitle->setStyleSheet("font-size: 30px;font-weight: bold; color: red");
}


void QtWidgetsExsample::makePushButton()
{
	ui.pushButtonDirectoryOpen->setText("");
	ui.pushButtonDirectoryOpen->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));

	ui.pushButtonFileOpen->setText("");
	ui.pushButtonFileOpen->setIcon(style()->standardIcon(QStyle::SP_FileIcon));

	ui.pushButtonMessageBoxShow->setText(QString::fromLocal8Bit("メッセージボックスを表示"));
	ui.pushButtonTableInsert->setText(QString::fromLocal8Bit("テーブルを追加"));
	ui.pushButtonExit->setText(QString::fromLocal8Bit("終了"));
}


void QtWidgetsExsample::makeLineEdit()
{
	ui.lineEditDirectoryPath->setPlaceholderText(QString::fromLocal8Bit("フォルダパス"));
	ui.lineEditFilePath->setPlaceholderText(QString::fromLocal8Bit("ファイルパス"));
}

void QtWidgetsExsample::makeTableWidgetData()
{
	const std::vector<std::string> HEADERS =
	{
		"index", "x", "y", "z", "w"
	};

	const int ROWS = 6;
	const int COLS = HEADERS.size();

	QTableWidget* tw = ui.tableWidgetVertex;
	tw->clear();
	tw->setRowCount(ROWS);
	tw->setColumnCount(COLS);

	// ヘッダを設定
	for (int col = 0; col < COLS; col++) {
		QString column_name = QString::fromLocal8Bit(HEADERS[col].c_str());
		tw->setHorizontalHeaderItem(col, new QTableWidgetItem(QString::fromLocal8Bit(HEADERS[col].c_str())));
	}
	
	// ストレッチを設定
	tw->horizontalHeader()->setStretchLastSection(false);
	tw->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	tw->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	tw->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
	tw->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

	tw->verticalHeader()->setVisible(false);				// 垂直ヘッダーを非表示
	tw->setEditTriggers(QAbstractItemView::NoEditTriggers);	// セル編集を不可にする
	tw->setSelectionMode(QAbstractItemView::NoSelection);	// 選択不可にする
}

void QtWidgetsExsample::makeTableWidgetVertex()
{
	const int ROWS = 0;
	const int COLS = 2;

	QTableWidget* tw = ui.tableWidgetData;
	tw->clear();
	tw->setColumnCount(ROWS);
	tw->setColumnCount(COLS);

	// ヘッダを設定
	tw->setHorizontalHeaderItem(0, new QTableWidgetItem(QString::fromLocal8Bit("data")));
	tw->setHorizontalHeaderItem(1, new QTableWidgetItem(QString::fromLocal8Bit("icon")));

	// ストレッチを設定
	tw->horizontalHeader()->setStretchLastSection(false);
	tw->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	tw->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

	tw->horizontalHeader()->setVisible(false);				// 水平ヘッダーを非常時
	tw->setEditTriggers(QAbstractItemView::NoEditTriggers);	// セル編集を不可にする
	tw->setSelectionMode(QAbstractItemView::NoSelection);	// 選択不可にする
}



void QtWidgetsExsample::makeSpinBox()
{
	ui.spinBox->setMaximum(999);
}


void QtWidgetsExsample::on_pushButtoDataSetting_clicked()
{
	QPushButton* button = dynamic_cast<QPushButton*>(sender());
	int index = button->objectName().replace("dataSettingBtn", "").toInt();

	ui_setting = new DataSetting(index, this);
	ui_setting->show();
}


void QtWidgetsExsample::on_menuBarHelp_triggered()
{
	QString version = QString::fromLocal8Bit("Qt version %1").arg(qVersion());

	QMessageBox* msgBox = new QMessageBox(
		QMessageBox::NoIcon,
		QString::fromLocal8Bit("Qtのバージョン情報"),
		version,
		QMessageBox::NoButton,
		this);
	msgBox->exec();
}

void QtWidgetsExsample::on_pushButtonDirectoryOpen_clicked()
{
	QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

	QString path = QFileDialog::getExistingDirectory(
		this,
		QString::fromLocal8Bit("ディレクトリの選択"),
		QString::fromLocal8Bit("初期ディレクトリ"), options);

	if (!path.isEmpty() || ui.lineEditDirectoryPath->text().isEmpty())
	{
		ui.lineEditDirectoryPath->setText(path);
	}
}

void QtWidgetsExsample::on_pushButtonDirectoryInfo_clicked()
{
}

void QtWidgetsExsample::on_pushButtonFileOpen_clicked()
{

	QString path = QFileDialog::getOpenFileName(
		this,
		QString::fromLocal8Bit("ファイルの選択"),
		".",
		QString::fromLocal8Bit("JSON file(*.json);"));

	if (!path.isEmpty() || ui.lineEditFilePath->text().isEmpty())
	{
		ui.lineEditFilePath->setText(path);
	}
}

void QtWidgetsExsample::on_pushButtonFileInfo_clicked()
{
	QFileInfo info(ui.lineEditFilePath->text());
	ui_fileinfo = new FileInfo(info, this);
	ui_fileinfo->show();
}

void QtWidgetsExsample::on_pushButtonMessageBoxShow_clicked()
{
	QMessageBox::information(this,
		QString::fromLocal8Bit("タイトル"),
		QString::fromLocal8Bit("メッセージボックスが表示されました")
		);
}

void QtWidgetsExsample::on_pushButtonTableInsert_clicked()
{
	QTableWidget* tw = ui.tableWidgetData;
	const int ROW = tw->rowCount();
	tw->insertRow(tw->rowCount());

	// データをカラムに追加
	QTableWidgetItem* item = new QTableWidgetItem(QString::fromLocal8Bit("データ%1").arg(ROW));
	tw->setItem(ROW, 0, item);

	// 設定ボタンをカラムに追加
	const QSize BUTTON_SIZE = QSize(10, 10);
	std::string  objName = "dataSettingBtn" + std::to_string(ROW);
	
	QPushButton* button = new QPushButton();
	QIcon icon(":/QtWidgetsExsample/images/icon/gear.png");

	button->setIcon(icon);
	button->resize(BUTTON_SIZE);
	button->setObjectName(QString::fromLocal8Bit(objName.c_str()));

	tw->setIndexWidget(tw->model()->index(ROW, 1), button);

	// シグナル/スロットを接続
	connect(button, &QPushButton::clicked, this, &QtWidgetsExsample::on_pushButtoDataSetting_clicked);
}

void QtWidgetsExsample::on_pushButtonExit_clicked()
{
	int ret = QMessageBox::question(this, 
		QString::fromLocal8Bit("アプリケーションの終了"),
		QString::fromLocal8Bit("終了しますか？"));

	switch (ret) {
	case QMessageBox::Yes:
		QApplication::quit();
		break;
	case QMessageBox::No:
		break;
	default:
		break;
	}
}
