#if !defined(GAMEDOCKWIDGET_H)
#define GAMEDOCKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QPushButton>

const QString kGameString = "Game Phase. Player: ";
class GameDockWidget : public QWidget{
    Q_OBJECT
    public:
        GameDockWidget(int w , QWidget *parent = nullptr);
        void setLabelValue(int value, int index){labels_[index]->setNum(value);}
        int getLabelValue(int index){return labels_[index]->text().toStdString()[0] - '0';}
        void setCommLabel( QString string = kGameString ){comm_label_->setText(string);}
        std::vector<QLabel*> labels_{3};
        std::vector<QPushButton*> buttons_{2};
    private:
        QLabel* comm_label_;
};


#endif // GAMEDOCKWIDGET_H
