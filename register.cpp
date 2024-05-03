#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("register");
    this->setAttribute(Qt::WA_DeleteOnClose,false);

    //connect signals and slots
    connect(ui->backButton,&QPushButton::clicked,[=](){
       emit backSignal();
    });
}

void Register::confirmButtonClicked(){
    this->hide();
    username = ui->unameInput->text().toStdString();
    password = ui->pwdInput->text().toStdString();


}

Register::~Register()
{
    delete ui;
}
