inherit ROOM;
void create() {
	set( "short", "$HIY$妖$HIW$幻$HIY$空間$NOR$" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/ghost-hole/obj/death-butterfly",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/ghost-hole/obj/death-butterfly",
		"amount9"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/living-water",
	]) );
	set( "build", 11310 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room162",
		"legging"   : "/open/clan/ou-cloud-club/room/room160",
		"claw"      : "/open/clan/ou-cloud-club/room/room157.c",
		"helmet"    : "/open/clan/ou-cloud-club/room/room204.c",
		"cloak"     : "/open/clan/ou-cloud-club/room/room161.c",
	]) );
	set( "long", @LONG
一股濃烈無以形容的味道襲向你，四周的空間變的詭異，不似是
正常的空間，這裏正是千年樹妖所製造出來的空間，平時的樹妖正是
處在此地，一向不喜歡人類的牠，最痛恨人類無故來打擾他平靜的生
活了，如果有人擅闖，將會被千年樹妖無情的攻擊。

LONG);
	setup();
	replace_program(ROOM);
}
