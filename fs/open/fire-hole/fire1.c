#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIB"神秘洞窟"NOR);
	set( "build", 48 );
  set ("long", @LONG
神秘的色彩瀰漫, 邪惡的氣息佈滿這裡, 這裡是火龍幻界的中心, 傳說
中幻界的統治者住在這裡, 前方有一個洞, 黑暗的令人感覺可怕, 有時還會
有邪惡的笑聲, 看來就是這裡了, 傳說中的火龍王住的地方--火龍王窟。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"fire2.c",
  "east" : __DIR__"f-25.c",
  "west" : __DIR__"f-24.c",
]));

  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  setup();
}

void init()
{
      call_out("do_check",1,this_player()); 
      add_action("do_search","search");
}

int do_search(string str)
{
   object me = this_player();
   if(!str && me->query_temp("find_scroll") == 3)
   {
    message_vision(HIG"\n六芒星魔法陣感應到$N身上的洛書河圖武學氣息，發出六色光芒將$N吸入...\n"NOR,me);
    me->move( __DIR__"scroll_room.c");
    return 1;
   }
   else{return notify_fail("找了老半天，可是看不出有任何特殊之處。");}
   
}

void do_check(object me)
{
      if(!me) return;
      if(me->query("combat_exp" ) < 5000000 && userp(me) && living(me)) {
        message_vision(HIR"$N抵抗不了火龍幻界的熱度，被天神傳送回起點！\n"NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
      }else  
      me->set_temp("check_ok",1);
}

