inherit ROOM;
void create() {
	set( "short", "皇城大道" );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file4"    : "/open/magic-manor/obj/fon-sky-sword",
		"file3"    : "/open/mogi/dragon/obj/power",
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
	]) );
	set( "build", 10013 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/hall.c",
		"east"      : "/open/clan/13_luck/room/room197.c",
		"north"     : "/open/clan/13_luck/room/room7.c",
		"west"      : "/open/clan/13_luck/room/room193",
	]) );
	set( "long", @LONG

    這裡是十三吉祥的大本營--皇城，放眼望去盡是深宮穹樓，一股莊
嚴的氣氛籠罩著整個皇城，使你望之卻步，腳下石版上刻著面龍騰鳳舞
之浮雕，乃十三吉祥花費無數人力所鑿造而成，非幫中之人，一但踏入
皇城之中再難回頭, 只有落的喪生殘體之下場...

LONG);
	setup();
	replace_program(ROOM);
}
