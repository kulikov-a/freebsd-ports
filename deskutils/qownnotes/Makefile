PORTNAME=	qownnotes
PORTVERSION=	23.3.7
CATEGORIES=	deskutils
MASTER_SITES=	https://download.tuxfamily.org/qownnotes/src/

MAINTAINER=	stobbsm@gmail.com
COMMENT=	Markdown note taking program with cloud integration
WWW=		https://www.qownnotes.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libbotan-2.so:security/botan2
RUN_DEPENDS=	git:devel/git

USES=		gl gmake pkgconfig qmake qt:5 tar:xz xorg
USE_GL=		gl
USE_QT=		buildtools:build linguisttools:build \
		concurrent core declarative gui network printsupport \
		sql svg websockets widgets x11extras xml xmlpatterns
USE_XORG=	x11

QMAKE_ARGS=	USE_SYSTEM_BOTAN=1

.include <bsd.port.mk>
