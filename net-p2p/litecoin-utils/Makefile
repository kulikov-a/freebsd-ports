MASTERDIR=	${.CURDIR}/../litecoin
PORTREVISION=	3
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS ZMQ
OPTIONS_RADIO=

PKGHELP=	${NONEXISTENT}

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-miniupnpc \
		--with-utils \
		--disable-wallet

PLIST_FILES=	bin/litecoin-cli bin/litecoin-tx \
		man/man1/litecoin-cli.1.gz man/man1/litecoin-tx.1.gz \
		bin/litecoin-wallet \
		man/man1/litecoin-wallet.1.gz

.include "${MASTERDIR}/Makefile"
