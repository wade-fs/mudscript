inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔指套Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount9"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 14558 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room361",
	]) );
	set( "long", @LONG
指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套
冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套
冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套
冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套
冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套
冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套冥魔指套

LONG);
	setup();
	replace_program(ROOM);
}
