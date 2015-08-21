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

#include "JSonSpellParser.h"

#include <json/json.h>

namespace dnd_spell_book
{

extern std::vector<SpellBreed> ParseSpellBook(std::string const& spell_book_json)
{
  Json::Value root;
  Json::Reader reader;

  std::vector<SpellBreed> spell_breeds;

  bool handled = reader.parse(spell_book_json, root, true);
  if (handled)
  {
    for (Json::Value const& spell : root)
    {
      std::string name  = spell.get("name", "string").asString();
      std::string desc  = spell.get("desc", "string").asString();
      std::string page  = spell.get("page", "string").asString();
      std::string range = spell.get("range", "string").asString();
      std::string components = spell.get("components", "string").asString();
      std::string ritual     = spell.get("ritual", "string").asString();
      std::string duration   = spell.get("duration", "string").asString();
      std::string concentration = spell.get("concentration", "string").asString();
      std::string casting_time  = spell.get("casting_time", "string").asString();
      std::string level   = spell.get("level", "string").asString();
      std::string school  = spell.get("school", "string").asString();
      std::string classes = spell.get("class", "string").asString();

      spell_breeds.push_back({name,
                              desc,
                              page,
                              range,
                              components,
                              ritual,
                              duration,
                              concentration,
                              casting_time,
                              level,
                              school,
                              classes});
    }
  }

  return spell_breeds;
}

} // namespace dnd_spell_book
