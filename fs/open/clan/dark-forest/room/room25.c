inherit ROOM;
void create() {
	set( "short", "$HIY$洛汗國$HIG$大草原$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "build", 10049 );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room26",
		"south"     : "/open/clan/dark-forest/room/room27",
	]) );
	set( "long", @LONG
一望無際的青蔥綠草，在此綿延開來，這裡正是驃騎國度
$HIR$『$HIY$洛汗國$HIR$』$NOR$管轄的大草原。由$HIW$白馬王$NOR$一脈所統治的洛汗，在遠
古時曾於剛鐸人皇瀕臨滅亡之際出手相救，人皇感於$HIW$白馬王$NOR$之
恩，特將此區賜給$HIW$白馬王$NOR$，使其世代為北方屏障。而藉由這片
廣大肥沃的草原，洛汗國亦得以訓練出強大的騎兵，中土世界
的馬匹，也以此區最為精良。

LONG);
	setup();
	replace_program(ROOM);
}
