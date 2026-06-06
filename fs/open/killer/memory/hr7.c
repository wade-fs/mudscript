#include "/open/open.h"
#include "ansi.h"
inherit ROOM;

void create ()
{
  set ("short", "通吃小築");
  set ("long", @LONG

   這是由天才機關手諸岡渡與天靈老人，兩人合力完成的迷陣屋
   放眼望去每個房間長的都一樣，讓你難以分辨，到底要如何去行走
   如果想出去，趕快打BACK退出去吧........................
   在一旁有豎立了一個標示牌(sign)
   

LONG);
  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr9.c",
     "back" : __DIR__"hr5.c",   
]));
  set("item_desc", ([ /* sizeof() == 2 */
        "sign":"想加入殺手工會的話，或是資深殺手想見工會老大，請打 meet black\n",
]));
 set("objects",([
  "/open/killer/npc/spy4.c":2,]));
  setup();
}

void init()
{
	add_action("do_meet","meet");
//	add_action("do_look","look");
}

int do_look(string str)
{
  object me;

   if(str )
    return notify_fail("你想看什麼？？看看有沒有人救你嗎？？用哭的比較快啦！！\n");
//::look();
}

int do_meet(string str)
{
  object me=this_player();

   if( str != "black" )
    return notify_fail("你想去會見誰呀？？\n");

if(me->query("class") != "killer")
{
	 if(me->query("class"))
		return notify_fail("你以為你是誰呀，也想要去見他？自己找路吧！！\n");
	//表示不是殺手且為平民，想要加入殺手者
	if (me->query("quest/rain") != 1)
	message_vision(HIG + "突然由一旁出現一位紫霞組的高手！！！\n" + NOR,me);
	message_vision(HIG + "一陣灰暗後，你居然來到了工會老大面前........！\n" + NOR,me);
	me->move(__DIR__"hru2.c");
	return 1;

}
	//表示是殺手，想要去見工會老大者，但沒有解過魔氣殺之謎者
  if (me->query("quest/rain") != 1)
	return notify_fail("孩子，你的能力不足，也想要去見他？必須要自己找路哦！！\n");
	//有解過魔氣殺的殺手
  message_vision(HIG + "突然由一旁出現一位紫霞組的高手！！！\n" + NOR,me);
  message_vision(HIG + "一陣灰暗後，你居然來到了工會老大面前........！\n" + NOR,me);
  me->move(__DIR__"hru1.c");
  return 1;
}
