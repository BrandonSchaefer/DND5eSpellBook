#include <QtQml>
#include <QtQml/QQmlContext>
#include <QtQuick/qquickview.h>
#include "BackendPlugin.h"
#include "Spell.h"

#include <iostream>
#include <vector>

namespace dsb = dnd_spell_book;

BackendPlugin::BackendPlugin()
  : ascending_(true)
  , search_string_("")
{
}

void BackendPlugin::registerTypes(const char *uri)
{
  Q_ASSERT(uri == QLatin1String("DND5eSpellBook"));

  qmlRegisterType<dsb::Spell>(uri, 1, 0, "Spell");
}

void BackendPlugin::ClassFilter(QString const& klass, bool checked)
{
  if (checked)
    spell_book_model_.AddClassFilter(klass.toStdString());
  else
    spell_book_model_.RemoveClassFilter(klass.toStdString());

  UpdateSpellBookModel();
}

void BackendPlugin::LevelFilter(QString const& level, bool checked)
{
  if (checked)
    spell_book_model_.AddLevelFilter(level.toStdString());
  else
    spell_book_model_.RemoveLevelFilter(level.toStdString());

  UpdateSpellBookModel();
}

void BackendPlugin::EditingFinished(QString const& search)
{
  search_string_ = search.toStdString();
  UpdateSpellBookModel();
}

void BackendPlugin::SortBy(QString const& sort)
{
  // TODO Figure out a better way
  if (sort == "Alphabet")
    spell_book_model_.SortBySpellName(ascending_);
  else if (sort == "Level")
    spell_book_model_.SortBySpellLevel(ascending_);
  else if (sort == "School")
    spell_book_model_.SortBySpellSchool(ascending_);

  UpdateSpellBookModel();
}

auto BackendPlugin::MatchSpellsOnSearchString(std::vector<dsb::SpellBreed> const& spells)
{
  std::vector<dsb::SpellBreed> matched_spells;

  auto lower_func = [] (char& c) { c = tolower(c); };

  std::string lower_search = search_string_;
  for_each(lower_search.begin(), lower_search.end(), lower_func);

  for (auto const& s : spells)
  {
    std::string lower_string = s.name;
    for_each(lower_string.begin(), lower_string.end(), lower_func);

    if (lower_string.find(lower_search) != std::string::npos)
      matched_spells.push_back(s);
  }

  return matched_spells;
}

void BackendPlugin::UpdateSpellBookModel()
{
  QList<QObject*> spell_book;
  auto spells = spell_book_model_.GetSpells();

  if (!search_string_.empty())
    spells = MatchSpellsOnSearchString(spells);

  for (auto const& s : spells)
  {
    spell_book.append(new dsb::Spell(QString::fromStdString(s.name),
                                     QString::fromStdString(s.desc),
                                     QString::fromStdString(s.page),
                                     QString::fromStdString(s.range),
                                     QString::fromStdString(s.components),
                                     QString::fromStdString(s.ritual),
                                     QString::fromStdString(s.duration),
                                     QString::fromStdString(s.concentration),
                                     QString::fromStdString(s.casting_time),
                                     QString::fromStdString(s.level),
                                     QString::fromStdString(s.school),
                                     QString::fromStdString(s.classes)));
  }

  // FIXME Handle the fact that the spells might be empty
  //if (spells.empty())
    //spell_book.append(new dsb::Spell("", "", "", "", "", "", "", "", "", "", "", ""));
    //spell_book.append(new dsb::Spell("N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A"));

  QQmlContext* ctxt = engine_->rootContext();
  ctxt->setContextProperty("spellBookModel", QVariant::fromValue(spell_book));
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
  engine_ = engine;
  QQmlContext* ctxt = engine_->rootContext();
  UpdateSpellBookModel();
  ctxt->setContextProperty(QStringLiteral("backend"), this);

  QQmlExtensionPlugin::initializeEngine(engine, uri);
}

