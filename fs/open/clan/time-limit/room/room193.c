inherit ROOM;
void create() {
	set( "short", "$HIR$幫主$HIY$丹藥$HIM$房3$NOR$" );
	set( "owner", "auo" );
	set( "object", ([
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount3"  : 74,
		"file9"    : "/open/mogi/dragon/obj/key",
		"file3"    : "/open/mon/obj/thousand-nectar",
		"file2"    : "/open/ping/obj/poison_pill",
		"amount2"  : 100,
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/key",
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount1"  : 6,
	]) );
	set( "build", 10274 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room195",
	]) );
	set( "long", @LONG
六面不同顏色的藥櫃呈現在眼前,綠色櫃子存放綠龍精元,可以暫時增加刀法,藍色櫃
子存放藍龍精元,可以暫時增加內功,白色櫃子存放白龍精元,可以暫時擁有化劫的效
果,紫色櫃子存放毒龍精元,可以暫時增加法術和咒術,紅色櫃子存放紅龍精元,可以暫
時增加身法,黃色櫃子存放黃龍精元,可以暫時增加劍術和刺術

LONG);
	setup();
	replace_program(ROOM);
}
