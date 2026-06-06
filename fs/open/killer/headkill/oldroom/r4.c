#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","兵器庫");
  set ("long", @LONG
這裡是黑牙聯平時儲存兵器的地方﹐在這裡可以看到不少的兵器
但是大多是暗器﹐只有黑牙聯的弟子可以在這裡領取兵器﹐但是必須
先向掌理兵器的兵器使報備(report)﹐想知道有什麼兵器就用(list)。


如今在你眼前的是一大堆落石，填滿了這一間兵器室，
當年的兵器使，幸好有隨葉秀殺一起脫離，目前仍在殺手總壇的兵器室中。
忽然你感覺南方似乎有人的氣息存在？
不會吧？有人會居住在這裡嗎？
記得葉秀殺曾經提過，當年的兵器室有機關連到訓練室，
不知道機關是不是有被破壞掉，在這裡找看看吧。。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"west":__DIR__"r3",
]));

/*
  set("objects",([
	"/open/snow/npc/manager":1,
	]));
*/

  setup();
}

void init()
{ 
   add_action("do_search","search");
}

int do_search()
{
   object me;
   me = this_player();
   tell_room(me,""+me->query("name")+"找到了機關，發現了一條出路。\n");
    set("exits", ([
	"west":__DIR__"r3",
	"south":__DIR__"r5",
]));
   return 1;
}
