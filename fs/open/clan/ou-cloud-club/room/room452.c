inherit ROOM;
void create() {
	set( "short", "$HIR$煉丹房-丸 3$NOR$" );
	set( "object", ([
		"amount1"  : 600,
		"amount3"  : 283,
		"file6"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/ping/obj/poison_pill",
		"amount2"  : 338,
		"file9"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/obj/gift/shenliwan",
		"amount10" : 141,
		"file7"    : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room11",
	]) );
	set( "owner", "taa" );
	set( "build", 10297 );
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
