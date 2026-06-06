// Room: /open/capital/room/king/kr4-4-2
#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short","朝聖殿內部");
  set ("long", @LONG
這裡已是朝聖殿內部, 在往北就是皇帝接見百官的大殿, 為了避免
有人擅入而驚擾了皇上, 除了朝廷命官外嚴禁進入.
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kr4-4-1",
  "north" : __DIR__"kr4-4-3",
]));

  setup();
}

int valid_leave(object me,string dir){
  if(dir=="north" && present("soldier",environment(me)) && !wizardp(me)){
        if(me->query("class")=="officer")
          return 1;
        else
          return notify_fail("殿前武士拿起虎頭鋼刀擋在你面前,狠狠的瞪著你說道:
放肆！朝聖殿豈是你隨便進出的地方 \n");
    }
    return 1;
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC + "皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n" + NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
