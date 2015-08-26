#include <QtQml>
#include <QtQml/QQmlContext>
#include <QtQuick/qquickview.h>
#include "backend.h"
#include "Spell.h"
#include "SpellBookModel.h"

#include <iostream>

namespace dsb = dnd_spell_book;

void BackendPlugin::registerTypes(const char *uri)
{
  Q_ASSERT(uri == QLatin1String("DND5eSpellBook"));

  qmlRegisterType<dsb::Spell>(uri, 1, 0, "Spell");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
  dsb::SpellBookModel spell_book_model;

  QList<QObject*> spell_book;
  auto spells = spell_book_model.GetSpells();
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

  QQmlContext* ctxt = engine->rootContext();
  ctxt->setContextProperty("spellBookModel", QVariant::fromValue(spell_book));

  QQmlExtensionPlugin::initializeEngine(engine, uri);
}

