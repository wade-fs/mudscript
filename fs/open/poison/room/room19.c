 // Room: /open/poison/room/room19
#include <ansi.h>
#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
  set ("short", "牢房");
  set ("long", @LONG
這裡四處都是鐵牆銅壁的，乃是冥蠱魔教用來囚禁重犯
之用，這裡不像對面那般雜亂，反而顯的額外整齊，只是地
上已鋪上一層薄薄的灰塵，看來已有一小段時間無人踏入此
地，仔細一看，牆角處堆放了一個不起眼的箱子。
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"path13",
]));
  set("need_key/south",1);
  create_door("south",HIB"藍色鐵門"NOR,"north",DOOR_LOCKED);
  set("box_get",0);
  setup();
}
void reset()
{
  set("box_get",0);
  :: reset();
}
void init()
{
  add_action("do_search","search");
  add_action("do_push","push");
  add_action("do_look","look");
  add_action("do_look","l");
  add_action("do_get","get");
}
int do_get(string str)
{
  string str1, str2;
  object me, book;
  if(sscanf(str,"%s from %s",str1,str2) != 2)
        return 0;
  if( str1 != "book" || str2 != "box")
        return 0;
  if(query("box_get"))
	{
	  tell_object(me,"你想從空箱中拿出什麼呀! \n");
	  return 1;
	}
  set("box_get",1);
  me = this_player();
  book = new(POISON_OBJ"box_book");
  book->move(me);
  message_vision("$N從箱中搜出一本書來。\n",me);
  return 1;
}
int do_search(string str)
{
  object me = this_player();
  object ob;
  if(!str || str != "hole" || !me->query_temp("box_moved"))
        return 0;
  if(me->query("lotch") == 5) {
        tell_object(me,HIC"經過你的搜索之後，你發現了一樣東西。\n"NOR);
        tell_object(me,HIC"你取出仔細一看。哇! 竟是傳說中的煉妖壺。\n"NOR);
	me->set("lotch",6);
        ob = new("/open/gblade/mob/lotch");
        ob->move(me);
        return 1;
      }
  tell_object(me,"你仔細搜查好幾遍，還是找不到任何東西。\n");
  return 1;
}
int do_look(string str)
{
  object me = this_player();
  if(!str)
        return 0;
  if(str == "box" || str == "箱子") {
        if(!query("box_get"))
                tell_object(me,"這是一個沉重的鐵箱，箱子內藏有幾本書。\n");
        else
                tell_object(me,"這是一個沉重的鐵箱，箱內空空如也，什麼都沒有。\n");
        return 1;
      }

  if(str == "hole" && me->query_temp("box_moved")) {
        tell_object(me,"這是一個不明顯的小洞，其內不知藏有何物? \n");
        return 1;
      }
  return 0;
}
int do_push(string str)
{
  object me = this_player();
  if(!str || str != "box")
        return notify_fail("你想要推什麼?\n");
  if(me->query_temp("box_moved"))
        return notify_fail("你已經推開箱子了呀。\n");
  tell_object(me,"突然陣陣銀光撒出，頓時四面八方盡是光影。\n");
  if(me->query_kar() < 30 && random(me->query_skill("dodge")) < 20) {
        tell_object(me,"一不小心，閃躲不及，你中了幾針銀針。\n");
	me->apply_condition("dark_poison", 3);
       }
  else
        tell_object(me,"很幸運，你閃躲過所有的銀針。\n");
  me->set_temp("box_moved",1);
  tell_object(me,"在推開箱子後，你發現其下有一小洞(hole) 。\n");
  return 1;
}
