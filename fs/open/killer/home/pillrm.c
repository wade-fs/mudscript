#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "殺手煉丹房");
  set ("long", @LONG
房間中煙霧繚繞，四處飄來的藥水味道令人難以忍受。房間中間有個巨大的煉丹爐（can)
有一位年老的婆婆在看守，這裡又沒有隱藏什麼秘密，真不知道她在看守什麼，
傳說中，她盡得葉孤城的真傳，一身煉藥的技術，可不是一般人可比擬。
據說連殺手密藥，都是她與葉孤城合力創作出來的。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r19.c",
]));
  set("objects",([
      "/open/killer/npc/pillman.c":1,]));
  set("item_desc", ([ /* sizeof() == 1 */
      "can" : "爐中火焰正鼎沸，試著將富士山秘草煉化吧。 ",]));
  setup();
}

void init()
{
add_action("do_secret",({"secret"}));
}

int do_secret()
{
 object me;

 me=this_player();
 if(me->query("class") != "killer")
 return 0;
 tell_object(me,"這房間果然有秘密！！發現了通道，你立刻走了過去\n");
 me->move(__DIR__"mimirm.c");
}
