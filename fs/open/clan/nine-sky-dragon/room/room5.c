inherit ROOM;
void create() {
	set( "short", "殺氣房" );
	set( "owner", "haoman" );
	set( "object", ([
		"amount1"  : 48,
		"amount3"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/obj/gift/xisuidan",
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 8,
		"amount5"  : 37,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 9,
		"amount2"  : 1,
	]) );
	set( "build", 10086 );
	set( "exits", ([
		"up"        : "/open/clan/nine-sky-dragon/room/room2.c",
		"enter"     : "/open/clan/nine-sky-dragon/room/room4.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    在今日的fs,變態玩家層出不窮,連要賺個殺氣都有點困難,也因為如此
都想找殺手幫忙自己提升殺氣,所以殺手玩家變成每位玩家要打變態npc前的尋找
對象,wiz有鑑於此特地開放了一隻npc,用來提供玩家打些特定物品來換取你所需
要的殺氣,此處就存放著可以換取殺氣的物.
LONG);
	setup();
	replace_program(ROOM);
}
