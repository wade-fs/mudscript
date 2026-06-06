inherit ROOM;
void create() {
	set( "short", "武神居龍鱗房" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount10" : 1,
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/dragon-head",
		"file1"    : "/open/mogi/dragon/obj/dragon-head",
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10020 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room680",
		"west"      : "/open/clan/13_luck/room/room483",
	]) );
	set( "long", @LONG

    傳說中魔界之神黃金甲龍，兇猛無比，且常出沒傷人
。武神曾多次斬殺甲龍，獲得身上珍貴的龍鱗。據說龍鱗
有神奇的功用，可從任何地方瞬間移動到魔界，故收藏於
此，等到有用到的時後，可以及時取出使用，救人或進入
魔界除妖。

LONG);
	setup();
	replace_program(ROOM);
}
