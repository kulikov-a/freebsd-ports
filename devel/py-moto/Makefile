PORTNAME=	moto
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Allow your python tests to easily mock out the boto library
WWW=		https://github.com/getmoto/moto

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=40.6.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.9.201:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.12.201:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.3.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.1<3.0.0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.13.0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0.5:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aws-xray-sdk>=0.93:devel/py-aws-xray-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cfn-lint>=0.40.0:devel/py-cfn-lint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>=2.5.1:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.16:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=2.2.2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphql-core>=0:devel/py-graphql-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsondiff>=1.1.2:devel/py-jsondiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-spec-validator>=0.2.8:devel/py-openapi-spec-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.7:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jose>=3.1.0<4.0.0:security/py-python-jose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sshpubkeys>=3.1.0:security/py-sshpubkeys@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
