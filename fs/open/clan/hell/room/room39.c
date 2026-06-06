inherit ROOM;
void create() {
	set( "short", "$HIY$珠光寶氣$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/killer/obj/kill_yar_head",
		"file2"    : "/open/killer/obj/kill_yar_head",
		"amount8"  : 1,
		"file6"    : "/open/killer/obj/kill_yar_head",
		"file3"    : "/open/killer/obj/kill_yar_head",
		"amount6"  : 1,
		"file1"    : "/open/killer/obj/kill_yar_head",
		"amount7"  : 1,
		"file8"    : "/open/killer/obj/kill_yar_head",
	]) );
	set( "build", 10594 );
	set( "light_up", 1 );
	set( "exits", ([
		"gold"      : "/open/clan/hell/room/room64",
		"green"     : "/open/clan/hell/room/room17.c",
		"out"       : "/open/clan/hell/room/room28.c",
		"blue"      : "/open/clan/hell/room/room11.c",
		"red"       : "/open/clan/hell/room/room66.c",
	]) );
	set( "long", @LONG
一踏入這間房間,發現牆壁上四處都鑲著各種顏色的寶石,仔細一看,原
來都是有神奇能力的戒指上面所鑲的寶石,有$HIG$綠色$NOR$的殺意魔戒,$HIC$藍色$NOR$的冰雪神
戒,$HIR$紅色$NOR$的紅寶石指戒,當然還有$HIY$金色$NOR$的護衛戒指,這裡有不同的門,分別通
往存放不同戒指的地方.

LONG);
	setup();
	replace_program(ROOM);
}
