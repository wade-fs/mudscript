#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIY + "金靈塔" + NOR);
	set ("long", @LONG
金靈塔的周圍遍滿了奇異的金屬，五彩的金屬不時的碰撞並發出
無比尖瑞的聲音，若非有一番功力的人，將承受不住這樣大的音波侵
襲，此塔中佈滿奇異金屬，若不能尋找到一個克制金的寶物，將有可
能在裏面被音波給震破五臟六腑。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"west"	: __DIR__"manor62",
	"enter"	: __DIR__"gold/gold01",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
