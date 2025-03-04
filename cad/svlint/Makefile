PORTNAME=	svlint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	cad devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SystemVerilog linter
WWW=		https://github.com/dalance/svlint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	dalance

CARGO_CRATES=	aho-corasick-0.7.20 \
		anyhow-1.0.70 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bytecount-0.6.3 \
		cfg-if-1.0.0 \
		clap-3.2.23 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		colored-2.0.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		enquote-1.1.0 \
		getrandom-0.2.8 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		indexmap-1.9.2 \
		lazy_static-1.4.0 \
		libc-0.2.140 \
		libloading-0.7.4 \
		memchr-2.5.0 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		nom-greedyerror-0.5.0 \
		nom-packrat-0.7.0 \
		nom-packrat-macros-0.7.0 \
		nom-recursive-0.5.0 \
		nom-recursive-macros-0.5.0 \
		nom-tracable-0.9.0 \
		nom-tracable-macros-0.9.0 \
		nom_locate-4.1.0 \
		once_cell-1.17.1 \
		os_str_bytes-6.5.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.53 \
		quote-1.0.26 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.2 \
		regex-syntax-0.6.29 \
		rustversion-1.0.12 \
		same-file-1.0.6 \
		serde-1.0.158 \
		serde_derive-1.0.158 \
		serde_regex-1.1.0 \
		serde_spanned-0.6.1 \
		str-concat-0.2.0 \
		strsim-0.10.0 \
		sv-filelist-parser-0.1.3 \
		sv-parser-0.13.1 \
		sv-parser-error-0.13.1 \
		sv-parser-macros-0.13.1 \
		sv-parser-parser-0.13.1 \
		sv-parser-pp-0.13.1 \
		sv-parser-syntaxtree-0.13.1 \
		syn-1.0.109 \
		syn-2.0.8 \
		term-0.7.0 \
		termcolor-1.2.0 \
		textwrap-0.16.0 \
		thiserror-1.0.40 \
		thiserror-impl-1.0.40 \
		toml-0.7.3 \
		toml_datetime-0.6.1 \
		toml_edit-0.19.8 \
		unicode-ident-1.0.8 \
		version_check-0.9.4 \
		walkdir-2.3.3 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winnow-0.4.0

PLIST_FILES=	bin/${PORTNAME} \
		bin/mdgen

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/mdgen

.include <bsd.port.mk>
