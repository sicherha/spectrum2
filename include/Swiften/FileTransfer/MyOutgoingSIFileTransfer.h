/*
 * Copyright (c) 2010 Remko Tronçon
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#pragma once

#include <boost/shared_ptr.hpp>

#include "Swiften/SwiftenCompat.h"

#include <Swiften/FileTransfer/OutgoingFileTransfer.h>
#include <Swiften/FileTransfer/ReadBytestream.h>
#include <Swiften/FileTransfer/FileTransferError.h>
#include <Swiften/FileTransfer/SOCKS5BytestreamServer.h>
#include <Swiften/JID/JID.h>
#include <Swiften/Elements/StreamInitiation.h>
#include <Swiften/Elements/Bytestreams.h>
#include <Swiften/Elements/ErrorPayload.h>
#include <Swiften/FileTransfer/IBBSendSession.h>
#include <Swiften/Version.h>
#define HAVE_SWIFTEN_3  (SWIFTEN_VERSION >= 0x030000)

namespace Swift {
	class IQRouter;
	class SOCKS5BytestreamServer;
	class SOCKS5BytestreamRegistry;

	class MyOutgoingSIFileTransfer : public OutgoingFileTransfer {
		public:
			MyOutgoingSIFileTransfer(const std::string& id, const JID& from, const JID& to, const std::string& name, int size, const std::string& description, SWIFTEN_SHRPTR_NAMESPACE::shared_ptr<ReadBytestream> bytestream, IQRouter* iqRouter, SOCKS5BytestreamServer* socksServer, SOCKS5BytestreamRegistry* registry);

			virtual void start();
			virtual void stop();
			virtual void cancel();

			SWIFTEN_SIGNAL_NAMESPACE::signal<void (const boost::optional<FileTransferError>&)> onFinished;

		private:
			void handleStreamInitiationRequestResponse(StreamInitiation::ref, ErrorPayload::ref);
			void handleBytestreamsRequestResponse(Bytestreams::ref, ErrorPayload::ref);
			void finish(boost::optional<FileTransferError> error);
			void handleIBBSessionFinished(boost::optional<FileTransferError> error);

		private:
			std::string id;
			JID from;
			JID to;
			std::string name;
			int size;
			std::string description;
			SWIFTEN_SHRPTR_NAMESPACE::shared_ptr<ReadBytestream> bytestream;
			IQRouter* iqRouter;
			SOCKS5BytestreamServer* socksServer;
			SWIFTEN_SHRPTR_NAMESPACE::shared_ptr<IBBSendSession> ibbSession;
			SOCKS5BytestreamRegistry *registry;
	};
}
