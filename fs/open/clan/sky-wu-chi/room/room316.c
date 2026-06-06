inherit ROOM;
void create() {
	set( "short", "cloak" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
	]) );
	set( "build", 10123 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room36.c",
		"east"      : "/open/clan/sky-wu-chi/room/room342",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room330.c",
	]) );
	set( "long", @LONG

水水水水水水水水水水水水水水水水水水水水水水水水
水水水水水水水水水水水水水水水水水水水水水水水水
水水水水水水水水水水喝喝水水水水水水水水水水水水   
水水水水水水水水水水喝喝水水水水水水水水水水水水   
水水水水水水水水水水喝喝水水水水水水水水水水水水   
水水水水水水水水水水喝喝水水水水水喝喝水水水水水
水水水水水水水水水水喝喝水水水水喝喝喝水水水水水
水水喝喝喝喝喝喝喝喝喝喝水水喝喝喝水水水水水水水     多
水水喝喝喝喝喝喝喝喝喝喝喝喝喝水水水水水水水水水     喝
水水水水水水水水喝喝喝喝喝喝水水水水水水水水水水     水
水水水水水水水喝喝喝喝喝喝喝水水水水水水水水水水     沒
水水水水水水水喝喝水喝喝水喝喝水水水水水水水水水     事
水水水水水水喝喝水水喝喝水水喝喝水水水水水水水水
水水水水水水喝喝水水喝喝水水水喝喝水水水水水水水
水水水水水喝喝水水水喝喝水水水喝喝喝水水水水水水
水水水水水喝喝水水水喝喝水水水水喝喝喝喝水水水水
水水水水喝喝水水水水喝喝水水水水喝喝喝喝喝水水水          沒
水水水喝喝水水水水水喝喝水水水水水喝喝喝喝喝水水          事
水水喝喝水水水水水水喝喝水水水水水水喝喝水水水水          多
水水水水水水水水喝喝喝喝水水水水水水水水水水水水          喝
水水水水水水水水水喝喝喝水水水水水水水水水水水水          水
水水水水水水水水水水喝水水水水水水水水水水水水水
水水水水水水水水水水水水水水水水水水水水水水水水
水水水水水水水水水水水水水水水水水水水水水水水水


LONG);
	setup();
	replace_program(ROOM);
}
