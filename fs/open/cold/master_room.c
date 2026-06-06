// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","寶珍神宮大殿");
	set("long", @LONG
這裡是寒谷一派的根據地﹐寶珍神宮是寒谷弟子世代居住的地方﹐
在大廳上﹐有一張用雪狼皮鋪著的寶座﹐而四周裝飾卻是十分的單調﹐
格外顯示出寒谷的冷清﹐然而在寶座之上有一月形標誌﹐是寒谷一派的
象徵﹐相傳著﹐寒谷派的掌門人每天都要向只月形標誌致敬﹐以表示對
前代師祖的尊敬。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"out":COLD_ROOM"home1",
	"north":COLD_ROOM"in1",
]));
	set("objects",([
	COLD_NPC"master":1,
	]));
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
