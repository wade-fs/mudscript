inherit ROOM;
void create() {
	set( "short", "$HIC$逍遙錢莊$NOR$" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_finger",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file1"    : "/open/firedancer/npc/eq/r_hands",
		"file10"   : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/firedancer/npc/eq/r_pants",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 11052 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/free-zone/room/hall",
	]) );
	set( "long", @LONG

 $HIY$             ▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃▃
            ◢▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓◣
         ◥▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓◤
$HIR$           ▕︻|︻|︻|︻|/════\|︻|︻|︻|︻▏
           ▕︻|︻|︻|︻|/════\|︻|︻|︻|︻▏
           ▕︻|︻|︻|︻|/════\|︻|︻|︻|︻▏
           ▕︻|︻|︻|︻|/════\|︻|︻|︻|︻▏
           ▕︻|︻|︻|︻|/════\|︻|︻|︻|︻▏ 
           ▕︻|︻|︻|︻▁▁$HIW$$BRED$錢莊$NOR$$HIR$▁▁︻|︻|︻|︻▏ 
        ▕︻|︻|︻|︻|︻││$WHT$▆▆$NOR$$HIR$││︻|︻|︻|︻|︻▏
       $BWHT$◢※※※※※※※//═════\\※※※※※※※◣$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
