inherit ROOM;
void create() {
	set( "short", "青龍舞天" );
	set( "owner", "mad" );
	set( "object", ([
		"amount7"  : 38,
		"amount2"  : 1,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/daemon/class/blademan/obj/ublade",
		"amount4"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file3"    : "/open/doctor/pill/f_pill",
		"amount3"  : 29,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 8,
		"amount5"  : 3,
		"amount1"  : 1,
		"file10"   : "/open/wu/npc/obj/armband",
	]) );
	set( "build", 15238 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room20.c",
		"up"        : "/open/clan/13_luck/room/room22",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在爬了一段時間，終於看到了終點就在不遠處，你興奮的不管四周
的美景，二話不說的向前直衝，一步當兩步的跑著，四周全佈滿了白雲
，整個人就好像漂浮在空中，心中有說不出的快樂，期待的一看十三吉
祥的行政中樞。

LONG);
	setup();
	replace_program(ROOM);
}
