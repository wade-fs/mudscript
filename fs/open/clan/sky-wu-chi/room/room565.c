inherit ROOM;
void create() {
	set( "short", "魔洞 - 地下二樓" );
	set( "owner", "icegirl" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"file2"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
	]) );
	set( "build", 12345 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room401",
		"down"      : "/open/clan/sky-wu-chi/room/room566.c",
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
