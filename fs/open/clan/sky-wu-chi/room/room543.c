inherit ROOM;
void create() {
	set( "short", "ddt兵器庫" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file5"    : "/open/capital/obj/4-3",
		"file3"    : "/open/capital/obj/4-3",
		"file4"    : "/open/capital/obj/4-3",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/capital/obj/4-3",
		"file6"    : "/open/capital/obj/4-3",
		"amount2"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10038 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room512.c",
		"north"     : "/open/clan/sky-wu-chi/room/room561",
	]) );
	set( "long", @LONG
這是Ddt四處搜尋兵器回來存放的地方,牆上掛滿著兵器
因為Ddt是刀客,房間中掛的都是魔刀「不應」也是很合理的
你四處看看四周似乎真的只有刀子沒有其他好康A的東西...
於是你歪著頭坐下來思考著,難道今天就此空手而歸!?
LONG);
	setup();
	replace_program(ROOM);
}
