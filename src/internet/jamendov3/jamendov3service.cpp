/* This file is part of Clementine.
   Copyright 2010-2013, David Sansome <me@davidsansome.com>
   Copyright 2010, 2014, John Maguire <john.maguire@gmail.com>
   Copyright 2011, Tyler Rhodes <tyler.s.rhodes@gmail.com>
   Copyright 2011, Paweł Bara <keirangtp@gmail.com>
   Copyright 2011, Andrea Decorte <adecorte@gmail.com>
   Copyright 2014, Chocobozzz <florian.bigard@gmail.com>
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

#include "jamendov3service.h"

const char* Jamendov3Service::kServiceName = "Jamendov3";
const char* Jamendov3Service::kApiClientId = "f4905164";
const char* Jamendov3Service::kTrackUrl =
    "https://api.jamendo.com/v3.0/tracks/file/?client_id=%1&audioformat=%2"
    "&action=%3&id=%4"; // format: mp31,mp32,ogg,flac. action: stream, download
const char* Jamendov3Service::kDownloadAlbumUrl =
    "https://api.jamendo.com/v3.0/albums/file/?client_id=%1&id=%2";
    // probably useless because albuminfo returns this url
const char* Jamendov3Service::kSearchUrl =
    "https://api.jamendo.com/v3.0/autocomplete/?client_id=%1&limit=500"
    "&prefix=%2&matchcount=1";
const char* Jamendov3Service::kAlbumInfoUrl =
    "https://api.jamendo.com/v3.0/albums/musicinfo/?client_id=%1&id=%2";
    // We can also use this to search for albums by name / artist / tag.
    // Provides album cover(s)
Jamendov3Service::Jamendov3Service(Application* app, InternetModel* parent)
    : InternetService(kServiceName, app, parent, parent),
      network_(new NetworkAccessManager(this)),
      context_menu_(nullptr),   // eg right click download album
      library_backend_(nullptr),
      library_filter_(nullptr), // eg Internet > search jamendo
      library_model_(nullptr),
      search_provider_(nullptr) {
  library_backend_ = new LibraryBackend;
  library_backend_->moveToThread(app_->database()->thread());
  library_backend_->Init(app_->database(), kSongsTable, QString::null,
                         QString::null, kFtsTable);

}
