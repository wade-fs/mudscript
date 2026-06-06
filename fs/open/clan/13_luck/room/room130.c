inherit ROOM;
void create() {
	set( "short", "狂風濤" );
	set( "owner", "mill" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file9"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10109 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room134.c",
		"north"     : "/open/clan/13_luck/room/room232",
	]) );
	set( "long", @LONG

    風呼呼的吹，卻留不下一點痕跡，但是風真的有在動，我們卻看不見
它，難道就這樣任他四處流動嗎，不，有個成功的留下了風，也留下了他
最輝煌的人生一頁，在今生，他會許了無遺憾，但在後人眼裡他已經學究
天人了，在這個人嘴裡常只聽著他說的一句話，風 ~追求快意中的冷靜。


LONG);
	setup();
	replace_program(ROOM);
}
