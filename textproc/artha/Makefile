PORTNAME=	artha
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	lichray@gmail.com
COMMENT=	Free cross-platform English thesaurus
WWW=		http://artha.sourceforge.net/wiki/index.php/Home

LICENSE=	GPLv2

BROKEN=		Fails to build with recent compilers against unmaintained GTK 2
DEPRECATED=	Abandonware, last release in 2012
EXPIRATION_DATE=2023-03-31

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libWN.so:textproc/wordnet

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool
USES=		cpe gmake gnome libtool pkgconfig
CPE_VENDOR=	${PORTNAME}_project

CONFIGURE_ARGS=	--enable-static=no --x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
CFLAGS+=	-fcommon
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/WordNet
LIBS+=		`pkg-config --libs gio-2.0`

OPTIONS_DEFINE=	NOTIFY
NOTIFY_DESC=	Popup word definition as notification

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

.include <bsd.port.mk>
