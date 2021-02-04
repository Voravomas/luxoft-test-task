#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactlistprovider.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

// Method that shows active call via QMessageBox
void MainWindow::call()
{
    std::string finStr = "Calling +380971231231";
    QMessageBox::information(this, "Call Info", finStr.c_str());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // path to image
    char img_path[] = "../luxoft0/img/linus.jpeg";

    // get Contacts
    ContactListProvider provider;
    std::vector<Person> contacts = provider.getContact();

    // creating widget
    QWidget * wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);

    // adding buttons in cycle
    int v_size = contacts.size();
    for (int var = 0; var < v_size; ++var) {
        std::string fullName = contacts[var].name + " " + contacts[var].surname;
        // creating button
        QPushButton *btn = new QPushButton(fullName.c_str());

        // customizing button
        QPixmap pixmap(img_path);
        QIcon ButtonIcon(pixmap);
        btn->setIcon(ButtonIcon);
        btn->setIconSize(QSize(50, 50));
        btn->setFixedSize(300, 50);
        btn->setStyleSheet("background-color: rgb(4,132,132);border: none; Text-align:left;");

        vlay->addWidget(btn);
        // adding reaction to button
        connect(btn, SIGNAL(clicked()), this ,SLOT(call()));
    }
    wdg->setLayout(vlay);
    setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

