inherit ROOM;
void create() {
	set( "short", "星月殿" );
	set( "owner", "mill" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room497",
		"north"     : "/open/clan/13_luck/room/room534.c",
	]) );
	set( "long", @LONG

　　『　星　月　殿　』三個斗大的燙金字體出現在你眼前，往前望
去，只見殿內雕刻玲瓏，器宇非凡，金壁輝煌，而殿內四根石柱上分
別雕刻著青龍、朱雀、白虎、玄武四神獸，象徵著雄霸四方。整座宮
殿非常氣派，不愧是為富貴乞丐～百煉生的住所。

LONG);
	setup();
	replace_program(ROOM);
}
