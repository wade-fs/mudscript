inherit ROOM;
void create() {
	set( "short", "$CYN$$BBLU$冥魔$HIR$戒指$NOR$" );
	set( "build", 10144 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room660",
		"west"      : "/open/clan/ou-cloud-club/room/room671.c",
		"east"      : "/open/clan/ou-cloud-club/room/room673.c",
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
