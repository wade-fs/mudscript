inherit ROOM;
void create() {
	set( "short", "皮鞭研發中心" );
	set( "owner", "shooter" );
	set( "object", ([
		"file6"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"amount8"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file2"    : "/open/mon/obj/thousand-nectar",
		"file7"    : "/open/tendo/obj/luboot",
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount2"  : 179,
		"amount9"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
	]) );
	set( "build", 10200 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room425",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
哇.....好多皮鞭阿,仔細一看,原來這邊主要負責研發皮鞭
至於這些皮邊有何用途呢 ,主要是因為研究所所長常常騎馬,所
以需要一個良好的皮鞭來驅策馬匹,至於為何生產這麼多皮鞭呢
有沒有其他的用途??這裡的研究所所員就不願意透露了。

LONG);
	setup();
	replace_program(ROOM);
}
