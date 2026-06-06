inherit ROOM;
void create() {
	set( "short", "$HIM$新天地$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"file10"   : "/open/gsword/obj1/khelmet",
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj1/kring",
		"file8"    : "/open/gsword/obj1/karmor",
		"amount1"  : 1,
		"file2"    : "/open/gsword/obj1/kring",
		"file1"    : "/open/gsword/obj1/kring",
		"amount5"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/gsword/obj1/khelmet",
		"file5"    : "/open/gsword/obj1/kring",
		"file3"    : "/open/gsword/obj1/karmband",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file9"    : "/open/gsword/obj1/karmband",
		"file4"    : "/open/gsword/obj1/khelmet",
		"amount7"  : 1,
	]) );
	set( "build", 10086 );
	set( "outdoors", "/open/clan/orient" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room51",
	]) );
	set( "long", @LONG
新天地預定地.......尚未開發.......閒人物近
新天地預定地.......尚未開發.......閒人物近
新天地預定地.......尚未開發.......閒人物近
新天地預定地.......尚未開發.......閒人物近
新天地預定地.......尚未開發.......閒人物近
LONG);
	setup();
	replace_program(ROOM);
}
