inherit ROOM;
void create() {
	set( "short", "武具防具廳" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
	]) );
	set( "build", 10233 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room282.c",
		"east"      : "/open/clan/13_luck/room/room306.c",
		"west"      : "/open/clan/13_luck/room/room301",
		"out"       : "/open/clan/13_luck/room/room5.c",
	]) );
	set( "long", @LONG

    整層放著，防具跟武具，有著各式各樣的武具跟防具，強如風舞揚
。任正晴。郭襄....等，也逃不過吉祥高手的圍剿，所以為新進弟子成
立的eq。wp室，希望能有一天..

               今日你以十三為榮，明日十三以你為榮
　　　　　　
     WEST ＝ 武器室    SOUTH ＝ 照明室    防具室 ＝ EAST

LONG);
	setup();
	replace_program(ROOM);
}
