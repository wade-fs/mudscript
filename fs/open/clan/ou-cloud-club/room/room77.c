// Room : /open/clan/ou-cloud-club/room/room77.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIR$四極$HIY$天山徑$NOR$" );
	set( "owner", "miles" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount4"  : 1,
	]) );
	set( "build", 10008 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 5 */
  "northup" : "/open/clan/ou-cloud-club/room/room93.c",
  "westup" : "/open/clan/ou-cloud-club/room/room92.c",
  "eastup" : "/open/clan/ou-cloud-club/room/room78.c",
  "southdown" : "/open/clan/ou-cloud-club/room/room76",
  "southup" : "/open/clan/ou-cloud-club/room/room94.c",
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
