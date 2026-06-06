inherit ROOM;
void create() {
	set( "short", "寶庫" );
	set( "object", ([
		"amount7"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount9"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mon/obj/thousand-nectar",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 17,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room56",
		"west"      : "/open/clan/13_luck/room/room120.c",
		"north"     : "/open/clan/13_luck/room/room540.c",
	]) );
	set( "owner", "biob" );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "long", @LONG
建構中
還不知道要寫啥
所以慢慢等吧
看看我啥時候會想起來怎寫
不過可能很難
因為我敘述的創意不是很好
所以在這裡看不到有創意的房間敘述
如果要看到好的敘述你就來錯地方了
對了
以後看到小二別玩他的
皮卡邱
會被扁
謝謝
LONG);
	setup();
	replace_program(ROOM);
}
