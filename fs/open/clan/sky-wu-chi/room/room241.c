inherit ROOM;
void create() {
	set( "short", "寒霜居" );
	set( "owner", "roboo" );
	set( "object", ([
		"file1"    : "/obj/example/besttea",
		"amount1"  : 1,
	]) );
	set( "build", 10635 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room359.c",
		"north"     : "/open/clan/sky-wu-chi/room/room358",
		"west"      : "/open/clan/sky-wu-chi/room/room360.c",
	]) );
	set( "long", @LONG
當你走進這房間的時候，突然被一陣強光照射的無法睜開眼睛
等你適應了這陣強光之後，才發覺原來這強光的來源是源自於
這房間牆壁上的水晶。你仔細一看這房間幾乎都是由十種不同
顏色的水晶所構成的，難道這牆上的水晶就是傳說中記載武林
絕學《渾天心法》口訣的十色水晶嗎！想必這房間的主人必定
是位再世高人啊~~~.

LONG);
	setup();
	replace_program(ROOM);
}
