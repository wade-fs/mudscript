#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIY + "狂想空間歷史發展館" + NOR);
  set( "long", "     後來創站大神Wade那時也快畢業了,慢慢的將事情交給了下一任大神Lum
,Lum接手FS在他的整頓之下巫師的問題也慢慢變少,約只有四十多位左右的巫
師,同時狂想的發展也正在進行,一些的門派也慢慢有其特色出來!!門派也慢慢
變多了,那時狂想也一直在穩定中發展!!!
" );
  set("exits", ([
  "north" : __DIR__"newhand6-3",
  "south" : __DIR__"newhand6-5",
               ]));
  set("light_up", 1);
  setup();
}

