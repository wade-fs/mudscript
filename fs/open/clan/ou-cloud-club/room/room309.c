inherit ROOM;
void create() {
	set( "short", "$HIW$無限城$NOR$--$HIG$東方之矛$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"file3"    : "/open/gsword/obj1/blosword",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/capital/obj/icer",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file6"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 10292 );
	set( "light_up", 1 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"west"      : "/open/clan/ou-cloud-club/room/room314.c",
	]) );
	set( "long", @LONG
原為古都‧萊姆東方的市集，來往的人潮成了新一代軍
團的新血輪，尤其是市集內的師父們紛紛加入兵器研發，使
得菜刀團擁有輕巧與鋒利兼具的殺敵武器，除此之外，飛甲
的開發工作也在這裡進行，目的是利用水蒸氣以及滑翔的原
理使得士兵能夠在空中戰鬥，強化無限城的空中戰力。

LONG);
	setup();
	replace_program(ROOM);
}
