PORTNAME=	mp3c
PORTVERSION=	0.31
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wspse.de/linux/wspse/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD to mp3c converter with a console frontend
WWW=		http://mp3c.wspse.de/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, last release in 2009. Please consider using audio/cyanrip or audio/abcde
EXPIRATION_DATE=2023-03-31

RUN_DEPENDS=	mp3info:audio/mp3info \
		cdrecord:sysutils/cdrtools

USES=		ncurses
GNU_CONFIGURE=	yes

DEFAULT_CDROM_DEVICE?=	cd0

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|rcd0d|${DEFAULT_CDROM_DEVICE}|g' \
		-e 's|/dev/cdrom|/dev/${DEFAULT_CDROM_DEVICE}|g' \
		${WRKSRC}/src/conf.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/cdrip.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
