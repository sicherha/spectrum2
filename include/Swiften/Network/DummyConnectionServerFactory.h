/*
 * Copyright (c) 2011 Jan Kaluza
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#pragma once

#include <boost/asio/io_service.hpp>

#include <Swiften/Network/ConnectionServerFactory.h>
#include <Swiften/Network/DummyConnectionServer.h>

#include "Swiften/SwiftenCompat.h"

namespace Swift {
	class ConnectionServer;

	class DummyConnectionServerFactory : public ConnectionServerFactory {
		public:
			DummyConnectionServerFactory(EventLoop* eventLoop);

			virtual SWIFTEN_SHRPTR_NAMESPACE::shared_ptr<ConnectionServer> createConnectionServer(unsigned short port);

			virtual SWIFTEN_SHRPTR_NAMESPACE::shared_ptr<ConnectionServer> createConnectionServer(const Swift::HostAddress &hostAddress, unsigned short port);

		private:
			EventLoop* eventLoop;
	};
}
