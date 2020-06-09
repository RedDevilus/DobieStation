#include <QApplication>
#include <memory>
#include "emuwindow.hpp"

using namespace std;

int main(int argc, char** argv)
{
    QApplication::setOrganizationName("PSI");
    QApplication::setApplicationName("DobieStation");
    QApplication::setOrganizationDomain("https://github.com/PSI-Rockin/DobieStation");
	QApplication::setStyle(QStyleFactory::create("Modern Dark Theme"));
	QPalette p;
	p = qApp->palette();
	p.setColor(QPalette::Window, QColor(69,69,69));
	p.setColor(QPalette::Button, QColor(69,69,69));
	p.setColor(QPalette::Highlight, QColor(50,169,191));
	p.setColor(QPalette::ButtonText, QColor(169,209,209));
	qApp->setPalette(p);

    QApplication a(argc, argv);
    auto window = unique_ptr<EmuWindow>(new EmuWindow());

    if (window->init(argc, argv))
        return 1;

    a.exec();
    return 0;
}
