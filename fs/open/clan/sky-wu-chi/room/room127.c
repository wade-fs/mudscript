inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$藏刀門$NOR$" );
	set( "light_up", 1 );
	set( "build", 10787 );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/capital/obj/blade2",
		"amount8"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mogi/dragon/obj/sunblade",
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room72.c",
		"west"      : "/open/clan/sky-wu-chi/room/room131",
	]) );
	set( "long", @LONG
這裡是夜空下的欣之藏刀房...只見為首的麒麟神刀(sun_moon blade) 閃閃發亮
一支支麒麟神刀井然有序的排列在牆上,同時..............麒麟神刀
所發出來的光芒也使你的眼睛頓時陷入一片金黃色的光芒...........
而深埋底地下的邪刀也使你感覺到陣陣得邪氣直撲而來.................


你死了
LONG);
	setup();
	replace_program(ROOM);
}
