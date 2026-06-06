inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIY$寶$YEL$甲$HIW$藏$NOR$" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/wu/obj/armband",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/open/wu/obj/figring",
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"file1"    : "/open/tendo/obj/chaosbelt",
		"amount9"  : 1,
	]) );
	set( "owner", "left" );
	set( "build", 10079 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room185",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

$HIC$  ╭═══╮    ║$HIW$        ║         $HIB$  ║       ║    $HIW$ ═╩═ ╭═╦═╯
$HIC$╭╯═══╰╮  ║$HIW$╭═══╬═══╮ $HIB$═╩╮ ╭═╬═╮$HIW$  ══  ══╬══
$HIC$║ ╔╗╔╗ ║║║$HIW$║      ║      ║ $HIB$╭╦╯ ╠═╬═║$HIW$  ══      ║    
$HBBLU$$HIC$╯ ╚╝╚╝ ╰║║$HIW$║      ║      ║ $HIB$║║║ ║  ║  ║$HIW$╭══╮╭═╩═╮$NOR$
$HBBLU$$HIC$ ╭╯╮╭╯╮   ║$HIW$╰═══╬═══╯ $HIB$╯║╰ ╰═╬═╯$HIW$║    ║║      ║$NOR$
$HBBLU$$HIC$ ╯  ╰╯  ╰ ╰╯$HIW$        ║         $HIB$  ╯       ╯    $HIW$╰══╯╰═══╯$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
