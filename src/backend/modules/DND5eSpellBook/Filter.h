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

#ifndef FILTER_H
#define FILTER_H

#include <vector>

namespace dnd_spell_book
{

class Filter
{
public:
  Filter(unsigned int size);

  void SetFilter(unsigned int filter);
  void RemoveFilter(unsigned int filter);
  bool HasFilter(unsigned int filter) const;

private:
  std::vector<bool> filter_;

};

} // namespace dnd_spell_book

#endif // FILTER_H
