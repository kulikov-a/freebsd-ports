PORTNAME=	syncthing
PORTVERSION=	1.22.0
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	https://github.com/syncthing/syncthing/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSIONPREFIX}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Encrypted file sync tool
WWW=		https://syncthing.net/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/${PORTNAME}/LICENSE

USES=		cpe go:1.19,modules

USE_RC_SUBR=	syncthing syncthing-discosrv syncthing-relaysrv syncthing-relaypoolsrv

BINS=		syncthing stdiscosrv strelaysrv strelaypoolsrv

.for x in ${BINS}
PLIST_FILES+=	bin/${x}
.endfor

PORTDOCS=	*

USERS=		syncthing
GROUPS=		syncthing

# Anonymize
MAKE_ENV+=	BUILD_USER=ports BUILD_HOST=freebsd

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes

do-build:
	@( cd ${WRKSRC}/${PORTNAME} ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${PORTVERSION} -no-upgrade build ; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${PORTVERSION} -no-upgrade build stdiscosrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${PORTVERSION} -no-upgrade build strelaysrv; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run build.go -version v${PORTVERSION} -no-upgrade build strelaypoolsrv; \
		)

do-install:
.for x in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${x} \
		${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in AUTHORS LICENSE README.md
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
