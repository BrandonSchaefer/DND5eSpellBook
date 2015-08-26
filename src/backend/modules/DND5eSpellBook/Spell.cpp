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

#include "Spell.h"

namespace dnd_spell_book
{

Spell::Spell(QObject* parent)
  : QObject(parent)
  , name_("")
  , desc_("")
  , page_("")
  , range_("")
  , components_("")
  , ritual_("")
  , duration_("")
  , concentration_("")
  , casting_time_("")
  , level_("")
  , school_("")
  , classes_("")
{
}

Spell::Spell(QString const& name, QString const& desc, QString const& page,
             QString const& range, QString const& components, QString const& ritual,
             QString const& duration, QString const& concentration, QString const& casting_time,
             QString const& level, QString const& school, QString const& classes,
             QObject* parent)
  : QObject(parent)
  , name_(name)
  , desc_(desc)
  , page_(page)
  , range_(range)
  , components_(components)
  , ritual_(ritual)
  , duration_(duration)
  , concentration_(concentration)
  , casting_time_(casting_time)
  , level_(level)
  , school_(school)
  , classes_(classes)
{
}

Spell::~Spell()
{
}

QString Spell::name() const
{
  return name_;
}

QString Spell::desc() const
{
  return desc_;
}

QString Spell::page() const
{
  return page_;
}

QString Spell::range() const
{
  return range_;
}

QString Spell::components() const
{
  return components_;
}

QString Spell::ritual() const
{
  return ritual_;
}

QString Spell::duration() const
{
  return duration_;
}

QString Spell::concentration() const
{
  return concentration_;
}

QString Spell::castingTime() const
{
  return casting_time_;
}

QString Spell::level() const
{
  return level_;
}

QString Spell::school() const
{
  return school_;
}

QString Spell::classes() const
{
  return classes_;
}

void Spell::setName(QString const& name)
{
  name_ = name;
}

void Spell::setDesc(QString const& desc)
{
  desc_ = desc;
}

void Spell::setPage(QString const& page)
{
  page_ = page;
}

void Spell::setRange(QString const& range)
{
  range_ = range;
}

void Spell::setComponents(QString const& components)
{
  components_ = components;
}

void Spell::setRitual(QString const& ritual)
{
  ritual_ = ritual;
}

void Spell::setDuration(QString const& duration)
{
  duration_ = duration;
}

void Spell::setConcentration(QString const& concentration)
{
  concentration_ = concentration;
}

void Spell::setCastingTime(QString const& casting_time)
{
  casting_time_ = casting_time;
}

void Spell::setLevel(QString const& level)
{
  level_ = level;
}

void Spell::setSchool(QString const& school)
{
  school_ = school;
}

void Spell::setClasses(QString const& classes)
{
  classes_ = classes;
}

} // namespace dnd_spell_book
