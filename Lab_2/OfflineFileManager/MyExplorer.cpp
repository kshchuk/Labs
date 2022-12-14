#include "MyExplorer.h"
#include <qscreen.h>
#include <QScroller>


MyExplorer::MyExplorer(QWidget* parent, QFileInfoModel* model)
	: QTreeView(parent)
{
	treeViewInit(this, model);
}

MyExplorer::~MyExplorer()
{}

void MyExplorer::sendPathOfTheSelectedFile()
{
    QString path = this->currentIndex().siblingAtColumn((int)ColunmsOrder::FULL_PATH).data().toString();
    if (path.isEmpty())
        path = this->currentIndex().siblingAtColumn((int)ColunmsOrder::NAME).data().toString();

	emit pathSent(path);
}

void MyExplorer::treeViewInit(QTreeView* tree, QFileInfoModel* model1)
{
    tree->setModel(model1);

    for (size_t i = 4; i < tree->model()->columnCount(); i++)
        tree->hideColumn(i); // only 4 columns need to be displayed

    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setSortingEnabled(true);
    const QSize availableSize = tree->screen()->availableGeometry().size();
    tree->setColumnWidth(0, 400);
    QScroller::grabGesture(tree, QScroller::TouchGesture);
    tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
