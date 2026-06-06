inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下三樓" );
	set( "object", ([
		"amount8"  : 1,
		"file9"    : "/open/wu/obj/armband",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file7"    : "/open/dancer/obj/yuawaist",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "owner", "icegirl" );
	set( "build", 12038 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room567.c",
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
