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

namespace mada
{
	struct MessageId
	{
		MessageId() {}
		bool operator==(const MessageId& other) const
		{
			return this == &other;
		}

		bool operator<(const MessageId& other) const
		{
			return this < &other;
		}
	};

#	define __mada_declare_message_id \
	private: \
	public: \
		static MessageId m_id; \
		virtual const MessageId& getId() const; \
	private:

#	define __mada_implement_message_id(Type) \
	MessageId Type::m_id; \
	const MessageId& Type::getId() const { return m_id; }

	class Message : public RefCounted
	{
		__mada_declare_class(Message);
		__mada_declare_message_id;
	public:
		Message();
		~Message();

		bool hasId(const MessageId& id) const;
		/// Debug-String der Message. z.B. zum Loggen.
		virtual String toString() const;

		bool isHandled() const;
		void setHandled(bool handled);

	private:
		bool m_isHandled;
	};
}
