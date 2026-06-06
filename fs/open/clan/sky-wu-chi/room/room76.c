inherit ROOM;
void create() {
	set( "short", "兵器室" );
	set( "owner", "matrix" );
	set( "object", ([
		"file10"   : "/open/gsword/obj/may_ring",
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount8"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/daemon/class/fighter/figring",
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"file3"    : "/open/mogi/castle/obj/lochagem",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file6"    : "/open/tendo/obj/chaosbelt",
	]) );
	set( "build", 10125 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room367.c",
		"east"      : "/open/clan/sky-wu-chi/room/room267",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room96",
	]) );
	set( "long", @LONG
在這不大的密室之中, 擺了幾件無光澤的的兵器; 它們似乎並非金屬打造而成,

然卻堅硬勝於金鐵, 有的大而輕巧, 有的小巧而沉重, 這裏面的每一件兵器

, 皆另你感到驚異與讚嘆. 不知此處主人如何收籮到這些其異珍品.

LONG);
	setup();
	replace_program(ROOM);
}
