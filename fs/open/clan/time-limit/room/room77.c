inherit ROOM;
void create() {
	set( "short", "$BWHT$廠務部大樓$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount10" : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount9"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "owner", "kerr" );
	set( "build", 10173 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room21",
		"west"      : "/open/clan/time-limit/room/room76.c",
		"south"     : "/open/clan/time-limit/room/room80",
		"east"      : "/open/clan/time-limit/room/room75.c",
		"up"        : "/open/clan/time-limit/room/room22.c",
		"down"      : "/open/clan/time-limit/room/room23.c",
	]) );
	set( "long", @LONG
一入眼前竟是寬敞的中控平台, 一排排電腦不時輸出大量數據, 讓人眼花撩亂
兩旁為規劃整齊的會議室, 走道兩側為廠務人員辦公的辦公桌, 桌上潦亂不整
可見平時有多忙碌. 往左邊為純水控制室, 右邊為空調機房, 樓下為廢水控制
室, 樓上為電力機房.

LONG);
	setup();
	replace_program(ROOM);
}
