PORTNAME=	openpgl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-beta
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Intel Open Path Guiding Library
WWW=		http://www.openpgl.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# supported processors -
# arm with NEON/NEON2X and x86_64 with SSE4/AVX2/AVX512
ONLY_FOR_ARCHS=		amd64 armv6 armv7
ONLY_FOR_ARCHS_REASON=	requires supported SIMD ISA

LIB_DEPENDS=	libembree3.so:graphics/embree \
		libtbb.so:devel/onetbb

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenPathGuidingLibrary

.include <bsd.port.mk>
