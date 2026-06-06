inherit ROOM;
void create() {
	set( "short", "$HIY$傲$HIC$雲$HIR$龍鱗藏$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10207 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room224",
		"south"     : "/open/clan/ou-cloud-club/room/room262.c",
	]) );
	set( "long", @LONG
$HIY$傲$HIC$雲$NOR$山莊內大量存有魔界守護神獸的鱗甲，此乃聖
火教之$HIY$ζ$HIW$天焰武神$HIY$ζ$NOR$「$HIR$捨身入魔$NOR$」$HIC$冰焰$NOR$單憑一人之力力
挑魔界神獸$HIY$黃金甲龍$NOR$後從甲龍身上所得的龍鱗甲，據聞
此$HIY$魔龍鱗$NOR$具有通往魔界某處之效．

LONG);
	setup();
	replace_program(ROOM);
}
