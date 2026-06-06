inherit ROOM;
void create() {
	set( "short", "邪洞 - 地下二樓" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount4"  : 62,
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "owner", "giga" );
	set( "build", 11535 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room586.c",
		"out"       : "/open/clan/sky-wu-chi/room/room401",
		"fire"      : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
天魔混天亂舞之地。有著各式各樣的天魔石碑(fire)在旁邊，寫著許許多多
各極惡之魔當時獨霸天下時所做的風光偉業，說是風光偉業不如說是極大殺戮的
重大事遺；你可以再繼續看下去，但你可要保佑看完後你的項上人頭還在喔！
LONG);
	setup();
	replace_program(ROOM);
}
