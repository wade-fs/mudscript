inherit ROOM;
void create() {
	set( "short", "$HIY$狂想$HIC$儲藏室$NOR$" );
	set( "object", ([
		"file3"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/gblade/obj/sa-head",
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"file8"    : "/open/gblade/obj/sa-head",
		"amount8"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/gblade/obj/sa-head",
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room341",
		"up"        : "/open/clan/ou-cloud-club/room/hall",
	]) );
	set( "build", 10828 );
	set( "long", @LONG

$HIY$      ╰╮╰══╦══╯    ║    ╭══╮
      ╭╬╯    ║      ═╦╬╦═╠══╣
      ╯║  ══╬══  ╭╯║╰╮╠══╣
      ╭╬╯    ║          ╯    ╰══╯
      ╯║      ║      ╭╰╮╰═╮╰═╮
        ╯╰══╩══╯╯  ╰════╯$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
