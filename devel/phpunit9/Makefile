PORTNAME=	phpunit
PORTVERSION=	9.6.3
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/
PKGNAMESUFFIX=	9${PHP_PKGNAMESUFFIX}
EXTRACT_SUFX=	.phar

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for unit tests
WWW=		https://phpunit.de/ \
		https://github.com/sebastianbergmann/phpunit

LICENSE=	BSD3CLAUSE

USES=		cpe php:flavors
USE_PHP=	dom json pcre phar spl

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/phpunit

CONFLICTS_INSTALL=	phpunit[0-9] phpunit[0-9][0-9]

CPE_VENDOR=	phpunit_project

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/phpunit

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/phpunit ${STAGEDIR}${PREFIX}/bin/phpunit

.include <bsd.port.mk>
