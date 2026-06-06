inherit ROOM;
void create() {
	set( "short", "青龍殿迴廊" );
	set( "owner", "mad" );
	set( "object", ([
		"amount2"  : 1,
		"file7"    : "/open/common/obj/liz_meat",
		"amount8"  : 1,
		"amount10" : 22,
		"file1"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount9"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"file5"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file6"    : "/open/gsword/obj/dragon-cloth",
		"amount5"  : 1,
	]) );
	set( "build", 10087 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room15.c",
		"west"      : "/open/clan/13_luck/room/room697",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    剛踏足此處便有一種陰森可怕的感覺襲來，人生來便俱有第六感，
就在此時你的第六感告訴你﹒﹒﹒﹒。或許你覺得只是第六感作祟，但
相信這種感覺吧！除非你身具高超武學或者你不怕死。在往東方走去就
是鼎鼎有名的『朱雀堂』。

LONG);
	setup();
	replace_program(ROOM);
}
