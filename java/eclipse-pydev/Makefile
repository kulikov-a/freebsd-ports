PORTNAME=	pydev
PORTVERSION=	10.1.3
CATEGORIES=	java devel python
MASTER_SITES=	https://github.com/fabioz/Pydev/releases/download/${PORTNAME}_10_1_3/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	PyDev.${PORTVERSION}

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Eclipse plugin for Python and Jython development
WWW=		https://www.pydev.org/

LICENSE=	EPL

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:java/eclipse

USES=		python zip

USE_JAVA=	YES
JAVA_VERSION=	1.8+
JAVA_OS=	native
JAVA_RUN=	YES

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

OPTIONS_DEFINE=	JYTHON

JYTHON_DESC=	Use Jython as Python interpreter

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJYTHON}
RUN_DEPENDS+=	jython:lang/jython
.endif

PLUGINDIR=	share/eclipse/dropins/${PORTNAME}/eclipse

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/${PLUGINDIR})

.include <bsd.port.mk>
