PORTNAME=	music21
DISTVERSION=	7.3.3
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Toolkit for computer-aided musical analysis
WWW=		https://web.mit.edu/music21/

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}joblib>0:devel/py-joblib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpickle>0:devel/py-jsonpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webcolors>=1.5:graphics/py-webcolors@${PY_FLAVOR} \
		lilypond:print/lilypond \
		mscore:audio/musescore \
		xdg-open:devel/xdg-utils

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e " \
		s|/usr/bin/lilypond|${LOCALBASE}/bin/lilypond|; \
		s|/usr/bin/mscore3|${LOCALBASE}/bin/mscore|; \
		s|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|" \
		${WRKSRC}/music21/environment.py

.include <bsd.port.mk>
