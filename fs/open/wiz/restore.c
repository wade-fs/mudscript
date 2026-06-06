inherit ROOM;
#include <ansi.h>

void create ()
{
	set( "short", HIW"【"HIY"RESTORE"HIW"】【"HIC"申請廣場"HIW"】"NOR );
	set( "build", 155 );
	set( "long", @LONG
	
	   這兒是讓被 bug 害死者申訴的地方, 請注意下列規則:

	1. 一定要post畫面, 否則不予受理
	2. 若 restore 有誤, wiz 有權修改
	3. 金錢遺失問題, 不予受理
	4. post 後, 請靜待 wiz 處理, 不必再 post 催趕,
	   也可等 wiz 在線上時再處理
	5. 欺騙巫師 RESTORE 者, 殺無赦(purge)

LONG);
  set("no_kill",1);
  set("no_fight",1);
  set("light_up",1);
  set("exits", ([ /* sizeof() == 1 */
		"west" : "/open/common/room/inn",
	]));
	setup();
	call_other( "/obj/board/restore_b", "???" );
}


