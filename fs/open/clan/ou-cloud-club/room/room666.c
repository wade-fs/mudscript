inherit ROOM;
void create() {
	set( "short", "$CYN$$BBLU$冥魔$HIR$寶墜$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount7"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "owner", "cowboy" );
	set( "build", 10340 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room678",
		"west"      : "/open/clan/ou-cloud-club/room/room665.c",
		"east"      : "/open/clan/ou-cloud-club/room/room667.c",
	]) );
	set( "long", @LONG

  $CYN$$BBLU$冥魔$HIR$帝冠$NOR$
  $CYN$$BBLU$冥魔$HIR$邪盾$NOR$
ˇ$CYN$$BBLU$冥魔$HIR$寶墜$NOR$
  $CYN$$BBLU$冥魔$HIR$羽靴$NOR$
  $CYN$$BBLU$冥魔$HIR$披風$NOR$
  $CYN$$BBLU$冥魔$HIR$脛甲$NOR$
  $CYN$$BBLU$冥魔$HIR$足環$NOR$
  $CYN$$BBLU$冥魔$HIR$指套$NOR$
  $CYN$$BBLU$冥魔$HIR$指戒$NOR$
  $CYN$$BBLU$冥魔$HIR$甲冑$NOR$
  $CYN$$BBLU$冥魔$HIR$肩甲$NOR$
  $CYN$$BBLU$冥魔$HIR$腰帶$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
