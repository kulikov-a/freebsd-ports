PORTNAME=	kicad
PORTVERSION=	7.0.1
CATEGORIES=	cad
MASTER_SITES=	https://kicad-downloads.s3.cern.ch/docs/
PKGNAMESUFFIX=	-doc
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	KiCad Documentation and Help Files
WWW=		https://gitlab.com/kicad/services/kicad-doc

LICENSE=	GPLv3+ CC-BY-3.0
LICENSE_COMB=	dual

RUN_DEPENDS=	kicad:cad/kicad

CONFLICTS=	kicad-devel-r2*

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/share/doc/kicad && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
