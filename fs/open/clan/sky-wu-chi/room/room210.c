inherit ROOM;
void create() {
	set( "short", "$HIW$高級練武場$HIW$" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount1"  : 1,
		"file6"    : "/open/ping/obj/cloud_fan",
		"amount8"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount3"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/capital/obj/blade2",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
	]) );
	set( "build", 10061 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room121",
		"south"     : "/open/clan/sky-wu-chi/room/room176.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
       這裡到處佈滿了殺氣，在空氣中又帶著劍氣，感覺
   就好像到了一處劍士的修練區，在遠處有一道高大的人
   影，仔細一看原來是小志在那裡休息，原來這裡是小志
   的練功區和休息區。

LONG);
	setup();
	replace_program(ROOM);
}
