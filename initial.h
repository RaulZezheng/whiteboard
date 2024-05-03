#ifndef INITIAL_H
#define INITIAL_H
#include <QWidget>
#include "register.h"
#include "joinsession.h"
#include "createsession.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Initial;
}
QT_END_NAMESPACE

class Initial : public QWidget
{
    Q_OBJECT

public:
    Initial(QWidget *parent);
    ~Initial();


private:
    Ui::Initial *ui;
    Register *registerWidget;
    CreateSession *createSessionWidget;
    JoinSession *joinSessionWidget;
    Login *loginWidget;


private slots:
    void anocreateButtonClicked();
    void anojoinButtonClicked();
    void registerButtonClicked();
    void loginButtonClicked();

//    void displayError(QAbstractSocket::SocketError socketError);

};

#endif // INITIAL_H
