#include <room.h>
#include <ansi.h>
inherit ROOM;
 void create()
{
  set("short", "樓梯間");
  set("long", @LONG
  兩旁的燈火順著樓梯一直往上去，似乎通往的極為重要的地方。
  我想沒事最好不要亂闖，但是你是否能克制自己的好奇心呢？
  樓梯旁似乎有往北方的通道，裡面殺聲連連，令你不禁想一探究竟。
  西方傳來陣陣的藥味與奇怪的味道，似乎人聲鼎沸。
  東方是殺手們的起居地有飯廳與宿舍，需要的人可以去看看。
LONG);
    set("light_up", 10);
   set("exits", ([
   "north": __DIR__"boardrm.c",
    "west": __DIR__"r19",
    "east": __DIR__"r18.c",
      "up": __DIR__"ru0.c",
   "south": __DIR__"r17.c",
    ]));
   set("objects",([
         "/open/killer/npc/guard.c":  2,
           ]));
 setup();
}
