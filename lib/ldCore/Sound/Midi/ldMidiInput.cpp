#include "ldMidiInput.h"

#include <QtCore/QtDebug>

#include "ldMidiInfo.h"
#include "ldCore/Sound/Midi/ldMidiManager.h"

ldMidiInput::ldMidiInput(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType<ldMidiNote>();
    qRegisterMetaType<ldMidiCCMessage>();

    connect(this, &ldMidiInput::noteReceived, ldMidiManager::getSharedManager(), &ldMidiManager::addEvent);
}


ldMidiInput::~ldMidiInput()
{
}

bool ldMidiInput::isActive() const
{
    return m_isActive;
}

void ldMidiInput::start(const ldMidiInfo &info)
{
    if(m_isActive) {
        return;
    }

    bool r = openMidi(info);
    if (r) {
        m_isActive = true;
    } else {
        qWarning() << "Can't open midi" << info.id() << info.name();
    }
}
