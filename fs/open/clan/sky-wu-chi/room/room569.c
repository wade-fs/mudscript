inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下六樓" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_finger",
		"file5"    : "/open/firedancer/npc/eq/r_pants",
		"file8"    : "/open/firedancer/npc/eq/r_hands",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_boots",
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount6"  : 1,
		"file4"    : "/open/tendo/obj/chaosbelt",
		"file10"   : "/open/wu/obj/figring",
		"amount10" : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file9"    : "/open/wu/npc/obj/armband",
		"amount2"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
	]) );
	set( "owner", "giga" );
	set( "build", 12751 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room570.c",
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
