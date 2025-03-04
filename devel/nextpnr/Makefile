PORTNAME=	nextpnr
DISTVERSION=	0.4
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Portable FPGA place and route tool
WWW=		https://github.com/YosysHQ/nextpnr

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	clang segfault
BROKEN_FreeBSD_12_powerpc64=	runaway build

BUILD_DEPENDS=	${LOCALBASE}/share/trellis/database:devel/trellis \
		${LOCALBASE}/share/icebox:devel/icestorm
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		${PY_BOOST}

USES=		compiler:c++11-lang cmake qt:5 eigen:3 python:3.5+ gl
USE_QT=		buildtools:build core gui opengl qmake:build widgets
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TAGNAME=	${PORTNAME}-${DISTVERSION}
GH_TUPLE=	YosysHQ:nextpnr-tests:00c55a9e:tests/tests

BINARY_ALIAS=	python3=${PYTHON_CMD}

CMAKE_ARGS=	-DARCH="ice40;ecp5" -DTRELLIS_ROOT=${LOCALBASE}/share/trellis/

PLIST_FILES=	bin/nextpnr-ecp5 \
		bin/nextpnr-ice40

.include <bsd.port.mk>
