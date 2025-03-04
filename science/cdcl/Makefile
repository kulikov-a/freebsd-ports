PORTNAME=	cdcl
PORTVERSION=	5.4.8
PORTREVISION=	2
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/arch/dcl/ \
		http://dennou-h.gfd-dennou.org/arch/dcl/ \
		http://dennou-q.gfd-dennou.org/arch/dcl/
DISTNAME=	dcl-${PORTVERSION}-C

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience
WWW=		https://www.gfd-dennou.org/arch/dcl/

# Converted from RESTRICTED
LICENSE=	cdcl
LICENSE_NAME=	cdcl
LICENSE_TEXT=	No commercial use
LICENSE_PERMS=	auto-accept

BROKEN=			fails to fetch from mastersite (newest release is 7.4.0 of 2020611)
BROKEN_armv6=		fails to link: final link failed: Nonrepresentable section on output
BROKEN_armv7=		fails to link: final link failed: Nonrepresentable section on output
DEPRECATED=	Broken since 2021
EXPIRATION_DATE=	2023-04-21

OPTIONS_DEFINE=	DOCS EXAMPLES
USES=		desthack gnome pkgconfig xorg
USE_XORG=	x11 xext
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x --enable-shared
# Fix build with clang11
CFLAGS+=	-fcommon

PLIST_SUB=	DCL_VERSION=${PORTVERSION:S/.//g}

MAKE_JOBS_UNSAFE=	yes

BINARIES=	cdclcmap cdclclr cdcldate cdcldbs cdclexec cdclfont \
		cdclpara cdcltone cdcltrf cdclver
PORTDOCS=	CHECK CREDITS HISTORY README
PORTEXAMPLES=	*

post-configure:
	@${REINPLACE_CMD} -e 's|$$(DCLLANG)dcl$$(DCLVERNUM)|$$(DCLLANG)dcl|' ${WRKSRC}/Mkinclude

post-install:
.for i in ${BINARIES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
