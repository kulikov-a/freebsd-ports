PORTNAME=	phpmyfaq
PORTVERSION=	3.1.12
CATEGORIES=	www
MASTER_SITES=	https://download.phpmyfaq.de/files/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Multilingual, completely database-driven FAQ-system
WWW=		https://www.phpmyfaq.de/

LICENSE=	MPL20

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cpe php:web
USE_PHP=	filter json mysqli pcre session xml xmlrpc xmlwriter zlib
FAQ_DIR=	attachments data images inc pdf xml
NO_BUILD=	YES
NO_ARCH=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}
.for i in ${FAQ_DIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${i}
.endfor

.include <bsd.port.mk>
