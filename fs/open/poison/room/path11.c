// Room: /open/poison/room/path11.c
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
  set ("short", "小山洞");
  set ("long", @LONG
這裡是一個小小的山洞，東邊和南邊的石壁上均刻有聖
火像，仔細一看，北邊牆上有一個不明顯的小孔存在，東邊
石壁較光滑，南面石壁則是千瘡百孔的，此外看不出任何特
殊的地方。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"road6",
]));
  setup();
}
void init()
{
 object me = this_player();
 if(present("stonekey",me))
        tell_object(me,HIC + "東面石門有感於你身上磁石而發出喀喀的聲響。\n" + NOR);
 add_action("do_go","go");
 add_action("do_press","press");
}
int do_go(string str)
{
  object me = this_player();
  object ob = this_object();
  if(str == "south" )
        if(me->query("family/family_name")=="冥蠱魔教")
               {
                message_vision("$N熟練地開啟南面石門，翻身而入。\n",me);
                tell_room(ob,"石門隨即被關上。\n");
                me->move(POISON_ROOM"path2");
                return 1;
               }
  if(str == "east" )
        if(present("stonekey",me))
            {
             tell_room(ob,"東面石門感應到磁石的接近，開起了一道門。\n");
             message_vision("$N不慌不忙地走了進去。\n",me);
             tell_room(ob,"隨著磁石離去，石門自動關上。\n");
             me->move(POISON_ROOM"path12");
             return 1;
            }
}
int do_press(string str)
{
  object me = this_player();
  object ob = this_object();
  if(str != "fire")
        return notify_fail("你想按哪裡?\n");
  if(!me->query("quests/poison_help"))
    {

        tell_object(me, "由於你不清楚壓法，不小心觸動機關。\n");
        tell_object(me, "突然咻咻數響，你感到一股寒氣注入體內。\n");
	me->apply_condition("rose_poison", 3);
	return 1;
    }
  message_vision("$N正確地啟動石門開關，石門隨之開起。\n",me);
  message_vision("$N不慌不忙地走了進去。\n",me);
  message_vision("隨著$N走過，石門自動關上。\n", me);
  me->move(POISON_ROOM"path12");
  return 1;
}
