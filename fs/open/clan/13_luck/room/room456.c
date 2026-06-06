inherit ROOM;
void create() {
	set( "short", "『墨劍崖』" );
	set( "owner", "poll" );
	set( "object", ([
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10433 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room457",
		"south"     : "/open/clan/13_luck/room/room455",
	]) );
	set( "long", @LONG

     你正站在墨教總部的入口「墨劍崖」，首先印入眼簾的是那個如巨劍般
 聳立的岩石，那個象徵著墨教的標誌，看起非常宏偉，再往前看只見一排長
 不見尾的白石台階向山上延綿而去，宛如一條白色巨龍往上攀升一般。墨教
 建立幾來的基業，就是靠著這個固若金湯的堡壘。

LONG);
	setup();
	replace_program(ROOM);
}
