inherit ROOM;
void create() {
	set( "short", "$HIR$波-聊天室(9)$NOR$" );
	set( "owner", "perth" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room137",
		"north"     : "/open/clan/ou-cloud-club/room/room386",
	]) );
	set( "object", ([
		"amount2"  : 1,
		"file9"    : "/open/quests/snake/npc/obj/snake_gem",
		"file6"    : "/open/tendo/obj/chaosbelt",
		"amount3"  : 1,
		"file4"    : "/open/quests/snake/npc/obj/snake-3",
		"amount10" : 20,
		"file8"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/gsword/obj/dragon-sword",
		"amount8"  : 405,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file5"    : "/open/quests/snake/npc/obj/snake-3",
		"amount6"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount7"  : 1,
		"file2"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
	]) );
	set( "build", 12295 );
	set( "long", @LONG
進入  情色  聊天室     歡迎進入  情色  聊天室
歡迎進入  情色  聊天室     歡迎進入  情色  聊天室
歡迎進入  情色  聊天室     歡迎進入  情色  聊天室
歡迎進入  情色  聊天室     歡迎進入  情色  聊天室
歡迎進入  情色  聊天室     歡迎進入  情色  聊天室
歡迎進入  情色  聊天室     歡迎進入  情色  聊天室

LONG);
	setup();
	replace_program(ROOM);
}
