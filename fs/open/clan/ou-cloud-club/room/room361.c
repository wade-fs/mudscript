inherit ROOM;
void create() {
	set( "short", "$HIG$≡冥魔指套≡$NOR$" );
	set( "object", ([
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10166 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room363.c",
		"up"        : "/open/clan/ou-cloud-club/room/room372",
		"north"     : "/open/clan/ou-cloud-club/room/room360.c",
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
