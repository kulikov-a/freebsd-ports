PORTNAME=	cachy
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple yet effective caching library
WWW=		https://github.com/sdispater/cachy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	MEMCACHED MSGPACK REDIS
MEMCACHED_DESC=	Memcached support
MSGPACK_DESC=	MessagePack support
REDIS_DESC=	Redis support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=1.59<2.0:databases/py-python-memcached@${PY_FLAVOR}
MSGPACK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5:devel/py-msgpack@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=3.3.6<4.0.0:databases/py-redis@${PY_FLAVOR}

.include <bsd.port.mk>
