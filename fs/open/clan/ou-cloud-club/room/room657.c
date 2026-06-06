inherit ROOM;
void create() {
	set( "short", "$CYN$$BBLU$冥魔$HIR$腰帶$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "owner", "cowboy" );
	set( "build", 16375 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room669",
		"east"      : "/open/clan/ou-cloud-club/room/room658.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

  $CYN$$BBLU$冥魔$HIR$帝冠$NOR$
  $CYN$$BBLU$冥魔$HIR$邪盾$NOR$
  $CYN$$BBLU$冥魔$HIR$寶墜$NOR$
  $CYN$$BBLU$冥魔$HIR$羽靴$NOR$
  $CYN$$BBLU$冥魔$HIR$披風$NOR$
  $CYN$$BBLU$冥魔$HIR$脛甲$NOR$
  $CYN$$BBLU$冥魔$HIR$足環$NOR$
  $CYN$$BBLU$冥魔$HIR$指套$NOR$
  $CYN$$BBLU$冥魔$HIR$指戒$NOR$
  $CYN$$BBLU$冥魔$HIR$甲冑$NOR$
  $CYN$$BBLU$冥魔$HIR$肩甲$NOR$
ˇ$CYN$$BBLU$冥魔$HIR$腰帶$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
