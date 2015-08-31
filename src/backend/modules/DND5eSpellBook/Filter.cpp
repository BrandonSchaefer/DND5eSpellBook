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

#include "Filter.h"

#include <algorithm>

namespace dnd_spell_book
{

Filter::Filter()
{
}

void Filter::SetFilter(std::string const& string_filter)
{
  filter_.push_front(string_filter);
}

bool Filter::HasFilter(std::string const& string_filter) const
{
  return std::find(filter_.begin(), filter_.end(), string_filter) != filter_.end();
}

void Filter::RemoveFilter(std::string const& string_filter)
{
  filter_.remove(string_filter);
}

std::list<std::string> Filter::GetFilters() const
{
  return filter_;
}

} // namespace dnd_spell_book
