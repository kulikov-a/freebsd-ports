PORTNAME=	mongodb
DISTVERSIONPREFIX=	r
DISTVERSION=	3.6.23
PORTREVISION=	1
CATEGORIES=	databases net
MASTER_SITES=	https://fastdl.mongodb.org/src/ \
		http://fastdl.mongodb.org/src/
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	mongodb-src-${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed document-oriented "NoSQL" database
WWW=		https://docs.mongodb.com/v3.6/

# mongodb is SSPLv1, C++ driver is APACHE20
LICENSE=	SSPLv1 APACHE20
LICENSE_COMB=	multi
LICENSE_NAME_SSPLv1=	Server Side Public License Version 1
LICENSE_FILE_SSPLv1=	${WRKSRC}/LICENSE-Community.txt
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Upstream EOL reached on 2021-04-30
EXPIRATION_DATE=	2023-03-31
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only supported on amd64 and aarch64; i386 deprecated in v3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libsnappy.so:archivers/snappy

USES=		compiler:c++14-lang cpe python:3.7+,build scons shebangfix
USE_RC_SUBR=	mongod

CONFLICTS_INSTALL=	mongodb[0-9][0-9] # etc/mongodb.conf.sample

SHEBANG_FILES=	src/mongo/installer/compass/install_compass.in
python_OLD_CMD=	@python_interpreter@
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--use-system-pcre --use-system-snappy \
		--use-system-zlib \
		--cxx-std=14 --libc++ \
		--runtime-hardening=on \
		--disable-warnings-as-errors \
		VERBOSE=on

USERS=		mongodb
GROUPS=		mongodb

OPTIONS_DEFINE=		SASL SSL
OPTIONS_DEFAULT=	SASL SSL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_MAKE_ARGS=		--use-sasl-client

SSL_USES=	ssl
SSL_MAKE_ARGS=	--ssl

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
EXTRA_PATCHES=	${FILESDIR}/aarch64
.endif

ALL_TARGET=	core

PORTSCOUT=	limitw:1,even

CPE_PRODUCT=	mongodb

post-install:
.for f in mongo mongod mongoperf mongos
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${CP} ${WRKSRC}/rpm/mongod.conf ${STAGEDIR}${PREFIX}/etc/mongodb.conf.sample

.include <bsd.port.mk>
