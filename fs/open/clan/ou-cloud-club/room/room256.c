inherit ROOM;
void create() {
	set( "short", "$HIR$小紅帽$NOR$" );
	set( "owner", "ripken" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file9"    : "/open/prayer/obj/boris-cloth",
		"file2"    : "/daemon/class/fighter/armband",
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/capital/guard/gring",
	]) );
	set( "build", 14641 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room241",
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
