PORTNAME=	dolibarr
DISTVERSION=	13.0.5
CATEGORIES=	www finance
PKGNAMESUFFIX=	13

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Modern software package to manage your company or foundation
WWW=		https://www.dolibarr.org/

DEPRECATED=	No support PHP >= 8.x
EXPIRATION_DATE=2023-04-30

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:S/d/D/}
USES=		cpe php:web
USE_PHP=	calendar curl gd intl pcre session openssl
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USE=		PHP=mysqli
PGSQL_USE=		PHP=pgsql

WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	${RM} -R ${WRKSRC}/.github
	${RM} ${WRKSRC}/.gitmessage
	${RM} ${WRKSRC}/.stickler.yml

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>
