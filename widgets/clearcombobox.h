#ifndef WIDGETS_CLEARCOMBOBOX_H
#define WIDGETS_CLEARCOMBOBOX_H

#include "./buttonoverlay.h"

#include <QComboBox>

namespace QtUtilities {

class QT_UTILITIES_EXPORT ClearComboBox : public QComboBox, public ButtonOverlay {
    Q_OBJECT
public:
    explicit ClearComboBox(QWidget *parent = nullptr);
    ~ClearComboBox() override;
    bool isCleared() const override;

private Q_SLOTS:
    void handleTextChanged(const QString &text);
    void handleClearButtonClicked() override;
};

} // namespace QtUtilities

#endif // WIDGETS_CLEARCOMBOBOX_H
