#include "CursorUtil.h"

void setCustomCursor(QWidget* widget)
{
    QString cursorFile = ":/cards/cursor.png";
    QPixmap cursorPixmap(cursorFile);

    if (cursorPixmap.isNull()) {
        qDebug() << "Failed to load custom cursor image:" << cursorFile;
        return;
    }

    QCursor customCursor(cursorPixmap);
    widget->setCursor(customCursor);
}
