#if !defined(DOCKWIDGET_H)
#define DOCKWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
class DockWidget : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPushButton*> dock_boat_buttons{3};
    std::vector<QPushButton*> control_buttons{3};
    QButtonGroup* boat_button_group;
public:
    DockWidget(int w, QWidget *parent = nullptr);
    //~dockwidget();
};

enum BoatButtons{
    Battleship = 0, Support, Sonar
};
enum ControlButtons{
    Remove = 0, Rotate, Next
};

#endif // DOCKWIDGET_H
