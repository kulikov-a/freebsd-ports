--- ui/ozone/platform/wayland/host/wayland_toplevel_window.cc.orig	2023-03-10 11:01:21 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.cc
@@ -446,7 +446,7 @@ void WaylandToplevelWindow::HandleAuraToplevelConfigur
   const bool did_active_change = is_active_ != window_states.is_activated;
   is_active_ = window_states.is_activated;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // The tiled state affects the window geometry, so apply it here.
   if (window_states.tiled_edges != tiled_state_) {
     // This configure changes the decoration insets.  We should adjust the
