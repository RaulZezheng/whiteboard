#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("login");
    this->setAttribute(Qt::WA_DeleteOnClose,false);

    //connect signals and slots
    connect(ui->backButton,&QPushButton::clicked,[=](){
       emit backSignal();
    });
    connect(ui->loginButton,&QPushButton::clicked,this,&Login::loginButtonClicked);

}

void Login::loginButtonClicked(){
    this->hide();
    username = ui->unameInput->text().toStdString();
    password = ui->pwdInput->text().toStdString();

    mainWidget = new MainWidget(0);
    //back to main widget
    connect(mainWidget,&MainWidget::backSignal,[=](){
      mainWidget->close();
      this->show();
    });
    mainWidget->show();

}

Login::~Login()
{
    delete ui;
}
