// Room : /open/clan/ou-cloud-club/room/room78.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIR$四極$HIY$天山$NOR$徑" );
	set( "owner", "miles" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount4"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount10" : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "build", 12798 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 5 */
		"eastup"    : "/open/clan/ou-cloud-club/room/room97.c",
		"northup"   : "/open/clan/ou-cloud-club/room/room95.c",
		"westdown"  : "/open/clan/ou-cloud-club/room/room77",
		"westup"    : "/open/clan/ou-cloud-club/room/room115.c",
		"southup"   : "/open/clan/ou-cloud-club/room/room79.c",
]) );
	set( "long", @LONG
這裡就是傳聞中的四極天山徑，若沒有相當足夠的奇門　　
遁甲當基礎，要想走過此處只怕會陷入萬劫不復的地步，只　　
見周圍有四個方向，個個似是而非，處處暗藏殺機，偏偏只　　
有一個才是正確的道路，叫人難以抉擇‧‧‧　　
　　
LONG);
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_transmit", 1 );
	setup();

	}
