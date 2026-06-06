inherit ROOM;
void create() {
	set( "short", "皇城大道" );
	set( "build", 10010 );
	set( "object", ([
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room428",
		"south"     : "/open/clan/13_luck/room/room7.c",
		"north"     : "/open/clan/13_luck/room/room8.c",
		"east"      : "/open/clan/13_luck/room/room429.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是十三吉祥的大本營--皇城，放眼望去盡是深宮穹樓，一股莊
嚴的氣氛籠罩著整個皇城，使你望之卻步，腳下石版上刻著面龍騰鳳舞
之浮雕，乃十三吉祥花費無數人力所鑿造而成，非幫中之人，一但踏入
皇城之中再難回頭, 只有落的喪生殘體之下場...

LONG);
	setup();
	replace_program(ROOM);
}
