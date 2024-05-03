#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include "mainwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent);
    ~Login();

signals:
    void backSignal();

private slots:
    void loginButtonClicked();


private:
    Ui::Login *ui;
    std::string username;
    std::string password;
    MainWidget *mainWidget;
    //click create button to open new portal
//    CreateSession *createSessionWidget;
    //click join button to open new portal
//    JoinSession *joinSessionWidget;
};
#endif // LOGIN_H
