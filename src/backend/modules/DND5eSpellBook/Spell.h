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

#ifndef SPELL_H
#define SPELL_H

#include <QObject>

namespace dnd_spell_book
{

class Spell : public QObject
{
  Q_OBJECT
  Q_PROPERTY( QString name          READ name          WRITE setName          NOTIFY nameChanged )
  Q_PROPERTY( QString desc          READ desc          WRITE setDesc          NOTIFY descChanged )
  Q_PROPERTY( QString page          READ page          WRITE setPage          NOTIFY pageChanged )
  Q_PROPERTY( QString range         READ range         WRITE setRange         NOTIFY rangeChanged )
  Q_PROPERTY( QString components    READ components    WRITE setComponents    NOTIFY componentsChanged )
  Q_PROPERTY( QString ritual        READ ritual        WRITE setRitual        NOTIFY ritualChanged )
  Q_PROPERTY( QString duration      READ duration      WRITE setDuration      NOTIFY durationChanged )
  Q_PROPERTY( QString concentration READ concentration WRITE setConcentration NOTIFY concentrationChanged )
  Q_PROPERTY( QString casting_time  READ castingTime   WRITE setCastingTime   NOTIFY castingTimeChanged )
  Q_PROPERTY( QString level         READ level         WRITE setLevel         NOTIFY levelChanged )
  Q_PROPERTY( QString school        READ school        WRITE setSchool        NOTIFY schoolChanged )
  Q_PROPERTY( QString classes       READ classes       WRITE setClasses       NOTIFY classesChanged )

public:
  Spell(QObject* parent = 0);
  Spell(QString const& name, QString const& desc, QString const& page,
        QString const& range, QString const& components, QString const& ritual,
        QString const& duration, QString const& concentration, QString const& casting_time,
        QString const& level, QString const& school, QString const& classes,
        QObject* parent = 0);
       
  ~Spell();

Q_SIGNALS:
  void nameChanged();
  void descChanged();
  void pageChanged();
  void rangeChanged();
  void componentsChanged();
  void ritualChanged();
  void durationChanged();
  void concentrationChanged();
  void castingTimeChanged();
  void levelChanged();
  void schoolChanged();
  void classesChanged();

protected:
  QString name()          const;
  QString desc()          const;
  QString page()          const;
  QString range()         const;
  QString components()    const;
  QString ritual()        const;
  QString duration()      const;
  QString concentration() const;
  QString castingTime()   const;
  QString level()         const;
  QString school()        const;
  QString classes()       const;

  void setName         (QString const& name);
  void setDesc         (QString const& desc);
  void setPage         (QString const& page);
  void setRange        (QString const& range);
  void setComponents   (QString const& components);
  void setRitual       (QString const& ritual);
  void setDuration     (QString const& duration);
  void setConcentration(QString const& concentration);
  void setCastingTime  (QString const& casting_time);
  void setLevel        (QString const& level);
  void setSchool       (QString const& school);
  void setClasses      (QString const& classes);

private:
  QString name_;
  QString desc_;
  QString page_;
  QString range_;
  QString components_;
  QString ritual_;
  QString duration_;
  QString concentration_;
  QString casting_time_;
  QString level_;
  QString school_;
  QString classes_;
};

} // namespace dnd_spell_book

#endif // SPELL_H
