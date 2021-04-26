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
	makeVertexTableWidget();
	makeDataTableWidget();
	makePushButton();
	makeSpinBox();
}


void QtWidgetsExsample::makeMenu()
{
	// メニューバーにファイルを追加
	QMenu* menu_file = new QMenu(QString::fromLocal8Bit("ファイル"), this);
	QMenu* menu_file_open = new QMenu(QString::fromLocal8Bit("開く"));
	menu_file->addMenu(menu_file_open);

	QAction* actionExit = new QAction(QString::fromLocal8Bit("終了"), this);
	connect(menu_file, SIGNAL(triggered()), this, SLOT(close()));
	menu_file->addAction(actionExit);


	menuBar()->addMenu(menu_file);

	// メニューバーにヘルプを追加
	QMenu* menu_help = new QMenu(QString::fromLocal8Bit("ヘルプ"), this);
	menu_help->addAction(QString::fromLocal8Bit("バージョン"));
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
	ui.titleLabel->setText(QString::fromLocal8Bit("Qt Example Code"));
	ui.titleLabel->setStyleSheet("font-size: 30px;font-weight: bold; color: red");
}


void QtWidgetsExsample::makePushButton()
{
	ui.directoryPushButton->setText(QString::fromLocal8Bit("ディレクトリを選択"));
	ui.msgShowPushButton->setText(QString::fromLocal8Bit("メッセージボックスを表示"));
	ui.tableInsertPushButton->setText(QString::fromLocal8Bit("テーブルを追加"));
	ui.exitPushPushButton->setText(QString::fromLocal8Bit("終了"));
}




void QtWidgetsExsample::makeLineEdit()
{
	ui.directoryLineEdit->setPlaceholderText(QString::fromLocal8Bit("フォルダパス"));
}

void QtWidgetsExsample::makeVertexTableWidget()
{
	const std::vector<std::string> HEADERS =
	{
		"index", "X", "Y", "Z", "Angle"
	};

	const int ROWS = 6;
	const int COLS = HEADERS.size();

	QTableWidget* tw = ui.vertexTableWidget;
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

void QtWidgetsExsample::makeDataTableWidget()
{
	const int ROWS = 0;
	const int COLS = 2;

	QTableWidget* tw = ui.dataTableWidget;
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


void QtWidgetsExsample::on_settingPushButton_clicked()
{
	QPushButton* button = dynamic_cast<QPushButton*>(sender());
	QString str = button->objectName().replace("dataSettingBtn", "");

	setting_ui = new DataSetting(str.toInt(), this);
	setting_ui->show();

}


void QtWidgetsExsample::on_directoryPushButton_clicked()
{
	QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;

	QString strDir = QFileDialog::getExistingDirectory(
		this,
		QString::fromLocal8Bit("ダイアログタイトル"),
		QString::fromLocal8Bit("初期ディレクトリ"), options);

	if (!strDir.isEmpty() || ui.directoryLineEdit->text().isEmpty())
	{
		ui.directoryLineEdit->setText(strDir);
	}
}

void QtWidgetsExsample::on_msgShowPushButton_clicked()
{
	QMessageBox* msgBox = new QMessageBox(
		QMessageBox::Information,
		QString::fromLocal8Bit("タイトル"),
		QString::fromLocal8Bit("メッセージボックスが表示されました"),
		QMessageBox::Ok,
		this);

	msgBox->setText(QString::fromLocal8Bit("メッセージボックスが表示されました"));
	msgBox->exec();
}

void QtWidgetsExsample::on_tableInsertPushButton_clicked()
{
	QTableWidget* tw = ui.dataTableWidget;
	const int ROW = tw->rowCount();
	tw->insertRow(tw->rowCount());

	// データをカラムに追加
	QTableWidgetItem* item = new QTableWidgetItem(QString::fromLocal8Bit("データ"));
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
	connect(button, &QPushButton::clicked, this, &QtWidgetsExsample::on_settingPushButton_clicked);
}

void QtWidgetsExsample::on_exitPushPushButton_clicked()
{
	QMessageBox msgBox(this);
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setText(QString::fromLocal8Bit("終了しますか？"));

	int ret = msgBox.exec();

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
