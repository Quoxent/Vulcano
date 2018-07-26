
Debian
====================
This directory contains files used to package vulcanod/vulcano-qt
for Debian-based Linux systems. If you compile vulcanod/vulcano-qt yourself, there are some useful files here.

## vulcano: URI support ##


vulcano-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install vulcano-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your vulcanoqt binary to `/usr/bin`
and the `../../share/pixmaps/vulcano128.png` to `/usr/share/pixmaps`

vulcano-qt.protocol (KDE)

