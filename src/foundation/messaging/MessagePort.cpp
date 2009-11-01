/*
	This file is part of Kraft der Mada.
	Copyright (c) 2009 Daniel Wickert

    Kraft der Mada is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Kraft der Mada is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kraft der Mada. If not, see <http://www.gnu.org/licenses/>.
*/
#include "stdmadainc.h"

#include "messaging/MessagePort.h"

namespace mada
{
	__mada_implement_root_class(MessagePort);

	MessagePort::MessagePort() : m_handlers(), m_acceptedMessageIds()
	{
	}

	MessagePort::~MessagePort()
	{
		m_handlers.clear();
		m_acceptedMessageIds.clear();
	}

	void MessagePort::setupAcceptedMessages()
	{
		// None by default
	}

	void MessagePort::attachHandler(const Ptr<MessageHandler>& h)
	{
		m_handlers.push_back(h);
	}

	void MessagePort::removeHandler(const Ptr<MessageHandler>& h)
	{
	}

	void MessagePort::removeAllHandlers()
	{
	}

	void MessagePort::send(const Ptr<Message>& msg)
	{
	}

	bool MessagePort::acceptsMessage(const MessageId& msgId) const
	{
		return false;
	}

	void MessagePort::registerMessage(const MessageId& msgId)
	{
	}

	void MessagePort::handleMessage(const Ptr<Message>& msg)
	{
	}
}
