PORTNAME=	File_Iterator
PORTVERSION=	4.0.1
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR FileIterator implementation
WWW=		https://github.com/sebastianbergmann/php-file-iterator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-file-iterator

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/Iterator.php

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/Iterator.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
