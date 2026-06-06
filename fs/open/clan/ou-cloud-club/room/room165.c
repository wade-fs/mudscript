inherit ROOM;
void create() {
	set( "short", "夢幻閣" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room406",
		"south"     : "/open/clan/ou-cloud-club/room/room416.c",
	]) );
	set( "owner", "ads" );
	set( "light_up", 1 );
	set( "build", 76 );
	set( "object", ([
		"amount6"  : 1,
		"file8"    : "/open/dancer/obj/maple_ribbon",
		"file5"    : "/open/prayer/obj/boris-hands",
		"amount4"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/prayer/obj/boris-hat",
		"file3"    : "/open/prayer/obj/boris-cloth",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/open/dancer/obj/yuaboots",
	]) );
	set( "long", @LONG

                  夢幻閣      

      這裡是夜夢小築的大殿《夢幻閣》，這裡是幻魔
  弟子們平常學習舞蹈、武術的地方，建築得美侖美煥，
  美麗的建築再加上舞者們優美的舞蹈，真是會令人以為
  身處幻境。

LONG);
	setup();
	replace_program(ROOM);
}
