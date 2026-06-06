inherit ROOM;
void create() {
	set( "short", "$BLU$魔爪混天殺$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 13163 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room688",
		"west"      : "/open/clan/ou-cloud-club/room/room686.c",
	]) );
	set( "long", @LONG

$BLU$魔爪混天殺魔爪混天殺魔爪混天殺魔爪混天殺$NOR$
$BLU$魔爪混天殺魔爪混天殺魔爪混天殺魔爪混天殺$NOR$
$BLU$魔爪混天殺魔爪混天殺魔爪混天殺魔爪混天殺$NOR$
$BLU$魔爪混天殺魔爪混天殺魔爪混天殺魔爪混天殺$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
