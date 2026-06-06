inherit ROOM;
void create() {
	set( "short", "$HIG$天地聖地$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"file2"    : "/open/gsword/obj1/karmor",
		"amount7"  : 1,
		"file6"    : "/open/killer/obj/kill_yar_head",
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount5"  : 1,
		"amount10" : 1,
		"file5"    : "/open/gsword/obj1/karmband",
		"amount8"  : 1,
		"file1"    : "/open/gsword/obj1/karmor",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file7"    : "/obj/stone/jiao",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file3"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10605 );
	set( "outdoors", "/open/clan/orient" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room52",
		"west"      : "/open/clan/orient/room/room43.c",
	]) );
	set( "long", @LONG
天地聖地預定地.......尚未開發.......閒人物近
天地聖地預定地.......尚未開發.......閒人物近
天地聖地預定地.......尚未開發.......閒人物近
天地聖地預定地.......尚未開發.......閒人物近
天地聖地預定地.......尚未開發.......閒人物近
LONG);
	setup();
	replace_program(ROOM);
}
