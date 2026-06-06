#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW + "狂想空間新手入門" + NOR);
  set ("long","最後大部份的門派都有提供謎(quests),及進階武技提升
  的特別絕招(functions)!!這方面,新手玩家在玩時可以請教老玩家,或是
  加入幫派後可以問一下幫中的高手!!!虛心請教!!!我想大多數的玩家都
  會很樂意幫你的!!!!
  \n");
  set("exits", ([
  "west" : __DIR__"newhand2-5",
  "east" : __DIR__"newhand",
               ]));
  set("light_up", 1);
  setup();
}

