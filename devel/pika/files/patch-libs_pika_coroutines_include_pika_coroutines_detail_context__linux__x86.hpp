--- libs/pika/coroutines/include/pika/coroutines/detail/context_linux_x86.hpp.orig	2023-03-08 10:50:55 UTC
+++ libs/pika/coroutines/include/pika/coroutines/detail/context_linux_x86.hpp
@@ -12,7 +12,7 @@
 
 #pragma once
 
-#if defined(__linux) || defined(linux) || defined(__linux__)
+#if defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)
 
 # include <pika/config.hpp>
 # include <pika/assert.hpp>
