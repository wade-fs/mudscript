inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下十樓" );
	set( "object", ([
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
	]) );
	set( "owner", "giga" );
	set( "build", 11270 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room401.c",
		"down"      : "/open/clan/sky-wu-chi/room/room574.c",
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
