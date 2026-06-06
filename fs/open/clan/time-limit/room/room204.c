inherit ROOM;
void create() {
	set( "short", "$HIM$小臭虫之家" );
	set( "object", ([
		"file8"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/mon-pill",
		"file1"    : "/obj/gift/hobowdan",
		"file3"    : "/open/beggar/obj/neck",
		"file7"    : "/obj/gift/lingzhi",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount5"  : 422,
		"amount3"  : 1,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"amount9"  : 109,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 1,
		"amount6"  : 8,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 32,
	]) );
	set( "owner", "rena" );
	set( "build", 10098 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room248",
		"west"      : "/open/clan/time-limit/room/room82",
	]) );
	set( "long", @LONG
    $HIW$淺米色的房間，棕色的衣櫥，$HIR$DIY$NOR$$HIW$的木地板，
$HIC$藍色$HIW$格子窗簾，$HIG$青綠色$HIW$直線條床單，植物圖樣枕頭套，
$HIY$木黃色$HIW$桌椅，以及桌上一瓶  $HIB$卡打車  $HIW$綠茶多酚，
簡單的房間，適合$HIR$受傷$HIW$後修養和發呆!!
修養和發呆!!~是專長..!!
        『 最終也將邁向$HIC$變態$HIW$之路 』
LONG);
	setup();
	replace_program(ROOM);
}
