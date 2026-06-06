inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房-丸 1$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file8"    : "/obj/gift/unknowdan",
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file10"   : "/obj/gift/hobowdan",
		"amount2"  : 732,
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount6"  : 817,
		"amount1"  : 137,
		"file5"    : "/obj/gift/xisuidan",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 1,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 251,
		"amount3"  : 937,
		"file4"    : "/open/fire-hole/obj/k-pill",
		"file7"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 10573 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room11",
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
