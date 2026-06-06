#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "儲藏室");
  set ("long", @LONG
    這裡是段家的儲藏室, 似乎不常有人來, 灰塵到處都是, 只見牆邊
的桌子上排著一個一個的箱子(box), 除此之外, 也沒有別的東西了。

    北邊有一道鐵門(door)。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"np3",
]));

  create_door("north","鐵門","south",DOOR_LOCKED);

  set("item_desc", ([ /* sizeof() ==  */
  "north" : (: look_door,     "north" :),
  "door" :  (: look_door,     "north" :),
  "box" : "一個小小精緻的銅箱子, 裡頭似乎有些東西。\n",
  ]));

  set("search_desc", ([ /* sizeof() == 1 */
  "box" : "你打開了箱子瞧了一瞧, 發現裡頭裝滿了炮仗(firecracker)。\n若想要的話就拿(take)一些走吧。\n",
  ]));

  set("need_key", ([ /* sizeof() == 1 */
  "east" : 1,
]));

  setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string str)
{
        object me=this_player();
        object fire=new(PING_OBJ"fire");
        if(str != "firecracker")
          write("你要從箱子裡拿什麼出來?\n");
        else
        {
          write("你小心翼翼的拿出一個炮仗揣入懷裡。\n");
          fire->move(me);
        }
        return 1;
}


