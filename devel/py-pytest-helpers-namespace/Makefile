PORTNAME=	pytest-helpers-namespace
PORTVERSION=	2019.1.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Provide a helpers namespace in pytest
WWW=		https://pypi.org/project/pytest-helpers-namespace/

LICENSE=	APACHE20

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# pypi tarball does not contain any of the test code?

#do-test:
#	@cd ${WRKSRC} && ${LOCALBASE}/bin/pytest-${PYTHON_VER} tests

.include <bsd.port.mk>
