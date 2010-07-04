/* This file is part of Clementine.

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEVICEVIEW_H
#define DEVICEVIEW_H

#include "library/libraryview.h"
#include "widgets/autoexpandingtreeview.h"

class QAction;
class QMenu;
class QSortFilterProxyModel;

class DeviceManager;
class DeviceProperties;
class MergedProxyModel;

class DeviceItemDelegate : public LibraryItemDelegate {
public:
  DeviceItemDelegate(QObject* parent);

  static const int kIconPadding;

  void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};


class DeviceView : public AutoExpandingTreeView {
  Q_OBJECT

public:
  DeviceView(QWidget* parent = 0);
  ~DeviceView();

  void SetDeviceManager(DeviceManager* manager);

protected:
  void contextMenuEvent(QContextMenuEvent *);
  void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
  void Connect();
  void Disconnect();
  void Forget();
  void Properties();

  void DeviceDisconnected(int row);

private:
  QModelIndex MapToDevice(const QModelIndex& merged_model_index) const;

private:
  DeviceManager* manager_;
  MergedProxyModel* merged_model_;
  QSortFilterProxyModel* sort_model_;

  boost::scoped_ptr<DeviceProperties> properties_dialog_;

  QMenu* menu_;
  QAction* connect_action_;
  QAction* disconnect_action_;
  QAction* forget_action_;
  QAction* properties_action_;
  QModelIndex menu_index_;
};

#endif // DEVICEVIEW_H
