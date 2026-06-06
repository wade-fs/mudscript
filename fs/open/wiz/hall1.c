// Room: /d/wiz/hall1.c
#include <room.h>


inherit ROOM;

void create ()
{
  set ("short", "巫師交誼廳");
  set ("long", @LONG
如果您有任何話想留給其他巫師看, 請在此地 post.  也因為這裡
提供此項服務, 所以常常是巫師們聚集的地方. 當然, 巫師們每次上線
通常也都會來這兒, 如果您不常來這兒, 也許您已經漏掉不少資訊了.
    往南是程式寫作房, 那邊您可以發問或查詢跟程式寫作有關的種種
疑難雜症, 往東則是跟玩家有關的房間, 要是您常常寫程式或開發某一
地區, 請您務必常常過去賞光, 也許那邊會有問題等您解決呢! 往西則
是一個郵局, 最近郵局已經開發出新功能, 當您有話要私下講的時候,
利用郵局是一個不錯的選擇.

               ftp位置為fs.twkang.net 5560


LONG);

  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 6 */
  "down" : "/u/c/chan/cl_room.c",
  "up" : __DIR__"hall3",
  "south" : __DIR__"program_room",
  "west" : __DIR__"post_office",
  "east" : __DIR__"entrance.c",
  "north" : __DIR__"jobroom",
  "board" : __DIR__"board",

]));


  setup();
call_other("/obj/board/wizard_b","???");   
}
