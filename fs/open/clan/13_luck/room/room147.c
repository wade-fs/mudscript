inherit ROOM;
void create() {
	set( "short", "小志修練區" );
	set( "owner", "roar" );
	set( "object", ([
		"amount4"  : 122,
		"file3"    : "/obj/stone/suipian",
		"amount1"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/stone/powder",
		"file6"    : "/open/ping/obj/cloud",
		"amount6"  : 1,
		"file2"    : "/open/killer/memory/static",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 9,
		"file7"    : "/obj/stone/jiao",
		"amount3"  : 10,
		"amount5"  : 1,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/killer/memory/static",
	]) );
	set( "light_up", 1 );
	set( "build", 10001 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room113.c",
	]) );
	set( "long", @LONG

    這裡到處佈滿了殺氣，在空氣中又帶著劍氣，感覺
就好像到了一處劍士的修練區，在遠處有一道高大的人
影，仔細一看原來是小志在那裡休息，原來這裡是小志
的練功區和休息區。

LONG);
	setup();
	replace_program(ROOM);
}
