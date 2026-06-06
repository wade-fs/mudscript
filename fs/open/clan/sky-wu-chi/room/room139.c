inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $HIG$前庭$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"amount3"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/open/capital/guard/gring",
		"file3"    : "/open/ping/obj/cloud_fan",
		"file8"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/ping/obj/cloud_fan",
		"file1"    : "/open/ping/obj/cloud_fan",
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"file10"   : "/open/ping/obj/cloud_fan",
		"amount1"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file4"    : "/open/capital/room/king/obj/dagger1",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10029 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room165.c",
		"west"      : "/open/clan/sky-wu-chi/room/room44.c",
		"out"       : "/open/clan/sky-wu-chi/room/room141.c",
		"north"     : "/open/clan/sky-wu-chi/room/room197",
	]) );
	set( "long", @LONG
走進書院前庭，兩條用紅磚鋪成的筆直大道朝前後及左右延伸而去，將前庭的
大草坪劃分成四塊區域，草坪上零零落落的放著幾件學生們忘了拿走的東西。在道
路兩旁，是一座座用石頭作成的小人像，每個人物的表情和面貌各有風采，看起來
好像都是在討論學問的樣子。朝北方過去可以走進書院的中庭，南邊是書院大門，
東西兩邊各有一棟建築物，似乎是學生讀書的地方。
LONG);
	setup();
	replace_program(ROOM);
}
