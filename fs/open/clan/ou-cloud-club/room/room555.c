inherit ROOM;
void create() {
	set( "short", "$HIY$蒼龍巢-防$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_pants",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_hands",
		"amount10" : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/firedancer/npc/eq/r_boots",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
	]) );
	set( "build", 10232 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room556.c",
		"up"        : "/open/clan/ou-cloud-club/room/room621",
		"north"     : "/open/clan/ou-cloud-club/room/room557.c",
		"south"     : "/open/clan/ou-cloud-club/room/room559.c",
		"east"      : "/open/clan/ou-cloud-club/room/room558.c",
	]) );
	set( "long", @LONG

    這是一間存放獅王防具及其它雜物的大房間，在獅穴中佔有很重要
的地位。房間中裝璜的非常漂亮，牆璧上一張蠻清楚的防具列表清單，
吸引了你的視線，上頭的ＰＯＰ字寫得很不錯。洶都十分的
乾淨。但因為是服物台的管理人員相當盡則，所以您存放的物品也都在
架上排列的非常整齊。

LONG);
	setup();
	replace_program(ROOM);
}
