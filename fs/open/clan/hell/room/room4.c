inherit ROOM;
void create() {
	set( "short", "$HIC$kalin$HIW$的$HIG$雞絲頭$NOR$" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
	]) );
	set( "owner", "blur" );
	set( "item_desc", ([
		"充氣娃娃" : @ITEM

cow...馬的B...色狼cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
cow...馬的B...色狼
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10270 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room93",
		"north"     : "/open/clan/hell/room/room43.c",
		"east"      : "/open/clan/hell/room/room54.c",
		"south"     : "/open/clan/hell/room/room44.c",
	]) );
	set( "long", @LONG
    經過了上次的祝融之災...kalin損失慘重...
在痛定失痛後...豬神決定不再打混了...
這次豬神學乖了..好好寫敘述....作各乖寶寶
eq..eq....回來吧..
eq..eq ........我愛你...
永永遠遠都不crash...........
嗯...就降...                    :)

$HIR$錯字1..痛定(思)痛
錯字2..作(個)乖寶寶
批..超白痴....12/20..(min)到此一$NOR$

  煤油冥紙的屍體(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
