inherit ROOM;
void create() {
	set( "short", "$HIR$魔日$HIY$劍$HIW$室$NOR$" );
	set( "owner", "baby" );
	set( "object", ([
		"amount5"  : 1,
		"amount10" : 308,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 525,
		"file9"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"file6"    : "/open/killer/obj/atman_pill",
		"file2"    : "/obj/gift/unknowdan",
		"file3"    : "/open/killer/memory/static",
		"file4"    : "/open/mon/obj/mon-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 61,
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/obj/gift/xiandan",
		"amount9"  : 3,
		"amount4"  : 45,
	]) );
	set( "build", 10036 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room195",
	]) );
	set( "long", @LONG

                 $HIR$☆  $HIW$魔  日  斬  $HIR$☆

$HIG$ξ雪月 風花ξ$HIY$縱身一躍，將全身功力集中於劍尖，憑空發出一擊。
$RED$你反應不及，$HIR$魔日斬$RED$已全數貫穿妳的身體。
$NOR$( 妳$RED$已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。$NOR$ )

$NOR$你腳下一個不穩﹐跌在地上一動也不動了。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
