inherit ROOM;
void create() {
	set( "short", "回春堂" );
	set( "owner", "rue" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/doctor/pill/ice_pill",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/doctor/pill/gnd_pill",
		"file6"    : "/open/quests/snake/npc/obj/snake-3",
		"file10"   : "/obj/stone/suipian",
		"amount9"  : 1,
		"amount8"  : 41,
		"amount10" : 4,
		"amount5"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"file1"    : "/open/doctor/pill/human_pill",
		"file8"    : "/open/doctor/pill/taii_pill",
		"amount1"  : 54,
		"amount7"  : 627,
		"amount3"  : 42,
		"amount6"  : 1,
	]) );
	set( "build", 10452 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room148",
		"east"      : "/open/clan/sky-wu-chi/room/room308.c",
		"north"     : "/open/clan/sky-wu-chi/room/room268.c",
	]) );
	set( "long", @LONG
遠遠地便瞧見門首上燙金的「妙手回春」四個大字，進
得門來諸多匾額「仁心仁術」、「華陀再世」等語把東邊的
牆壁妝點得如匾額之海；西邊是藥局，櫃檯後邊整排格子屜
櫃標著茯苓、人蔘、燕窩、川芎等等各式藥材，藥香四溢使
你精神抖擻起來。
LONG);
	setup();
	replace_program(ROOM);
}
