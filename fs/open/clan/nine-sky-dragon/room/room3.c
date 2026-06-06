inherit ROOM;
void create() {
	set( "short", "$HIM$九$HIY$天$HIR$錢莊$NOR$" );
	set( "object", ([
		"file9"    : "/obj/stone/powder",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 1,
		"file6"    : "/obj/stone/jiao",
		"amount7"  : 90,
		"amount3"  : 2,
		"file4"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file5"    : "/obj/stone/powder",
		"file7"    : "/obj/stone/powder",
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 5,
		"file1"    : "/open/mogi/dragon/obj/dragon-head",
		"amount6"  : 10,
		"amount9"  : 49,
		"amount5"  : 412,
	]) );
	set( "build", 10071 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/nine-sky-dragon/room/room2",
	]) );
	set( "long", @LONG

      ║            ╭══╦══╯  ╭══╮═╬═╩═ ══╬═══╬══
╰══╬══╮            ║        ║ ╦ ║  ╰╮═╯ ║    ║    ╮    
      ║    ║    ╭═══╬═══╯║ ║ ║═╯╰═╯ ╰══╣══╬══
      ║    ║          ╭╯╮      ╯ ╬ ╰═╬═╩═ ╭══╣    ║    
    ╭╯    ║        ╭╯  ╰╮     ╮║╭   ╰╮═╯ ║    ║    ║    
╰═╯      ╰═╯╰═╯      ╰═╯ ╩╩╩ ═╯╰═╯ ╯    ╯  ═╩═   

LONG);
	setup();
	replace_program(ROOM);
}
