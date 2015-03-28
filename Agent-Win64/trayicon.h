#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
class QSystemTrayIcon;

class TrayIcon : QObject
{
    Q_OBJECT

public:
    TrayIcon();
    ~TrayIcon();

private:
    QSystemTrayIcon *m_trayIcon;

private slots:
    void slotSettings();
};

#endif // TRAYICON_H
