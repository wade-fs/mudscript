inherit ROOM;
void create() {
	set( "short", "$HIC$明日水行陣$NOR$" );
	set( "object", ([
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10114 );
	set( "owner", "tomorrow" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room740",
		"south"     : "/open/clan/13_luck/room/room738",
	]) );
	set( "long", @LONG
這裡是tomorrow所排設的五行陣之一  水行陣
眼前汪洋一片  四周看不到陸地  自己也只站在一塊大石上
一陣強風吹來  捲起千層浪  向你席捲過來
 你只能死命的抱著大石  祈禱大浪不會將自己吞噬
這裡是tomorrow所排設的五行陣之一  水行陣
眼前汪洋一片  四周看不到陸地  自己也只站在一塊大石上
一陣強風吹來  捲起千層浪  向你席捲過來
 你只能死命的抱著大石  祈禱大浪不會將自己吞噬

LONG);
	setup();
	replace_program(ROOM);
}
