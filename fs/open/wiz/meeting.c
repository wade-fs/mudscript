#include <room.h>

inherit RECORD_ROOM;

void create()
{
	set("short", "巫師會議室");
	set("long", @LONG

	會議室！

	目前只有錄音「say」訊息，沒限制誰啟動錄音！
	而且，錄音檔只能設在 /log 下。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "back"  : __DIR__"entrance",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("no_magic", 1);
	seteuid ("ROOT");

	setup();
	call_other("/obj/board/wiz_record_b","???");
}
