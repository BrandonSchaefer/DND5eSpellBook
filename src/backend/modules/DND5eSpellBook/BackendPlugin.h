#ifndef BACKEND_PLUGIN_H
#define BACKEND_PLUGIN_H

#include <QtQml/QQmlEngine>
#include <QtQml/QQmlExtensionPlugin>

#include "Spell.h"
#include "SpellBookModel.h"

namespace dsb = dnd_spell_book;

class BackendPlugin : public QQmlExtensionPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
  BackendPlugin();

  void registerTypes(const char *uri);
  void initializeEngine(QQmlEngine *engine, const char *uri);

public slots:
  void ClassFilter (QString const& klass, bool checked);
  void LevelFilter (QString const& level, bool checked);
  void SchoolFilter(QString const& school, bool checked);

  void SortBy(QString const& sort);
  void Ascending(QString const& sort, QString const& ascending);

  void EditingFinished(QString const& search);

  void FilterByLevel();

private:
  void SortSpellBookModel(QString const& sort);
  void UpdateSpellBookModel();
  auto MatchSpellsOnSearchString(std::vector<dsb::SpellBreed> const& spells);

  bool ascending_;
  std::string search_string_;
  dsb::SpellBookModel spell_book_model_;
  QQmlEngine* engine_;
    
};
#endif // BACKEND_PLUGIN_H


