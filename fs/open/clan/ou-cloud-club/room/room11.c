inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房-丸$NOR$" );
	set( "owner", "taa" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 340,
		"amount6"  : 105,
		"amount10" : 1,
		"file8"    : "/open/common/obj/liz_meat",
		"file7"    : "/open/fire-hole/obj/p-pill",
		"amount9"  : 1,
		"file9"    : "/open/common/obj/liz_meat",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/obj/gift/bingtang",
		"amount5"  : 242,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 249,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 487,
		"file6"    : "/open/killer/obj/atman_pill",
		"amount8"  : 1,
		"amount4"  : 132,
		"amount7"  : 104,
	]) );
	set( "build", 10215 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room225.c",
		"up"        : "/open/clan/ou-cloud-club/room/room624",
		"south"     : "/open/clan/ou-cloud-club/room/room452.c",
		"north"     : "/open/clan/ou-cloud-club/room/room213.c",
		"east"      : "/open/clan/ou-cloud-club/room/room234.c",
	]) );
	set( "long", @LONG

    這是一間存放獅王丹藥及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的丹藥列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
	replace_program(ROOM);
}
