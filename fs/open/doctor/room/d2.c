#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short","道路");
  set ("long", @LONG
你正走在這條道路上，一路走來，只有看到幾個樵夫，背著一擔擔的乾
材，步行而過。路邊長滿了許多珍貴的草藥，【 銀針門 】三個大字越來越
明顯，由於求醫心切，你的腳步又不知不覺地加快了。

LONG);

  set("light_up", 1);
        set("outdoors", 1);
        set("objects",([
        ]));
  set("exits", ([ /* sizeof() == 2 */
      "south" : __DIR__"d1",
      "north" : __DIR__"d3",
      ]));
  setup();
}


