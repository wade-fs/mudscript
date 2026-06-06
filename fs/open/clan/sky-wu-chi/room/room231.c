inherit ROOM;
void create() {
	set( "short", "小喵兵器房" );
	set( "owner", "cong" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/japan/obj/super-blade",
		"amount5"  : 1,
		"file10"   : "/obj/gift/bingtang",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/capital/obj/blade2",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"file4"    : "/open/soldier/obj/blood",
		"file2"    : "/open/beggar/obj/gstaff",
		"amount9"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/golden-ball",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake_gem",
	]) );
	set( "build", 10176 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room99",
	]) );
	set( "long", @LONG
這是一小喵專用的兵器房 , 這裡放著各式各樣的兵器 , 為
世界兵器最為齊全之地 , 你看到各種奇怪的兵器 , 所謂工欲善
其事 ,必先利其器 , 看來 ,你也該為自己選把像樣的武器 , 好
闖蕩江湖 .你可以看看(list)參觀一下這裡的兵器 ?

LONG);
	setup();
	replace_program(ROOM);
}
