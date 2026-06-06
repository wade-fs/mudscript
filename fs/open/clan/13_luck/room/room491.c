inherit ROOM;
void create() {
	set( "short", "石階" );
	set( "owner", "evonne" );
	set( "object", ([
		"amount2"  : 47,
		"file2"    : "/open/fire-hole/obj/y-pill",
		"file10"   : "/open/killer/obj/atman_pill",
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 400,
		"amount1"  : 78,
		"file3"    : "/open/killer/obj/atman_pill",
		"amount8"  : 47,
		"file8"    : "/open/killer/obj/atman_pill",
		"amount5"  : 45,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 555,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount6"  : 15,
	]) );
	set( "build", 10074 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room492.c",
		"east"      : "/open/clan/13_luck/room/room366",
		"north"     : "/open/clan/13_luck/room/room85.c",
	]) );
	set( "long", @LONG

　　這是一條通往蝴蝶谷的階梯，入口處十分隱密，不仔細找的話還
難以發現。由於此階梯是鑿穿山壁所成，因此十分的昏暗，伸手不見
五指，階梯上更是長滿了綠苔，稍微不留神是很容易滑倒的。此處的
唯一光源便是那鑲在岩壁中價值連城的夜明珠。 

LONG);
	setup();
	replace_program(ROOM);
}
