inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下八樓" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/wu/obj/ya-head",
		"amount7"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/wu/obj/ya-head",
		"file4"    : "/open/wu/obj/ya-head",
		"file5"    : "/open/wu/obj/ya-head",
		"file2"    : "/open/wu/obj/ya-head",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/wu/obj/ya-head",
		"amount9"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/wu/obj/ya-head",
		"amount2"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "owner", "giga" );
	set( "build", 12035 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room572.c",
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
