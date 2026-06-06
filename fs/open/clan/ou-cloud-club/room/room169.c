inherit ROOM;
void create() {
	set( "short", "$HIG$乾坤戰鬥服$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"amount10" : 1,
		"file1"    : "/obj/stone/jiao",
		"file9"    : "/obj/gift/unknowdan",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/magic-manor/obj/magic-sign",
		"amount7"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount1"  : 3,
		"file5"    : "/obj/stone/suipian",
		"file3"    : "/obj/stone/powder",
		"file4"    : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/key",
		"amount5"  : 2,
		"amount8"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 30,
	]) );
	set( "light_up", 1 );
	set( "build", 11698 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room187",
		"west"      : "/open/clan/ou-cloud-club/room/room143",
	]) );
	set( "long", @LONG
$WHT$基本棍法(stick)                技能效應： 15$NOR$
    $WHT$撲擊格鬥技巧(unarmed)          技能效應： 15$NOR$
    $WHT$跳躍閃躲之術(dodge)            技能效應： 5$NOR$
    $WHT$基本內功(force)                技能效應： 5$NOR$
此為聖火教的鎮教之寶....竟然被小馬..
有幾件還沾著血跡.....林宏升也許正在頭痛著...
LONG);
	setup();
	replace_program(ROOM);
}
