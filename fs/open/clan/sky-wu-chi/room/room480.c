inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下一樓" );
	set( "owner", "icegirl" );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10057 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room401",
		"down"      : "/open/clan/sky-wu-chi/room/room565.c",
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
