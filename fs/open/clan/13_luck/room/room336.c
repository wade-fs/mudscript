inherit ROOM;
void create() {
	set( "short", "迷霧之道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/obj/gift/shenliwan",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10653 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room335",
		"north"     : "/open/clan/13_luck/room/room337",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    陰風陣陣，送來了一團團的迷霧，使得路徑變得愈來愈迷糊。使
你突然驚嚇了一跳，你皺一皺眉頭，急忙的看清楚了道路，急急忙忙
的往正確的路途衝去。神風之真是讓人感覺得又奇又神祕的地方，你
一時也不明白其中的秘奧所在，此時厚厚黑黑的雲層吹過來，壓得你
喘不過氣來，連忙運功自保。


LONG);
	setup();
	replace_program(ROOM);
}
