#if !defined(SETUPDOCKWIDGET_H)
#define SETUPDOCKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <vector>
#include <QString>

const QString kSetupString = "Setup phase";

class SetupDockWidget : public QWidget
{
    Q_OBJECT
private:
    QButtonGroup* boat_button_group;
    std::vector<int> boat_num_{3};
    QLabel* comm_label_;
public:
    SetupDockWidget(int w, QWidget *parent = nullptr);
    void setLabelValue(int value, int index){dock_labels[index]->setText(QString('0' + value));}
    int getLabelValue(int index){return dock_labels[index]->text().toStdString()[0] - '0';}
    void setCommLabel(QString string){comm_label_->setText(string);}

    std::vector<QPushButton*> dock_boat_buttons{3};
    std::vector<QPushButton*> control_buttons{3};
    std::vector<QLabel*> dock_labels{3};
    
    //~setupdockwidget();
};

enum BoatButtons{
    First = 0, Middle, Last
};

#endif // SETUPDOCKWIDGET_H
