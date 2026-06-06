// Room : /open/clan/ou-cloud-club/room/room35.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$羅馬尼亞  $HIW$外西凡尼亞$NOR$" );
	set( "object", ([
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount4"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
	]) );
	set( "build", 10133 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
面前美麗的的多瑙河向西流去,不過,在沿岸的一座山坡頂崖邊
,卻矗立著一座古老城堡,城堡上空烏雲密佈,偶爾落下的幾道閃電
更是令人心理泛起一陣不祥之感,這座古老的城堡,隱藏著未知的
邪惡強大力量,來自另一個世界的可怕存在...
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room34",
  "northwest" : "/open/clan/ou-cloud-club/room/room36.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
