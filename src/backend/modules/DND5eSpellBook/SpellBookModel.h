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

#ifndef SPELL_BOOK_MODEL_H
#define SPELL_BOOK_MODEL_H

#include <functional>
#include <string>
#include <vector>

#include "Filter.h"

namespace dnd_spell_book
{

typedef struct 
{
  std::string name;
  std::string desc;
  std::string page;
  std::string range;
  std::string components;
  std::string ritual;
  std::string duration;
  std::string concentration;
  std::string casting_time;
  std::string level;
  std::string school;
  std::string classes;
} SpellBreed;

enum ClassFilter
{
  BARD,
  CLERIC,
  DRUID,
  PALADIN,
  SORCERER,
  WARLOCK,
  WIZARD
};

class SpellBookModel
{
public:
  SpellBookModel();

  std::vector<SpellBreed> GetSpells() const;

  void AddClassFilter(ClassFilter const& filter);
  void RemoveClassFilter(ClassFilter const& filter);

  void SortBySpellLevel(bool ascending);
  void SortBySpellName(bool ascending);
  void SortBySpellSchool(bool ascending);

private:
  std::vector<std::string> GetSpellClassFilters() const;
  bool PassesFilters(SpellBreed const& b) const;

  void SortSpells(std::function<bool(SpellBreed const&, SpellBreed const&)> const& comp);

  std::vector<SpellBreed> spells_;
  Filter class_filter_;
};

} // namespace dnd_spell_book

#endif // SPELL_BOOK_MODEL_H
