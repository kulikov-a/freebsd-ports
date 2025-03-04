PORTNAME=	ringrtc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.25.2
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/mikael/ringrtc/:base \
		LOCAL/mikael/ringrtc/:boringssl \
		LOCAL/mikael/ringrtc/:build \
		LOCAL/mikael/ringrtc/:buildtools \
		LOCAL/mikael/ringrtc/:catapult \
		LOCAL/mikael/ringrtc/:icu \
		LOCAL/mikael/ringrtc/:nasm \
		LOCAL/mikael/ringrtc/:libjpeg_turbo \
		LOCAL/mikael/ringrtc/:libsrtp \
		LOCAL/mikael/ringrtc/:libvpx \
		LOCAL/mikael/ringrtc/:libyuv \
		LOCAL/mikael/ringrtc/:third_party \
		LOCAL/mikael/ringrtc/:testing
DISTFILES=	base-${BASE_REV}.tar.gz:base \
		boringssl-${BORINGSSL_REV}.tar.gz:boringssl \
		build-${BUILD_REV}.tar.gz:build \
		buildtools-${BUILDTOOLS_REV}.tar.gz:buildtools \
		catapult-${CATAPULT_REV}.tar.gz:catapult \
		icu-${ICU_REV}.tar.gz:icu \
		nasm-${NASM_REV}.tar.gz:nasm \
		libjpeg_turbo-${LIBJPEG_TURBO_REV}.tar.gz:libjpeg_turbo \
		libsrtp-${LIBSRTP_REV}.tar.gz:libsrtp \
		libvpx-${LIBVPX_REV}.tar.gz:libvpx \
		libyuv-${LIBYUV_REV}.tar.gz:libyuv \
		third_party-${THIRD_PARTY_REV}.tar.gz:third_party \
		testing-${TESTING_REV}.tar.gz:testing

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Middleware library for Signal-Desktop
WWW=		https://github.com/signalapp/ringrtc

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	gn:devel/gn \
		protoc:devel/protobuf
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfreetype.so:print/freetype2 \
		libpulse.so:audio/pulseaudio

USES=		cargo gnome localbase:ldflags ninja pkgconfig python:3.7+,build \
		tar:xz
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	signalapp
GH_TUPLE=	signalapp:ringrtc:${DISTVERSIONPREFIX}${DISTVERSION} \
		signalapp:webrtc:${WEBRTC_REV}:webrtc

# Add extra-patch-no-mempcpy-nasm only when there's no mempcpy() in base.
# Nested variable expansion avoids executing the test when not needed for
# expanding EXTRA_PATCHES.
EXTRA_PATCHES+=	${"${:!${GREP} mempcpy ${CROSS_SYSROOT}/usr/include/string.h \
	|| ${TRUE}!}" == "":?${PATCHDIR}/extra-patch-no-mempcpy-nasm:}

# sh net-im/signal-desktop/get_deps.sh
WEBRTC_REV=	5481

# modify webrtc_fetch.sh, then sh webrtc_fetch.sh
BASE_REV=		b054aaefd4d4ec5aad7189c4e97000a06b594163
BORINGSSL_REV=		1ee71185a2322dc354bee5e5a0abfb1810a27dc6
BUILD_REV=		1c4f38fd4f534d78b72cefc376a03b3e8b486e7c
BUILDTOOLS_REV=		24fa2da896a027e7202bb8886177cccfe885b67d
CATAPULT_REV=		4793433248183dd073e608f655204d4acfdc7193
ICU_REV=		20f8ac695af59b6c830def7d4e95bfeb13dd7be5
LIBJPEG_TURBO_REV=	ed683925e4897a84b3bffc5c1414c85b97a129a3
LIBSRTP_REV=		5b7c744eb8310250ccc534f3f86a2015b3887a0a
LIBVPX_REV=		9d6d0624d7943a09cc0be9df1a7402522989ac1a
LIBYUV_REV=		00950840d1c9bcbb3eb6ebc5aac5793e71166c8b
NASM_REV=		9215e8e1d0fe474ffd3e16c1a07a0f97089e6224
TESTING_REV=		6f2362298838e8789b09282cf198c8582f9c4555
THIRD_PARTY_REV=	28a4580f804c4fc4279ecf10100a409811030235

