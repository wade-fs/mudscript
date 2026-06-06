#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "火龍幻界");
  set ("long", @LONG
火光四射, 烈燄直衝天頂, 使得這裡的氣候十分炎熱, 四周都是火光,
這大概是統治著這裡的怪物以無窮的力量所造成的火之結界, 當你來到了這
時, 同時被它的火光迷惑, 找不到正確的出路。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"f-9.c",
  "east" : __DIR__"f-11.c",
]));
  set("outdoors", 1);

  setup();
}
void init()
{
      call_out("do_check",1,this_player()); 
}
void do_check(object me)
{
      if(me->query("combat_exp" ) < 5000000 && userp(me) && living(me)) {
        message_vision(HIR + "$N抵抗不了火龍幻界的熱度，被天神傳送回起點！\n" + NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
      }else  
      me->set_temp("check_ok",1);
}
