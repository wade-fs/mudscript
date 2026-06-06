inherit ROOM;
void create() {
	set( "short", "$HIB$惡霸$HIG$拳$HIW$場$NOR$" );
	set( "owner", "snowy" );
	set( "object", ([
		"file10"   : "/open/mon/obj/mon-pill",
		"amount10" : 190,
		"file9"    : "/open/magic-manor/obj/magic-sign",
		"amount8"  : 880,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 587,
		"amount5"  : 304,
		"file6"    : "/open/mon/obj/thousand-nectar",
		"amount7"  : 739,
		"amount3"  : 795,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 634,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 747,
		"file7"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 1,
		"amount6"  : 41,
	]) );
	set( "build", 10160 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room195",
	]) );
	set( "long", @LONG

$HIC$□惡霸掌

$HIW$    此掌由不詳的$CYN$武林高人$HIW$所創，所使用的招式頗為陰險，常常夾帶奇怪的功用，如：
$MAG$困住敵手，$BLU$吸取敵人功力，$RED$瘋狂連續攻擊$HIW$等，可以說是相當惡毒的掌法，也頗為難學。
$HIW$此種掌法必須要有相當的$HIR$殺氣$HIW$才能修練，而其許多的特殊功用必須要輔以$HIC$惡化魔功$HIW$方能
$HIW$見效。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
