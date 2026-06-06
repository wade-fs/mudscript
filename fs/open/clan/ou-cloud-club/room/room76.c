// Room : /open/clan/ou-cloud-club/room/room76.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIR$四極$HIY$天山$NOR$徑" );
	set( "object", ([
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj1/bbladeball",
		"amount10" : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"file1"    : "/open/gsword/obj1/bbladeball",
		"amount4"  : 1,
		"file6"    : "/open/gsword/obj1/bbladeball",
	]) );
	set( "build", 10020 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 5 */
  "eastup" : "/open/clan/ou-cloud-club/room/room90.c",
  "northup" : "/open/clan/ou-cloud-club/room/room77.c",
  "westup" : "/open/clan/ou-cloud-club/room/room89.c",
  "southup" : "/open/clan/ou-cloud-club/room/room91.c",
  "eastdown" : "/open/clan/ou-cloud-club/room/room75",
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
