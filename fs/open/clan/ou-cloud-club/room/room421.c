inherit ROOM;
void create() {
	set( "short", "實驗室專用倉庫" );
	set( "owner", "kanon" );
	set( "object", ([
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount5"  : 3384,
		"file2"    : "/obj/stone/jiao",
		"amount4"  : 478,
		"amount3"  : 50,
		"file4"    : "/obj/stone/powder",
		"file7"    : "/obj/stone/suipian",
		"amount9"  : 1,
		"file9"    : "/open/gblade/obj/dragon_book",
		"file6"    : "/open/ping/obj/linpo_book",
		"file8"    : "/open/capital/obj/book",
		"file1"    : "/open/mon/obj/mon-pill",
		"file10"   : "/u/p/pana/q/obj/lan-head",
		"amount7"  : 44,
		"amount8"  : 1,
		"amount10" : 1,
		"file5"    : "/open/killer/obj/atman_pill",
		"amount1"  : 4203,
		"amount2"  : 10,
		"amount6"  : 1,
	]) );
	set( "build", 10677 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room425",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡到處堆滿了各種器材, 看起來比研究中心更亂,你心想
這應該是這些實驗室的倉庫吧,地上堆了不少各研究室和實驗室
所需要的原料, 小心點別弄亂了這邊物品的排列,也別亂拿倉庫
的物品,不然倉庫的管理人可是會把你抓去阿魯巴的。

LONG);
	setup();
	replace_program(ROOM);
}
