inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房-丸 2$NOR$" );
	set( "owner", "taa" );
	set( "object", ([
		"file1"    : "/open/ping/obj/poison_pill",
		"amount6"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"amount7"  : 97,
		"file10"   : "/open/mogi/castle/obj/seven2-dark-head",
		"file2"    : "/open/killer/obj/fire-knife",
		"amount2"  : 1,
		"amount4"  : 97,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 1,
		"amount10" : 1,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 73,
		"file5"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount1"  : 142,
		"file3"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
	]) );
	set( "build", 10018 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room11",
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
