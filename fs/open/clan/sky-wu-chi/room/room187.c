inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$防具所$HIB$II$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room109",
		"west"      : "/open/clan/sky-wu-chi/room/room169.c",
	]) );
	set( "light_up", 1 );
	set( "object", ([
		"amount7"  : 1,
		"file10"   : "/open/capital/guard/gring",
		"amount8"  : 1,
		"file1"    : "/open/gsword/obj1/sball",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"file6"    : "/open/beggar/obj/wrists",
		"amount1"  : 1,
		"file2"    : "/open/ping/questsfan/obj/stone",
		"amount10" : 1,
		"amount2"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10515 );
	set( "long", @LONG
   這裡是夜空下的欣的防具所,所有防具都整齊劃一的排列在防具所裡
每個防具都閃亮著他們的光芒,導致整各房間閃閃發亮,你看到裡面所
收藏的妖幻防具..不禁嘖嘖稱其......所有的防具在欣提刀作戰時,則
給了欣一道強勁的防護.....
vv
LONG);
	setup();
	replace_program(ROOM);
}
