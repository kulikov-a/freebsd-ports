PORTNAME=	gitlab-omniauth-openid-connect
PORTVERSION=	0.10.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OpenID Connect Strategy for OmniAuth
WWW=		https://gitlab.com/gitlab-org/gitlab-omniauth-openid-connect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.7<3.0:www/rubygem-addressable \
		rubygem-omniauth1>=1.9<3.0:security/rubygem-omniauth1 \
		rubygem-openid_connect>=1.2<2.0:net/rubygem-openid_connect

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
