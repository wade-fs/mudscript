inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房-丸 4$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"file4"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file3"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"file10"   : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount7"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"file7"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10172 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room11.c",
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
