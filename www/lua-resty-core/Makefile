PORTNAME=	lua-resty-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.24
CATEGORIES=	www

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	New FFI-based Lua API for OpenResty NGINX Lua modules
WWW=		https://github.com/openresty/lua-resty-core

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	lua-resty-lrucache>=0.10:www/lua-resty-lrucache \
		luajit-openresty>=2.1:lang/luajit-openresty

USE_GITHUB=	yes
GH_ACCOUNT=	openresty

NO_ARCH=	yes
NO_BUILD=	yes

LUA_MODSHAREDIR=	${LOCALBASE}/share/lua/5.1

PLIST_SUB=	LUA_MODSHAREDIR=${LUA_MODSHAREDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${LUA_MODSHAREDIR} "-name *\.lua")

.include <bsd.port.mk>
