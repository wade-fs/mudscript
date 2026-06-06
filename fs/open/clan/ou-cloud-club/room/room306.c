inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$HIY$蛋$NOR$" );
	set( "object", ([
		"file2"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room210",
	]) );
	set( "owner", "del" );
	set( "light_up", 1 );
	set( "build", 10028 );
	set( "long", @LONG
穿過小徑，踏上幾層石梯，眼前突然開闊起來，在你的
正前方是一棟樸實卻又讓人安心的木屋，屋旁的水車伴著陣
陣流水聲，左手邊有一塊約莫兩個人高的石碑，刻著火紅色
的兩個字『劍邪』，好奇的你再定神一看，赫然發現劍邪二
字的走勢竟就像一套變化萬千的劍法，你不禁對這裡的主人
是誰產生莫大的興趣。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
