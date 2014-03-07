#include "yarrgui.h"
#include "ui_yarrgui.h"

YarrGui::YarrGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::YarrGui)
{
    ui->setupUi(this);

    ui->device_listWidget->setSelectionMode(QListWidget::SingleSelection);

    devicePath.setPath("/dev/");
    QStringList filter;
    QStringList deviceList;
    filter << "spec*";
    devicePath.setFilter(QDir::System);
    deviceList = devicePath.entryList(filter);
    ui->device_listWidget->addItems(deviceList);
}

YarrGui::~YarrGui()
{
    delete ui;
}

void YarrGui::on_device_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->selDevice_label->setText(devicePath.absolutePath() + "/" + current->text());
}
