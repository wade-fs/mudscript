inherit ROOM;
void create() {
	set( "short", "練氣房" );
	set( "owner", "roar" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount2"  : 1,
	]) );
	set( "build", 10029 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room397",
	]) );
	set( "long", @LONG

    這裡是給十三拳堂弟子練武的地方，牆上所刻之武學更是上層的內功
心法。因為拳十三教導弟子們的第一課就是練武之道並不在於外在的強猛
，更要修練自己本身的內力，使自己的外在武功能夠配合內在的內勁，方
能發揮拳之奧義。

LONG);
	setup();
	replace_program(ROOM);
}
