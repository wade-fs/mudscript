inherit ROOM;
void create() {
	set( "short", "欣的武器室II" );
	set( "object", ([
		"file7"    : "/open/common/obj/pill2",
		"amount3"  : 2,
		"amount9"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"amount7"  : 10,
		"file3"    : "/open/gsword/obj/ff_pill",
		"amount5"  : 19,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10001 );
	set( "owner", "lts" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room399",
	]) );
	set( "long", @LONG

         ██████████████████████████
         ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■
         ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■  ■■
         ██████████████████████████
         █田田田田田田田田田田田▄▄田田田田田田田田田田田█
         █|田田田田田田田田田田田田田田田田田田田田田田田|█
         █│∥∥  ∥∥  ∥∥            ∥∥  ∥∥  ∥∥│█
         █│∥∥  ∥∥  ∥∥            ∥∥  ∥∥  ∥∥│█
         █│██  ██  ██            ██  ██  ██│█

LONG);
	setup();
	replace_program(ROOM);
}
