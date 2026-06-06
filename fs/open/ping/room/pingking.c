// Room: /open/ping/room/pingking
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "段王府門口");
  set ("long", @LONG
這裡便是段王府, 段王府是整個平南城的中心, 在數百年前, 這兒
方圓數百里的地方是一個小國, 整個小國便是由段家的人所統治著, 如
今這裡以歸順朝廷統治, 而原本的段家因歸順的緣故, 也受封為平南王
只是這兒的人還是習慣稱呼其為段王府。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan-guard.c" : 2,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road7",
  "enter" : __DIR__"np1.c",
]));

  setup();
}

void init ()
{
  object me=this_player ();
  if (me->query_temp("six_sp_quest") == 4)
      {
       message_vision("\n你剛出大門, 突被一陣疾風撞倒, 只見一名僧侶急忙扶起你, 連聲道歉.\n",me);
       message_vision(HIY"特上級武僧說道:對不起, 沒撞傷你吧, 小僧有『急事』告知你師父, 才如此匆忙. \n"NOR, me);
       message_vision("說完, 便向府中奔去, 你滿懷好奇, 急忙也跟了進去. \n\n",me);
       me->set_temp("six_sp_quest",5);
      }
}
