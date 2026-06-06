// Room: /u/m/moner/room/room26.c
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "臥房");
  set ("long", @LONG

剛至此處，便有一股淡淡的細香，沁人心肺，向壁上望去，有唐伯虎畫的
「海堂春睡圖」，一旁卦著一把藍狿刀，另一方著有宋太學士寫的對聯，案
上擺著一幅水晶鏡，輕羅百蝶被上一絲凌亂，私忽有人剛睡過，東方螢珀石
屏風(screen)後，彷彿有黑影在搖動。

LONG);

  set("item_desc", ([ /* sizeof() == 2 */
"screen" : "由螢珀石所做成的屏風，光可照人。\n",
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 2 */
"west":"/open/gblade/mroom/room17.c",
"east":__DIR__"r2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
 "/daemon/class/blademan/npc/m1.c" :1,
]));
  set("light_up", 1);
  create_door("east", "螢珀石屏風","west",DOOR_CLOSED);
  setup();
}
int valid_leave(object me, string dir)
  {
if(dir=="east"&&(doors["east"]["status"]==DOOR_CLOSED) )
    return notify_fail("你必須先把螢珀石屏風打開﹗\n");
     if(dir=="east")
  {
          message_vision(HIW+"$N一踏入浴室，哇～～
美女入浴圖ㄟ，在$N來不及反應時，美女一個旋身，一件浴袍輕輕的
披上身子，一柄籃色的兵刃架在$N的頸上。\n"+NOR,me);
    }
    return 1;
   }
