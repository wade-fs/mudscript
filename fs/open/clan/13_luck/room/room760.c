inherit ROOM;
void create() {
	set( "short", "$HIR$倉庫$NOR$" );
	set( "object", ([
		"file8"    : "/obj/gift/xisuidan",
		"amount1"  : 118,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 1,
		"amount3"  : 160,
		"amount9"  : 43,
		"file6"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount4"  : 20,
		"amount2"  : 13,
	]) );
	set( "owner", "kanako" );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room690",
	]) );
	set( "long", @LONG
    $HIW$這是一間坪數非常大的$HIR$倉庫!!
$HIW$裡面放著許多的東西..有$HIY$寶物$HIW$包括一堆廢物..
這一堆$HIM$戰利品$HIW$都是靠著打鬥收集回來的--
東西$HIG$堆積如山,隨時有$HIG$倒塌$HIW$的危機@@
$HIW$也正因為如此..其中也有很多派的上用場的$BMAG$$HIC$好物$NOR$
$HIW$只要仔細$HIC$尋找$HIW$...必能找到想要的$YEL$東西$HIW$..CCC
LONG);
	setup();
	replace_program(ROOM);
}
