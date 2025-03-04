PORTNAME=	ampache
PORTVERSION=	5.5.7
DISTVERSIONSUFFIX=	_all
CATEGORIES=	audio www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Web-based Audio file manager
WWW=		https://ampache.org/

LICENSE=	AGPLv3+

USES=		cpe zip gettext php:flavors mysql
USE_PHP=	pdo pdo_mysql hash session json intl simplexml curl dom xml

CONFLICTS_INSTALL=	ampache-php* # etc/periodic/daily/500.ampache-cron man/man1/ampache.1.gz

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SUB_FILES=	500.ampache-cron
SUB_LIST=	WWWOWN="${WWWOWN}"
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	DOCS

post-patch:
.for h in channel play rest
	${REINPLACE_CMD} 's,[[:space:]]*RewriteRule [^[:space:]]*[[:space:]],&/ampache,'	\
		${WRKSRC}/public/$h/.htaccess.dist
.endfor
	${REINPLACE_CMD} 's,^;web_path = "",web_path = "/${PORTNAME}",'	\
		${WRKSRC}/config/ampache.cfg.php.dist

do-build:
	${MKDIR} ${WRKSRC}/src

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in $$(${FIND} ${WRKSRC} -name .htaccess); do \
		${MV} $$f $$f.dist; \
		done
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '-not -regex ^./man.*')
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} '-not -regex ^./docs.* -a -not -name *.bak')
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/500.ampache-cron ${STAGEDIR}${PREFIX}/etc/periodic/daily/

.include <bsd.port.mk>
