// Room : /open/clan/ou-cloud-club/room/room34.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$絲綢之路$NOR$" );
	set( "object", ([
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10369 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
沿途的景象漸漸多了些綠色的點綴了,不是沙漠中的綠洲,而是
因為這裡已經接近地中海了,往西過去就是東歐了,完全不同於中國
和印度的另一種古老文明,據說民族主義及浪漫學在此非常盛行,西
邊有一條河,河畔樹林綿密,景色優美,這就是橫亙歐陸的多瑙河.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room31",
		"west"      : "/open/clan/ou-cloud-club/room/room35.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
