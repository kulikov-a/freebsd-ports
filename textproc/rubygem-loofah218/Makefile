PORTNAME=	loofah
PORTVERSION=	2.18.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	218

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library for manipulating HTML/XML documents and fragments
WWW=		https://github.com/flavorjones/loofah

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-crass>=1.0.2<1.1:www/rubygem-crass \
		rubygem-nokogiri>=1.5.9:textproc/rubygem-nokogiri

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	loofah_project

.include <bsd.port.mk>
