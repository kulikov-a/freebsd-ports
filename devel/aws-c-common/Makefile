PORTNAME=	aws-c-common
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.15
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Core c99 package for AWS SDK for C
WWW=		https://github.com/awslabs/aws-c-common

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.mk>
