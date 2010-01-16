#pragma once

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

#include "messaging/Message.h"
#include "messaging/MessageHandler.h"

#include <set>
#include <vector>

namespace mada
{
	class MessagePort : public RefCounted
	{
		__mada_declare_class(MessagePort);
	public:
		MessagePort();
		~MessagePort();

		virtual void setupAcceptedMessages();

		void attachHandler(const Ptr<MessageHandler>& handler);
		void removeHandler(const Ptr<MessageHandler>& handler);

		void removeAllHandlers();

		virtual void send(const Ptr<Message>& msg);

		virtual void handleMessage(const Ptr<Message>& msg);

		bool acceptsMessage(const MessageId& msgId) const;

	protected:
		void registerMessage(const MessageId& msgId);

	private:
		typedef std::vector<Ptr<MessageHandler> > HandlerVector;
		HandlerVector m_handlers;
		std::set<MessageId> m_acceptedMessageIds;
	};
}
