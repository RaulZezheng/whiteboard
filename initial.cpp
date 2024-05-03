#include "initial.h"
#include "ui_initial.h"

Initial::Initial(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Initial)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowTitle("initial interface");

    //connect signals & slots
    //create button connection
    connect(ui->registerButton,&QPushButton::clicked,this,&Initial::registerButtonClicked);
    connect(ui->anojoinButton,&QPushButton::clicked,this,&Initial::anojoinButtonClicked);
    connect(ui->anocreateButton,&QPushButton::clicked,this,&Initial::anocreateButtonClicked);
    connect(ui->loginButton,&QPushButton::clicked,this,&Initial::loginButtonClicked);


}

void Initial::registerButtonClicked(){
    this->hide();

    registerWidget = new Register(0);

    //back to main widget
    connect(registerWidget,&Register::backSignal,[=](){
       this->show();
       registerWidget->close();
    });

    registerWidget->show();
}

void Initial::anocreateButtonClicked(){
    this->hide();

    createSessionWidget = new CreateSession(0);

    //back to main widget
    connect(createSessionWidget,&CreateSession::backSignal,[=](){
       this->show();
       createSessionWidget->close();
    });

    createSessionWidget->show();
}

void Initial::anojoinButtonClicked(){
    this->hide();

    joinSessionWidget = new JoinSession(0);

    //back to main widget
    connect(joinSessionWidget,&JoinSession::backSignal,[=](){
       this->show();
       joinSessionWidget->close();
    });

    joinSessionWidget->show();
}

void Initial::loginButtonClicked(){
    this->hide();

    loginWidget = new Login(0);

    //back to main widget
    connect(loginWidget,&Login::backSignal,[=](){
       this->show();
       loginWidget->close();
    });

    loginWidget->show();
}

Initial::~Initial()
{
    delete ui;
}


