PORTNAME=	redmine
PORTVERSION=	4.2.10
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/
PKGNAMESUFFIX=	42

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Flexible project management web application
WWW=		https://www.redmine.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-bundler>=1.5.0:sysutils/rubygem-bundler \
		rubygem-rails52>=5.2.8.1<5.3:www/rubygem-rails52 \
		rubygem-rouge>=3.26.0:textproc/rubygem-rouge \
		rubygem-request_store>=1.5.0:devel/rubygem-request_store \
		rubygem-mini_mime>=1.0.1:mail/rubygem-mini_mime \
		rubygem-actionpack-xml_parser-rails52>=0:textproc/rubygem-actionpack-xml_parser-rails52 \
		rubygem-roadie-rails-rails52>=2.1.0:mail/rubygem-roadie-rails-rails52 \
		rubygem-mail>=2.7.1:mail/rubygem-mail \
		rubygem-csv>=3.1.1:devel/rubygem-csv \
		rubygem-nokogiri111>=1.11.0:textproc/rubygem-nokogiri111 \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-rbpdf>=1.19.6:print/rubygem-rbpdf \
		rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-ruby-openid>=2.9.2:net/rubygem-ruby-openid \
		rubygem-rack-openid>=0:www/rubygem-rack-openid \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-rotp>0:devel/rubygem-rotp \
		rubygem-rqrcode>0:www/rubygem-rqrcode

USES=		cpe ruby
BROKEN_RUBY30=	yes
BROKEN_RUBY31=	yes

CONFLICTS_INSTALL=	redmine4

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_SUFFIX=${RUBY_SUFFIX}

OPTIONS_DEFINE=	MYSQL POSTGRESQL MARKDOWN RMAGIC THIN
OPTIONS_DEFAULT=MYSQL MARKDOWN RMAGIC THIN
OPTIONS_SUB=	yes
POSTGRESQL_DESC=Enable PostgreSQL support
MARKDOWN_DESC=	Enable Markdown support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
MYSQL_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=	yes

MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.5.0:databases/rubygem-mysql2
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=1.1.4:databases/rubygem-pg
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.4.0:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-mini_magick>=4.9.5:graphics/rubygem-mini_magick
THIN_RUN_DEPENDS=	rubygem-thin>=1.6.2:www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

.include <bsd.port.options.mk>

post-extract:
	@${RM} -r ${WRKSRC}/.hgignore ${WRKSRC}/.gitignore ${WRKSRC}/.github \
		${WRKSRC}/files/delete.me ${WRKSRC}/log/delete.me
	@${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml.sample
	@${MV} ${WRKSRC}/config/database.yml.example ${WRKSRC}/config/database.yml.sample

post-patch:
	@${RM} ${WRKSRC}/Gemfile.orig

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/bundler.d
	${MKDIR} ${STAGEDIR}${WWWDIR}/log
	${MKDIR} ${STAGEDIR}${WWWDIR}/public/plugin_assets
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

do-install-MYSQL-on:
	${CP} ${FILESDIR}/mysql.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-POSTGRESQL-on:
	${CP} ${FILESDIR}/pg.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-MARKDOWN-on:
	${CP} ${FILESDIR}/markdown.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-RMAGIC-on:
	${CP} ${FILESDIR}/mini_magick.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-THIN-on:
	${CP} ${FILESDIR}/thin.rb ${STAGEDIR}${WWWDIR}/bundler.d

post-install:
	(cd ${STAGEDIR}${WWWDIR} && ${RM} Gemfile.lock && bundle install --local)
	${RM} ${STAGEDIR}${WWWDIR}/package.json \
		${STAGEDIR}${WWWDIR}/yarn.lock

.include <bsd.port.mk>
