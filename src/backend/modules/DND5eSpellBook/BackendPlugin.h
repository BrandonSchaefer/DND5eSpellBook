//-*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/* * Copyright (C) 2015 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

#ifndef BACKEND_PLUGIN_H
#define BACKEND_PLUGIN_H

#include <QtQml/QQmlEngine>
#include <QtQml/QQmlExtensionPlugin>

#include "Spell.h"
#include "SpellBookModel.h"

namespace dsb = dnd_spell_book;

class BackendPlugin : public QQmlExtensionPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
  BackendPlugin();

  void registerTypes(const char *uri);
  void initializeEngine(QQmlEngine *engine, const char *uri);

public slots:
  void ClassFilter (QString const& klass, bool checked);
  void LevelFilter (QString const& level, bool checked);
  void SchoolFilter(QString const& school, bool checked);

  void SortBy(QString const& sort);
  void Ascending(QString const& sort, QString const& ascending);

  void EditingFinished(QString const& search);

  void FilterByLevel();

private:
  void SortSpellBookModel(QString const& sort);
  void UpdateSpellBookModel();
  auto MatchSpellsOnSearchString(std::vector<dsb::SpellBreed> const& spells);

  bool ascending_;
  std::string search_string_;
  dsb::SpellBookModel spell_book_model_;
  QQmlEngine* engine_;
    
};
#endif // BACKEND_PLUGIN_H


