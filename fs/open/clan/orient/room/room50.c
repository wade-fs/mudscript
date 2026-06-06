inherit ROOM;
void create() {
	set( "short", "$HIR$天香聖地$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/gsword/obj1/karmor",
		"file5"    : "/open/gsword/obj1/ring",
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/magic-sign",
		"file9"    : "/open/magic-manor/obj/magic-sign",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/magic-sign",
		"file2"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 12620 );
	set( "outdoors", "/open/clan/orient" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room43.c",
		"west"      : "/open/clan/orient/room/room53",
	]) );
	set( "long", @LONG
天香聖地預定地.......尚未開發.......閒人物近
天香聖地預定地.......尚未開發.......閒人物近
天香聖地預定地.......尚未開發.......閒人物近
天香聖地預定地.......尚未開發.......閒人物近
天香聖地預定地.......尚未開發.......閒人物近
LONG);
	setup();
	replace_program(ROOM);
}
