PORTNAME=	liblas
PORTVERSION=	1.8.1
PORTREVISION=	22
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library For Reading And Writing LAS-Format Data
WWW=		https://liblas.org/

LICENSE=	BSD3CLAUSE BSL MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libgeotiff.so:graphics/libgeotiff

PORTSCOUT=	skipv:progress-20071229

USES=		cmake compiler:c++11-lang cpe libtool
LDFLAGS+=	-lpthread
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	libLAS
GH_PROJECT=	${GH_ACCOUNT}

.include <bsd.port.mk>
