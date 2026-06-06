inherit ROOM;
void create() {
	set( "short", "殿內大道一" );
	set( "object", ([
		"amount5"  : 100,
		"amount9"  : 100,
		"amount10" : 1024,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 1,
		"amount4"  : 100,
		"amount7"  : 100,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/ping/obj/poison_pill",
		"amount6"  : 100,
		"amount3"  : 1,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 100,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file3"    : "/open/quests/snake/npc/obj/snake_gem",
	]) );
	set( "owner", "roar" );
	set( "build", 10992 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room88.c",
		"north"     : "/open/clan/13_luck/room/room390",
	]) );
	set( "long", @LONG

    經過多次的廝殺依然無法見到浪子的真面目，心中有點灰心了，但抬
頭一看殿前大道，心中不知道有多高興，原來自己已經踏入前往浪子殿的
路途之中了。想了想就快要見到浪子了，而且已經走到這了，不如就繼續
往前走下去吧！！

LONG);
	setup();
	replace_program(ROOM);
}
