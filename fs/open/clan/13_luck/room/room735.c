inherit ROOM;
void create() {
	set( "short", "明日武器室" );
	set( "object", ([
		"file7"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file2"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file6"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 96,
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount2"  : 1,
	]) );
	set( "build", 10035 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room736",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是武器室  牆上掛滿了各式各樣的武器  刀劍自然不能少
仔細一瞧  東西還真不少  刀  劍  彩帶  扇  爪  嗯  這不是五
色靈器嗎  用來開啟聚靈道的物品原來tomorrow為了挑戰聚靈莊主  
早已收集了五色靈器  看來離決戰之日已不遠矣


LONG);
	setup();
	replace_program(ROOM);
}
