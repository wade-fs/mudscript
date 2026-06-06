inherit ROOM;
void create() {
	set( "short", "ζ 傲笑居 ζ" );
	set( "owner", "blackhorse" );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/fire-hole/obj/p-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 26,
		"amount10" : 25,
		"file10"   : "/open/mon/obj/mon-pill",
		"amount7"  : 68,
		"amount1"  : 5,
		"amount3"  : 111,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 11,
		"amount5"  : 222,
		"amount8"  : 44,
		"amount9"  : 11,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 10,
		"file3"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10047 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room76",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
$HIW$───────────────────────────
            $HIM$半涉濁流半涉清$HIW$，$HIM$倚箏閒吟廣陵文$HIW$，
    
            $HIM$寒劍默聽君子意$HIW$，$HIM$傲視人間笑紅塵$HIW$。
    
            $HIM$半箏永隨花中泥$HIW$，$HIM$瑟刃已成忘情詩$HIW$，
    
            $HIM$傲笑人間風雲客$HIW$，$HIM$愁月從此落天池$HIW$。
    $HIW$───────────────────────────
 $NOR$這是$HIW$劍聖$HIR$傲笑紅塵$NOR$所居住的地方。
      現在由($HIC$極冰$NOR$)$HIW$雪女孩$NOR$居住於此！          
LONG);
	setup();
	replace_program(ROOM);
}
