// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2015 Brandon Schaefer
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

#include <json/json.h>

#include "config.h"

#include <iostream>
#include <fstream>

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

std::string const JSON_PATH = JSONDIR"/spells.json";

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

/*
int main()
{
  Json::Value root;
  Json::Reader reader;

  std::cout << JSON_PATH << std::endl;

  std::string raw_json = ReadInFile(JSON_PATH);

  std::vector<SpellBreed> spell_breeds;
  bool handled = reader.parse(raw_json, root, true);
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

      spell_breeds.push_back({name, desc, page, range, components, ritual, duration, concentration, casting_time, level, school, classes});

      //print_spell_breed(spell_breeds.back());
    }
    std::cout << root.size() << std::endl;
    //auto t = root.get("name", "string").asString();
    //std::cout << t << std::endl;
    //printf(":(\n");

  }

  int count = 0;
  // Bard, Cleric, Druid, Paladin, Sorcerer, Warlock, Wizard
  std::string l_class("Wizard");
  for (auto const& s : spell_breeds)
  {
    if (s.classes.find(l_class) != std::string::npos)
    //if (s.classes == l_class)
    {
      count++;
      print_spell_breed(s);
    }
  }
  std::cout << std::endl;
  std::cout << "Class " << l_class << ", has " << count << " spells" << std::endl;

  return 0;
}
*/
