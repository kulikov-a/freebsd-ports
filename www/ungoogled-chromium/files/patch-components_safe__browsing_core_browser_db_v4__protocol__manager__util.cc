--- components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2022-10-01 07:40:07 UTC
+++ components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -113,7 +113,7 @@ std::ostream& operator<<(std::ostream& os, const ListI
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
