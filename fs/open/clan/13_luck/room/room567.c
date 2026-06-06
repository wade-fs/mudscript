inherit ROOM;
void create() {
	set( "short", "清幽小徑" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount10" : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room566",
		"up"        : "/open/clan/13_luck/room/room569.c",
	]) );
	set( "long", @LONG
你順著花香走到了這裡，只見黃花滿地，白柳橫坡。石中清流
滴滴，籬落飄香；樹頭紅葉翩翩，疏林如畫。先前在練武場的喧鬧
聲竟像被花香所阻隔一般，在這裡完全沒有任何的雜聲，只有小橋
、流水、清風、花香，宛如世外桃源。
LONG);
	setup();
	replace_program(ROOM);
}
