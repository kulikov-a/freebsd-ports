PORTNAME=	bladeRF
DISTVERSION=	2023.02
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	BladeRF USB 3.0 Superspeed software defined radio
WWW=		https://www.nuand.com/

LICENSE=	MIT LGPL20 GPLv2
LICENSE_COMB=	multi

USES=		cmake compiler:c11 libedit
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Nuand
GH_TUPLE=	analogdevicesinc:no-OS:0bba46e:x/thirdparty/analogdevicesinc/no-OS

PLIST_FILES=	bin/bladeRF-cli \
		bin/bladeRF-fsk \
		include/bladeRF1.h \
		include/bladeRF2.h \
		include/libbladeRF.h \
		lib/libbladeRF.so \
		lib/libbladeRF.so.2 \
		libdata/pkgconfig/libbladeRF.pc

.include <bsd.port.mk>
