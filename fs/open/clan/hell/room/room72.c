inherit ROOM;
void create() {
	set( "short", "$MAG$神丹$NOR$區" );
	set( "object", ([
		"file1"    : "/open/doctor/pill/sky_pill",
		"amount3"  : 50,
		"amount2"  : 231,
		"file2"    : "/open/doctor/pill/gnd_pill",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount4"  : 200,
		"file5"    : "/open/doctor/pill/ice_pill",
		"file4"    : "/open/doctor/pill/human_pill",
		"amount1"  : 231,
		"amount5"  : 289,
	]) );
	set( "owner", "blur" );
	set( "build", 10047 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

hmm..神丹...不是那個加阿里不答的dan
是在你快去見白伯伯,能救你一命的仙丹...
在這人心險惡,狗咬狗的大染缸裡...
行走江湖時最好隨身攜帶幾顆....
以備不時之需...
不過此丹不易取得...所以服用時要特別謹慎...
若能以如履薄冰的心態服用它的話...效果更加喔...

LONG);
	setup();
	replace_program(ROOM);
}
