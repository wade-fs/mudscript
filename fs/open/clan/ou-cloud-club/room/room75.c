// Room : /open/clan/ou-cloud-club/room/room75.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
這裡就是傳聞中的四極天山徑，若沒有相當足夠的奇門　　
遁甲當基礎，要想走過此處只怕會陷入萬劫不復的地步，只　　
見周圍有四個方向，個個似是而非，處處暗藏殺機，偏偏只　　
有一個才是正確的道路，叫人難以抉擇‧‧‧　　
　　
LONG);
	set( "short", "$HIR$四極$HIY$天山$NOR$徑" );
	set( "owner", "perth" );
	set( "object", ([
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/capital/obj/icer",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"file5"    : "/open/capital/obj/icer",
		"amount8"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount3"  : 1,
	]) );
	set( "build", 10032 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 5 */
  "southup" : "/open/clan/ou-cloud-club/room/room114.c",
  "westup" : "/open/clan/ou-cloud-club/room/room76.c",
  "eastup" : "/open/clan/ou-cloud-club/room/room113.c",
  "down" : "/open/clan/ou-cloud-club/room/room74",
  "northup" : "/open/clan/ou-cloud-club/room/room86.c",
]) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	setup();

	}
