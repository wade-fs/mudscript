inherit ROOM;
void create() {
	set( "short", "廖淫府" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 40,
		"amount4"  : 1,
		"amount9"  : 28,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/magic-sign",
		"file10"   : "/u/a/acky/obj/gps",
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"amount5"  : 74558,
		"amount1"  : 1,
		"amount8"  : 90000,
		"file3"    : "/open/killer/obj/bellstar",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"amount2"  : 1,
		"file5"    : "/open/killer/obj/hate_knife",
		"file8"    : "/open/killer/obj/hate_knife",
		"amount10" : 1,
		"file9"    : "/open/killer/obj/s_pill",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10139 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room105",
		"east"      : "/open/clan/13_luck/room/room83",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
一踏進這，即看見一塊木製牌匾，上頭寫著斗大
的七個字「　廖　官　人　淫　行　天　下　」，在
往裡面看去，你見到廖官人正脫光衣服，在和一群醜
女大玩SM遊戲，真是變態，心想狂想竟有如此變態之
人，還是趕快離開此地的好，免的被他纏上。
LONG);
	setup();
	replace_program(ROOM);
}
