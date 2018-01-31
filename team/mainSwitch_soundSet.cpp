#include "stdafx.h"
#include "mainSwitch.h"


void mainSwitch::soundSetting()
{
	SOUNDMANAGER->addSound("01.arrow", "sound/01.arrow.wav", false, false);
	SOUNDMANAGER->addSound("02.rupee", "sound/02.rupee.wav", false, false);
	SOUNDMANAGER->addSound("03.cursor", "sound/03.cursor.wav", false, false);
	SOUNDMANAGER->addSound("04.link attack", "sound/04.link attack.wav", false, false);
	SOUNDMANAGER->addSound("05.link spin", "sound/05.link spin.wav", false, false);
	SOUNDMANAGER->addSound("06.link hurt", "sound/06.link hurt.wav", false, false);
	SOUNDMANAGER->addSound("07.link dies", "sound/07.link dies.wav", false, false);
	SOUNDMANAGER->addSound("08.kakariko village", "sound/08.kakariko village.mp3", true, true);
	SOUNDMANAGER->addSound("09.dark world", "sound/09.dark world.mp3", true, true);
	SOUNDMANAGER->addSound("10.battle with ganon", "sound/09.dark world.mp3", true, true);
	SOUNDMANAGER->addSound("11.item get", "sound/11.item get.wav", true, false);







}