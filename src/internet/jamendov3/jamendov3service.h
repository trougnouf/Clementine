/* This file is part of Clementine.
   Copyright 2010-2012, David Sansome <me@davidsansome.com>
   Copyright 2010, 2014, John Maguire <john.maguire@gmail.com>
   Copyright 2011, Tyler Rhodes <tyler.s.rhodes@gmail.com>
   Copyright 2011, Andrea Decorte <adecorte@gmail.com>
   Copyright 2014, Krzysztof Sobiecki <sobkas@gmail.com>

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

#ifndef INTERNET_JAMENDOV3_JAMENDOV3SERVICE_H_
#define INTERNET_JAMENDOV3_JAMENDOV3SERVICE_H_

#include "internet/core/internetservice.h"

class Jamendov3Service : public InternetService {
  Q_OBJECT
 public:
  Jamendov3Service(Application* app, InternetModel* parent);
  ~Jamendov3Service();
  QStandardItem* CreateRootItem();
  void LazyPopulate(QStandardItem* item);
  void ShowContextMenu(const QPoint& global_pos);
  QWidget* HeaderWidget() const;
  static const char* kServiceName;
  static const char* kSettingsGroup;
  static const char* kApiClientId;
  static const char* kDownloadAlbumUrl;
  static const char* kSearchUrl;
  static const char* kAlbumInfoUrl;


}

#endif  // INTERNET_JAMENDOV3_JAMENDOV3SERVICE_H_
