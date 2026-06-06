// Room: /open/poison/room/path13
//補上顏色色碼NOR by blazakira 2010/12/25
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create ()
{
  set ("short", "牢房");
  set ("long", @LONG
這裡便是石牢所在地，由此看去可看見三個牢房，東邊
是有一密封鐵門，北面有一道只留一小小洞口的厚鐵門，南
面則是一般牢房，由一面鐵窗隔離，此地極為陰森恐怖。
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "south" : (: look_door,     "south" :),
  "north" : (: look_door,     "north" :),
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"path12",
  "north" : __DIR__"room19",
  "south" : __DIR__"room20",
  "east" : __DIR__"room22.c",
]));
  create_door("south",HIR + "紅色鐵門" + NOR,"north",DOOR_LOCKED);
  create_door("north",HIB + "藍色鐵門" + NOR,"south",DOOR_LOCKED);
  set("need_key", ([ /* sizeof() == 3 */
  "south" : 1,
  "north" : 1,
  "east" : 1,
]));

  setup();
}

void init()
{
  object me = this_player();
  if(me->query_temp("poison_help")==2) {
    remove_call_out("greeting");
    call_out("greeting",1,me);
  }
}

void greeting(object me)
{
  tell_object(me,HIC + "你聽到南面傳來陣陣求救聲。\n" + NOR);
  tell_object(me,HIC + "救～～我～～出～～去～～\n" + NOR);
  if(!present("red key",me)) {
    remove_call_out("greeting2");
    call_out("greeting2",1,me);
  }
}

void greeting2(object me)
{
  me->set_temp("poison_help",3);
  tell_object(me,HIC + "啊! 你沒有鑰匙呀! 趕快去向勾魂使拿吧! \n" + NOR);
  tell_object(me,HIC + "只要你救我出去我就告訴你一些秘密。\n" + NOR);
}
