inherit ROOM;
void create() {
	set( "short", "$HIC$魔$HIW$‧$HIY$牙門$NOR$" );
	set( "owner", "miko" );
	set( "object", ([
		"amount3"  : 116,
		"file1"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount7"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 285,
		"file8"    : "/open/mon/obj/mon-pill",
		"amount4"  : 150,
		"file6"    : "/obj/gift/xisuidan",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 13,
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 12264 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room212",
	]) );
	set( "long", @LONG

$HIM$     ═════════════════ $NOR$
$YEL$              ║    ║  ║       $HIY$︻$NOR$
$YEL$              ║  ═╬═╬═╮   $HIY$Ｅ$NOR$
$YEL$            ╭╬╯  ║  ║  ║   $HIY$Ａ$NOR$
$YEL$              ║    ║  ║       $HIY$Ｒ$NOR$
$YEL$            ═╩═  ║           $HIY$Ｔ$NOR$
$YEL$                    ╰═══╯   $HIY$Ｈ$NOR$
$YEL$                                 $HIY$︼$NOR$
$HIM$     ═════════════════$NOR$
      $HIB$《  $HIY$明 王 輪 迴 $HIW$‧ $YEL$地 裂 破  $HIB$》$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
