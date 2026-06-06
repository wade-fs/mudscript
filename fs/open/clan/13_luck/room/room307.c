inherit ROOM;
void create() {
	set( "short", "酷的補給站" );
	set( "owner", "cool" );
	set( "object", ([
		"file1"    : "/open/mogi/dragon/obj/key",
		"amount9"  : 1,
		"amount5"  : 5,
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file5"    : "/obj/stone/powder",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"amount6"  : 179,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/gsword/obj/dragon-sword",
	]) );
	set( "build", 10059 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room240",
	]) );
	set( "long", @LONG

@>>-  魔 法 驛 站  -<<@
這是我沈思，發呆，練功，補充精力的地方一進入此處，淡藍色系的
房間陳設，使人覺得精神氣爽，彷彿置身在蔚藍的黃金海岸，在這不
知不覺中，功力就如有神助般的加速倍增

**出發 ------ 總要有個方向**
**向 刀魂幽姬 的方向出發吧**


LONG);
	setup();
	replace_program(ROOM);
}