BINARY_ALIAS=	vpython3=${PYTHON_CMD}

# Keep in sync with https://github.com/signalapp/ringrtc/blob/${DISTVERSION}/bin/build-electron#L96
# Run "gn args out/Release --list" for all variables.
# Some parts don't have use_system_* flag, and can be turned on/off by using
# replace_gn_files.py script, some parts just turned on/off for target host
# OS "target_os == is_bsd", like libusb, libpci.
GN_ARGS+=	rtc_build_examples=false \
		rtc_build_tools=false \
		rtc_include_tests=false \
		rtc_enable_protobuf=false \
		rtc_use_x11=false \
		rtc_enable_sctp=false \
		rtc_libvpx_build_vp9=false \
		rtc_include_ilbc=false \
		use_custom_libcxx=false \
		is_debug=false \
		is_clang=true \
		clang_use_chrome_plugins=false \
		extra_cxxflags="${CXXFLAGS}" \
		extra_ldflags="${LDFLAGS}"

MAKE_ARGS=	-C out/${BUILDTYPE}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/rust
WEBRTCDIR=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc/src

# fetch -qo - https://raw.githubusercontent.com/signalapp/ringrtc/v2.25.1/src/rust/Cargo.lock | awk -f /usr/ports/Mk/Scripts/cargo-crates.awk | portedit merge -i Makefile
CARGO_CRATES=	adler-1.0.2 \
		aes-0.8.2 \
		aho-corasick-0.7.20 \
		anyhow-1.0.69 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.1 \
		bitflags-1.3.2 \
		block-buffer-0.10.3 \
		bumpalo-3.12.0 \
		byteorder-1.4.3 \
		bytes-1.4.0 \
		cc-1.0.79 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		cipher-0.4.3 \
		combine-4.6.6 \
		core-foundation-sys-0.8.3 \
		cpufeatures-0.2.5 \
		crc32fast-1.3.2 \
		crypto-common-0.1.6 \
		ctr-0.9.2 \
		curve25519-dalek-3.2.1 \
		digest-0.9.0 \
		digest-0.10.6 \
		either-1.8.1 \
		env_logger-0.9.3 \
		fastrand-1.9.0 \
		fixedbitset-0.4.2 \
		flate2-1.0.25 \
		form_urlencoded-1.1.0 \
		futures-0.3.26 \
		futures-channel-0.3.26 \
		futures-core-0.3.26 \
		futures-executor-0.3.26 \
		futures-io-0.3.26 \
		futures-macro-0.3.26 \
		futures-sink-0.3.26 \
		futures-task-0.3.26 \
		futures-util-0.3.26 \
		generic-array-0.14.6 \
		getrandom-0.1.16 \
		hashbrown-0.12.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.2.6 \
		hex-0.4.3 \
		hkdf-0.12.3 \
		hmac-0.12.1 \
		humantime-2.1.0 \
		idna-0.3.0 \
		indexmap-1.9.2 \
		inout-0.1.3 \
		instant-0.1.12 \
		itertools-0.10.5 \
		itoa-1.0.5 \
		jni-0.19.0 \
		jni-sys-0.3.0 \
		js-sys-0.3.61 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		libloading-0.6.7 \
		log-0.4.17 \
		memchr-2.5.0 \
		miniz_oxide-0.6.2 \
		multimap-0.8.3 \
		neon-0.10.1 \
		neon-build-0.10.1 \
		neon-macros-0.10.1 \
		neon-runtime-0.10.1 \
		nom8-0.2.0 \
		ntapi-0.4.0 \
		num_cpus-1.15.0 \
		num_enum-0.5.10 \
		num_enum_derive-0.5.10 \
		once_cell-1.17.1 \
		percent-encoding-2.2.0 \
		petgraph-0.6.3 \
		pin-project-lite-0.2.9 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.17 \
		prettyplease-0.1.23 \
		proc-macro-crate-1.3.0 \
		proc-macro2-1.0.51 \
		prost-0.11.6 \
		prost-build-0.11.6 \
		prost-derive-0.11.6 \
		prost-types-0.11.6 \
		quote-1.0.23 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.2.16 \
		regex-1.7.1 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		ring-0.16.20 \
		rustls-0.20.8 \
		ryu-1.0.12 \
		same-file-1.0.6 \
		sct-0.7.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_json-1.0.93 \
		sha2-0.10.6 \
		slab-0.4.7 \
		smallvec-1.10.0 \
		spin-0.5.2 \
		static_assertions-1.1.0 \
		subtle-2.4.1 \
		syn-1.0.107 \
		syn-mid-0.5.3 \
		synstructure-0.12.6 \
		sysinfo-0.28.0 \
		tempfile-3.3.0 \
		termcolor-1.2.0 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		tokio-1.25.0 \
		toml_datetime-0.5.1 \
		toml_edit-0.18.1 \
		typenum-1.16.0 \
		unicode-bidi-0.3.10 \
		unicode-ident-1.0.6 \
		unicode-normalization-0.1.22 \
		unicode-xid-0.2.4 \
		untrusted-0.7.1 \
		ureq-2.6.2 \
		url-2.3.1 \
		version_check-0.9.4 \
		walkdir-2.3.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.84 \
		wasm-bindgen-backend-0.2.84 \
		wasm-bindgen-macro-0.2.84 \
		wasm-bindgen-macro-support-0.2.84 \
		wasm-bindgen-shared-0.2.84 \
		web-sys-0.3.61 \
		webpki-0.22.0 \
		webpki-roots-0.22.6 \
		which-4.4.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1 \
		x25519-dalek-1.2.0 \
		zeroize-1.3.0 \
		zeroize_derive-1.3.3

