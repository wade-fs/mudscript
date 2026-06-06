inherit ROOM;
void create() {
	set( "short", "$HIR$地獄的詛咒$NOR$(choas belt & gem)" );
	set( "owner", "neun" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/tendo/obj/luboot",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 10,
		"file2"    : "/open/killer/obj/hate_knife",
		"file6"    : "/open/killer/obj/bellstar",
		"amount2"  : 287,
		"amount6"  : 8000,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 10,
	]) );
	set( "light_up", 1 );
	set( "build", 11791 );
	set( "exits", ([
		"dia"       : "/open/clan/hell/room/room29.c",
		"north"     : "/open/clan/hell/room/room23.c",
	]) );
	set( "long", @LONG
這裡是幫主專門存放一些奇怪物品的地方,有可能是解迷的重要關鍵,也有可
能是從各處收集來的人頭,所以這裡的磁場總是存在於不穩定的狀態中,當這裡存
放人頭的數目比較多的時候,經過這裡的人就會受到來自地獄的詛咒,就算是身在
地獄的各殿閻王也一樣不能倖免

LONG);
	setup();
	replace_program(ROOM);
}
