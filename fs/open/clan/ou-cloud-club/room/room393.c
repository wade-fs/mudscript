inherit ROOM;
void create() {
	set( "short", "$MAG$--虹晶紫裙--$NOR$" );
	set( "light_up", 1 );
	set( "build", 12495 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room394",
	]) );
	set( "long", @LONG
紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙虹晶紫裙
LONG);
	setup();
	replace_program(ROOM);
}
