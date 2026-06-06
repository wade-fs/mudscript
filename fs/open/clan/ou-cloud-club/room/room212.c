inherit ROOM;
void create() {
	set( "short", "$HIR$情$HIW$‧$HIC$牙門$NOR$" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 400,
		"file2"    : "/obj/gift/shenliwan",
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/obj/gift/shenliwan",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount7"  : 102,
		"amount9"  : 14,
		"file4"    : "/obj/gift/unknowdan",
		"amount8"  : 14,
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 1,
		"amount5"  : 170,
		"amount3"  : 1,
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount6"  : 754,
	]) );
	set( "owner", "etc" );
	set( "build", 11064 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room219",
		"east"      : "/open/clan/ou-cloud-club/room/room211.c",
	]) );
	set( "long", @LONG

$HIM$     ═════════════════$NOR$
$HIC$              ╭══╦══╯ $NOR$
$HIC$                    ║           $HIY$︻$NOR$
$HIC$            ╭═══╬═══╯   $HIY$Ｓ$NOR$
$HIC$                  ╭╯╮         $HIY$Ｋ$NOR$
$HIC$                ╭╯  ╰╮       $HIY$Ｙ$NOR$
$HIC$            ══╯      ╰══   $HIY$︼$NOR$
$HIM$     ═════════════════$NOR$
      $HIB$《  $HIY$明 王 輪 迴 $HIW$‧$HIC$ 天 狂 嘯  $HIB$》$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
