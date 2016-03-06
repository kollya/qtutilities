#include "./clearplaintextedit.h"

#include <QHBoxLayout>
#include <QScrollBar>

#include <functional>

using namespace std;

namespace Widgets {

/*!
 * \class Widgets::ClearPlainTextEdit
 * \brief A QPlainTextEdit with an embedded button for clearing its contents.
 */

/*!
 * \brief Constructs a clear plain text edit.
 */
ClearPlainTextEdit::ClearPlainTextEdit(QWidget *parent) :
    QPlainTextEdit(parent),
    ButtonOverlay(viewport())
{
    // set alignment to show buttons in the bottom right corner
    ButtonOverlay::buttonLayout()->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    ButtonOverlay::setClearButtonEnabled(true);
    connect(document(), &QTextDocument::contentsChanged, this, &ClearPlainTextEdit::handleTextChanged);
    // ensure button layout is realigned when scrolling
    connect(this->verticalScrollBar(), &QScrollBar::valueChanged, this, &ClearPlainTextEdit::handleScroll);
    connect(this->verticalScrollBar(), &QScrollBar::rangeChanged, this, &ClearPlainTextEdit::handleScroll);
}

/*!
 * \brief Destroys the clear plain text edit.
 */
ClearPlainTextEdit::~ClearPlainTextEdit()
{}

/*!
 * \brief Updates the visibility of the clear button.
 */
void ClearPlainTextEdit::handleTextChanged()
{
    updateClearButtonVisibility(!document()->isEmpty());
}

void ClearPlainTextEdit::handleClearButtonClicked()
{
    // do no call clear() here to prevent clearing of undo history
    QTextCursor cursor(document());
    cursor.select(QTextCursor::Document);
    cursor.removeSelectedText();
}

void ClearPlainTextEdit::handleScroll()
{
    buttonLayout()->update();
}

bool ClearPlainTextEdit::isCleared() const
{
    return document()->isEmpty();
}

} // namespace Widgets
