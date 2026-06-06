inherit ROOM;
void create() {
	set( "short", "狂龍刀塚" );
	set( "owner", "mill" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
	]) );
	set( "build", 10122 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room325",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

$HIB$███████████████████████████████
█                                                          █
█  $HIR$◢▆▆◣        $HIR$◢▊███▉███▇▆▅▄▃▂▁        $HIB$█
█  $HIR$▋█▆▊$HIR$▊▊▊▊▋$HIY$◎$HIR$█████▇▇███▇▇███◣    $HIB$█
█  $HIR$◥ ◤           $HIR$◥▊          ◥▇▇████▇▇██◣  $HIB$█
█                    $HIR$◥                ▇████▇▇█◤  $HIB$█
█                                                          █
███████████████████████████████
██████□□□□╬$HIG$刀$HIB$▃$HIG$嘯$HIB$▃$HIG$武$HIB$▃$HIG$林$HIB$▃$HIG$行$HIB$╬□□□□██████$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
