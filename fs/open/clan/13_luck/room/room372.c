inherit ROOM;
void create() {
	set( "short", "西側走道" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount2"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10275 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room393",
		"south"     : "/open/clan/13_luck/room/room371.c",
		"east"      : "/open/clan/13_luck/room/room373.c",
	]) );
	set( "long", @LONG

    由校場的西側連接下去的是十三吉祥四大分堂之一的刀堂所在地，傳
說現今江湖中的新興門派--霸刀門--的門主也是從此地脫離出去的，故其
中所傳的武功倒也不可小覷，走道之上有持刀的護衛來來去去的守護著，
而且他們的臉上均透露出一股刀者才有的霸氣及自信，若是再繼續往西走
下去就可以看到十三刀堂的大門了。往南的道路則通往四大分堂的『十三
拳堂』。

LONG);
	setup();
	replace_program(ROOM);
}
