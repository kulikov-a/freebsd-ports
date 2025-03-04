PORTNAME=	comrak
DISTVERSION=	0.15.0
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CommonMark + GFM compatible Markdown parser and renderer
WWW=		https://docs.rs/comrak/latest/comrak/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kivikakk

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		atom-0.3.6 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bincode-1.3.3 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.3.1 \
		block-buffer-0.10.3 \
		byteorder-1.4.3 \
		cc-1.0.70 \
		cfg-if-1.0.0 \
		clap-4.0.23 \
		clap_derive-4.0.21 \
		clap_lex-0.3.0 \
		cpufeatures-0.2.5 \
		crc32fast-1.2.1 \
		crypto-common-0.1.6 \
		digest-0.10.5 \
		entities-1.0.1 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		fancy-regex-0.7.1 \
		flate2-1.0.21 \
		fnv-1.0.7 \
		generic-array-0.14.6 \
		getrandom-0.1.16 \
		getrandom-0.2.3 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.7.0 \
		io-lifetimes-0.7.5 \
		itoa-0.4.8 \
		itoa-1.0.3 \
		lazy_static-1.4.0 \
		libc-0.2.134 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.4 \
		linux-raw-sys-0.0.46 \
		memchr-2.4.0 \
		miniz_oxide-0.4.4 \
		num-traits-0.2.14 \
		num_threads-0.1.6 \
		once_cell-1.13.0 \
		onig-6.2.0 \
		onig_sys-69.7.0 \
		os_str_bytes-6.4.0 \
		pest-2.4.1 \
		pest_derive-2.4.1 \
		pest_generator-2.4.1 \
		pest_meta-2.4.1 \
		pkg-config-0.3.19 \
		plist-1.3.1 \
		ppv-lite86-0.2.10 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.47 \
		propfuzz-0.0.1 \
		propfuzz-macro-0.0.1 \
		proptest-0.10.1 \
		pulse-0.5.3 \
		quick-error-1.2.3 \
		quote-1.0.9 \
		rand-0.7.3 \
		rand-0.8.4 \
		rand_chacha-0.2.2 \
		rand_chacha-0.3.1 \
		rand_core-0.5.1 \
		rand_core-0.6.3 \
		rand_hc-0.2.0 \
		rand_hc-0.3.1 \
		rand_xorshift-0.2.0 \
		redox_syscall-0.2.10 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rustix-0.35.13 \
		rusty-fork-0.3.0 \
		ryu-1.0.5 \
		safemem-0.3.3 \
		same-file-1.0.6 \
		serde-1.0.128 \
		serde_derive-1.0.128 \
		serde_json-1.0.66 \
		sha1-0.10.5 \
		shell-words-1.0.0 \
		strsim-0.10.0 \
		syn-1.0.74 \
		syntect-5.0.0 \
		tempfile-3.2.0 \
		termcolor-1.1.3 \
		terminal_size-0.2.2 \
		thiserror-1.0.37 \
		thiserror-impl-1.0.37 \
		time-0.1.43 \
		time-0.3.14 \
		timebomb-0.1.2 \
		typed-arena-2.0.1 \
		typenum-1.15.0 \
		ucd-trie-0.1.5 \
		unicode-ident-1.0.5 \
		unicode-xid-0.2.2 \
		unicode_categories-0.1.1 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.42.0 \
		xdg-2.2.0 \
		xml-rs-0.8.4 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
