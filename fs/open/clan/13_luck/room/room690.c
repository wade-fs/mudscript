inherit ROOM;
void create() {
	set( "short", "加奈子的窩" );
	set( "owner", "kanako" );
	set( "object", ([
		"file8"    : "/obj/stone/jiao",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount10" : 4,
		"amount1"  : 7470,
		"file9"    : "/obj/stone/powder",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file1"    : "/open/killer/obj/atman_pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 60,
		"amount5"  : 320,
		"amount9"  : 53,
		"file6"    : "/open/mon/obj/mon-pill",
		"amount3"  : 60,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount6"  : 550,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 103,
		"amount2"  : 93,
	]) );
	set( "build", 10053 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room45",
		"west"      : "/open/clan/13_luck/room/room760.c",
		"east"      : "/open/clan/13_luck/room/room761.c",
		"north"     : "/open/clan/13_luck/room/room593.c",
	]) );
	set( "long", @LONG
     $HIY$淺米色$NOR$的房間，棕色的$MAG$衣櫥$NOR$，DIY的$BMAG$$HIC$木地板$NOR$，
$HIC$藍色$NOR$格子窗簾，$HIG$青綠色$NOR$直線條床單，植物圖樣$HIW$枕頭套$NOR$，
$HIY$木黃色$NOR$桌椅，以及桌上一瓶  $HIG$卡打車  綠茶多酚，$NOR$
簡單的房間，適合$HIR$受傷$NOR$後修養和$HIB$發呆$NOR$!!
  $HIW$修養和發呆!!~是專長..!!$NOR$
        $HIW$『 最終也將邁向$HIM$變態$NOR$$HIW$之路 』$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
