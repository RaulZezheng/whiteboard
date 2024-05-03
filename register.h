#ifndef REGISTER_H
#define REGISTER_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Register; }
QT_END_NAMESPACE

class Register : public QWidget
{
    Q_OBJECT

public:
    Register(QWidget *parent);
    ~Register();

signals:
    void backSignal();

private slots:
    void confirmButtonClicked();


private:
    Ui::Register *ui;
    std::string username;
    std::string password;
    //click create button to open new portal
//    CreateSession *createSessionWidget;
    //click join button to open new portal
//    JoinSession *joinSessionWidget;
};
#endif // REGISTER_H
