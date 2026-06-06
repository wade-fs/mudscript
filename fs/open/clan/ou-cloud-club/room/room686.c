inherit ROOM;
void create() {
	set( "short", "$HIB$刀斬邪元歸$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 12963 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room687",
		"west"      : "/open/clan/ou-cloud-club/room/room685.c",
	]) );
	set( "long", @LONG

$HIB$刀斬邪元歸刀斬邪元歸刀斬邪元歸刀斬邪元歸$NOR$
$HIB$刀斬邪元歸刀斬邪元歸刀斬邪元歸刀斬邪元歸$NOR$
$HIB$刀斬邪元歸刀斬邪元歸刀斬邪元歸刀斬邪元歸$NOR$
$HIB$刀斬邪元歸刀斬邪元歸刀斬邪元歸刀斬邪元歸$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
