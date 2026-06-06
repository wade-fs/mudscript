inherit ROOM;
void create() {
	set( "short", "天洞 - 地下八樓" );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "owner", "giga" );
	set( "build", 11846 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room582.c",
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
