inherit ROOM;
void create() {
	set( "short", "$CYN$$BBLU$冥魔$HIR$戒指$NOR$" );
	set( "object", ([
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 11313 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room672",
		"west"      : "/open/clan/ou-cloud-club/room/room659.c",
		"east"      : "/open/clan/ou-cloud-club/room/room661.c",
	]) );
	set( "long", @LONG

  $CYN$$BBLU$冥魔$HIR$帝冠$NOR$
  $CYN$$BBLU$冥魔$HIR$邪盾$NOR$
  $CYN$$BBLU$冥魔$HIR$寶墜$NOR$
  $CYN$$BBLU$冥魔$HIR$羽靴$NOR$
  $CYN$$BBLU$冥魔$HIR$披風$NOR$
  $CYN$$BBLU$冥魔$HIR$脛甲$NOR$
  $CYN$$BBLU$冥魔$HIR$足環$NOR$
  $CYN$$BBLU$冥魔$HIR$指套$NOR$
ˇ$CYN$$BBLU$冥魔$HIR$指戒$NOR$
  $CYN$$BBLU$冥魔$HIR$甲冑$NOR$
  $CYN$$BBLU$冥魔$HIR$肩甲$NOR$
  $CYN$$BBLU$冥魔$HIR$腰帶$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
