#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QMainWindow>

class MyWidget : public QMainWindow {
private:
    QLabel *label;
    uint64_t counter = 0;
public:
    MyWidget(QWidget *parent = nullptr) : QMainWindow(parent) {
        this->resize(800, 600);
        label = new QLabel("Hello world.", this);
        label->setGeometry(150, 50, 150, 30);
        QPushButton *button = new QPushButton("Push me!", this);
        button->setGeometry(150, 120, 100, 30);
        QObject::connect(button, &QPushButton::clicked, this, [=]() { this->buttonClicked(); });
    }

    void buttonClicked() {
        label->setText(QString("Hello world * %1").arg(++counter));
    }
};

int main(int argc, char **argv) {
    QApplication app(argc, argv);

//    QTextEdit txt("Enter foobar here");
//    txt.resize(150, 30);
//    txt.show();
//
//    QPushButton hello(QPushButton::tr("Hit me!"));
//    hello.resize(100, 30);
//    hello.show();
    MyWidget widget{nullptr};
    widget.show();

    return app.exec();
}