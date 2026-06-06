inherit ROOM;
void create() {
	set( "short", "$CYN$$BBLU$冥魔$HIR$脛甲$NOR$" );
	set( "build", 10003 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room663",
		"west"      : "/open/clan/ou-cloud-club/room/room674.c",
		"east"      : "/open/clan/ou-cloud-club/room/room676.c",
	]) );
	set( "long", @LONG

  $CYN$$BBLU$冥魔$HIR$帝冠$NOR$
  $CYN$$BBLU$冥魔$HIR$邪盾$NOR$
  $CYN$$BBLU$冥魔$HIR$寶墜$NOR$
  $CYN$$BBLU$冥魔$HIR$羽靴$NOR$
  $CYN$$BBLU$冥魔$HIR$披風$NOR$
ˇ$CYN$$BBLU$冥魔$HIR$脛甲$NOR$
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
