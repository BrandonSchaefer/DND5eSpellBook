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

#include "SpellBookModel.h"
#include "JSonSpellParser.h"

#include "config.h"

#include <algorithm>
#include <fstream>
#include <iostream>

namespace dnd_spell_book
{

namespace
{
  std::string const JSON_PATH = JSONDIR"/spells.json";
  std::string const ZERO_LEVEL = "0th-Level";
  std::string const CANTRIP    = "Cantrip";

  std::vector<std::string> const CLASSES = {"Bard", "Cleric", "Druid", "Paladin", "Sorcerer", "Warlock", "Wizard"};
}

std::string ReadInFile(std::string const& path)
{
  std::string str;
  std::ifstream is(path.c_str(), std::ifstream::binary);

  if (is)
  {
    is.seekg(0, is.end);
    int length = (int)is.tellg();
    is.seekg(0, is.beg);

    char* buff = new char[length + 1];

    is.read(buff, length);
    is.close();

    buff[length] = '\0';

    str = std::string(buff);
    delete buff;
  }
  else
  {
    std::cerr << "Failed to load file: " << path.c_str() << std::endl;
  }

  return str;
}

void print_spell_breed(SpellBreed const& b)
{
  std::cout << std::endl;
  std::cout << "Name: \t\t"        << b.name          << std::endl <<
               "Desc: \t\t"        << b.desc          << std::endl <<
               "Page: \t\t"        << b.page          << std::endl <<
               "Range: \t\t"       << b.range         << std::endl <<
               "Components: \t"    << b.components    << std::endl <<
               "Ritual: \t"        << b.ritual        << std::endl <<
               "Duration: \t"      << b.duration      << std::endl <<
               "concentration: \t" << b.concentration << std::endl <<
               "Casting Time: \t"  << b.casting_time  << std::endl <<
               "Level: \t\t"       << b.level         << std::endl <<
               "School: \t"        << b.school        << std::endl <<
               "Class: \t\t"       << b.classes       << std::endl;
}

std::string ReplaceIfCantrip(std::string const& level)
{
  if (level == CANTRIP)
    return ZERO_LEVEL;

  return level;
}

bool SpellLevelDescending(SpellBreed const& a, SpellBreed const& b)
{
  std::string level_a = ReplaceIfCantrip(a.level);
  std::string level_b = ReplaceIfCantrip(b.level);

  return level_a.compare(level_b) > 0;
}

bool SpellLevelAscending(SpellBreed const& a, SpellBreed const& b)
{
  std::string level_a = ReplaceIfCantrip(a.level);
  std::string level_b = ReplaceIfCantrip(b.level);

  return level_a.compare(level_b) < 0;
}

bool SpellNameDescending(SpellBreed const& a, SpellBreed const& b)
{
  return a.name.compare(b.name) > 0;
}

bool SpellNameAscending(SpellBreed const& a, SpellBreed const& b)
{
  return a.name.compare(b.name) < 0;
}

bool SpellSchoolDescending(SpellBreed const& a, SpellBreed const& b)
{
  return a.school.compare(b.school) > 0;
}

bool SpellSchoolAscending(SpellBreed const& a, SpellBreed const& b)
{
  return a.school.compare(b.school) < 0;
}

SpellBookModel::SpellBookModel()
  : class_filter_(CLASSES.size())
{
  spells_ = ParseSpellBook(ReadInFile(JSON_PATH));

  std::sort(spells_.begin(), spells_.end(), SpellSchoolDescending);

  class_filter_.SetFilter(CLERIC);
  class_filter_.SetFilter(WIZARD);

  for (auto const& s : spells_)
  {
    std::cout << s.school << std::endl;
  }
  GetSpells();
    //print_spell_breed(s);
}

bool SpellBookModel::PassesFilters(SpellBreed const& b) const
{
  for (unsigned int i = 0; i < CLASSES.size(); i++)
  {
    if (class_filter_.HasFilter(i) &&
        b.classes.find(CLASSES[i]) != std::string::npos)
    {
      return true;
    }
  }

  return false;
}

std::vector<SpellBreed> SpellBookModel::GetSpells() const
{
  std::vector<SpellBreed> filtered_spells;

  for (auto const& s : spells_)
  {
    if (PassesFilters(s))
      filtered_spells.push_back(s);
  }

  std::cout << "Size: " << filtered_spells.size() << std::endl;

  return filtered_spells;
}

void SpellBookModel::AddClassFilter(ClassFilter const& class_index)
{
  class_filter_.SetFilter(class_index);
}

void SpellBookModel::RemoveClassFilter(ClassFilter const& class_index)
{
  class_filter_.RemoveFilter(class_index);
}

} // namespace dnd_spell_book
