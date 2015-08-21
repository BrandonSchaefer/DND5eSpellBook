#include "mytype.h"

#include "JSonSpellParser.h"
#include "SpellBookModel.h"

namespace dsb = dnd_spell_book;

MyType::MyType(QObject *parent) :
    QObject(parent),
    m_message("")
{
  dsb::SpellBookModel sb;
}

MyType::~MyType() {

}

