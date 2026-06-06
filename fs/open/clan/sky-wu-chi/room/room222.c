inherit ROOM;
void create() {
	set( "short", "$HIW$動物園$NOR$" );
	set( "owner", "timekiller" );
	set( "object", ([
		"amount5"  : 85,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"file5"    : "/open/killer/obj/s_pill",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room223",
	]) );
	set( "build", 10950 );
	set( "long", @LONG
哇！！這裡就是天道無極中的動物園了，嘿嘿～～想不到，
這裡竟然是免費的，不過，裡面的動物也太少隻了吧，
只看到幾隻小狗和小貓而已，拜託，動物園這麼簡陋怎麼行，
還是留幾顆$HIW$Diamond$NOR$下來當做基金吧，
這樣下次才會有更多的動物！！

LONG);
	setup();
	replace_program(ROOM);
}