CARGO_BUILD_ARGS=	--features electron
CARGO_INSTALL=		no

USE_LDCONFIG=	yes

MAKE_ENV=	OUTPUT_DIR=${WEBRTCDIR}/out

PLIST_FILES=	lib/libringrtc.so

post-extract:
	${MKDIR} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/src/webrtc
	${MV} ${WRKDIR}/webrtc-${WEBRTC_REV} ${WEBRTCDIR}
	${MV} ${WRKDIR}/base ${WEBRTCDIR}
	${MV} ${WRKDIR}/build ${WEBRTCDIR}
	${MV} ${WRKDIR}/buildtools ${WEBRTCDIR}
	${MV} ${WRKDIR}/testing ${WEBRTCDIR}
	${MV} ${WRKDIR}/third_party ${WEBRTCDIR}
	${MV} ${WRKDIR}/catapult ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/boringssl ${WEBRTCDIR}/third_party/boringssl/src
	${MV} ${WRKDIR}/icu ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libjpeg_turbo ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libsrtp ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/libvpx ${WEBRTCDIR}/third_party/libvpx/source
	${MV} ${WRKDIR}/libyuv ${WEBRTCDIR}/third_party
	${MV} ${WRKDIR}/nasm ${WEBRTCDIR}/third_party

post-patch:
	${REINPLACE_CMD} "s|LOCALBASE|${LOCALBASE}|" \
		${WEBRTCDIR}/build/toolchain/gcc_toolchain.gni \
		${WEBRTCDIR}/buildtools/third_party/libc++/BUILD.gn

	${ECHO_CMD} "# Generated from 'DEPS'" > ${WEBRTCDIR}/build/config/gclient_args.gni
	${ECHO_CMD} 1591703586 > ${WEBRTCDIR}/build/util/LASTCHANGE.committime
	${ECHO_CMD} "qqchose " > ${WEBRTCDIR}/build/util/LASTCHANGE

pre-build:
	cd ${WEBRTCDIR} && \
		${SETENV} ${CONFIGURE_ENV} gn gen out/release --args='${GN_ARGS}'

# build webrtc first, ringrtc needs libwebrtc.a
	cd ${WEBRTCDIR} \
		&& ${MAKE_ENV} CC=ccache CXX=ccache ninja -C out/release

# it's not intended to be used outside of signal-desktop, put that in
# /usr/local/share/ringrtc instead?
do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/libringrtc.so \
		${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
