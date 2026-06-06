inherit ROOM;
void create() {
	set( "short", "$MAG$雷火彩鳳翔$NOR$" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount1"  : 1,
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount2"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
	]) );
	set( "owner", "cowboy" );
	set( "build", 10809 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room690",
		"west"      : "/open/clan/ou-cloud-club/room/room688.c",
	]) );
	set( "long", @LONG

$MAG$雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔$NOR$
$MAG$雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔$NOR$
$MAG$雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔$NOR$
$MAG$雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔雷火彩鳳翔$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
