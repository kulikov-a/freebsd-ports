PORTNAME=	t
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line power tool for Twitter
WWW=		https://sferik.github.io/t/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-geokit>=1.9<2:graphics/rubygem-geokit \
		rubygem-htmlentities>=4.3<5:textproc/rubygem-htmlentities \
		rubygem-launchy>=2.4<3:devel/rubygem-launchy \
		rubygem-oauth>=0.5.1<0.6:net/rubygem-oauth \
		rubygem-retryable>=3.0<4:devel/rubygem-retryable \
		rubygem-thor>=0.19.1<2:devel/rubygem-thor \
		rubygem-twitter>=6.0:net/rubygem-twitter

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/t

.include <bsd.port.mk>
