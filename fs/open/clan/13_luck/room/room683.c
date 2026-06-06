inherit ROOM;
void create() {
	set( "short", "七彩陣之紫陣" );
	set( "object", ([
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount2"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount3"  : 732,
		"amount7"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"file4"    : "/open/capital/obj/4-2",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file1"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10038 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room684.c",
		"north"     : "/open/clan/13_luck/room/room682",
	]) );
	set( "long", @LONG

╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ ╭╮
╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯ ╰╯╰╮
    這是七彩陣的『紫』陣，眼前所見的景物都是紫色
，這是七彩陣的最後一陣。陣中央有根『紫水晶』，正
是破陣之物，也是七彩陣的最後一根水晶。收集六根水
晶的你，當然不會放過第七根水晶，拔出它繼續前進。
╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╯
╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯

LONG);
	setup();
	replace_program(ROOM);
}
