// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","枯\木林");
		set("long", "放眼望去，是一大片的荒野，和許\多因為無法忍受如此炎熱天氣
的枯\樹，四週的景色如此單調，也讓你漸漸失去了方向。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "up" :  __DIR__"maze",
            "down" :  __DIR__"maze",
            "left" :  __DIR__"maze",	
            "right" :  __DIR__"maze",
            "northwest" :  __DIR__"maze",
            "northeast" :  __DIR__"maze",			
      ]));
        setup();
}
//k= 1上2上3下4下5左6右7左8右9BA
int valid_leave(object me, string str)
{
  int k = me->query_temp("break-sun/maze");
  string dir;
  if(!k) me->set_temp("break-sun/maze",1);
  if(k == 5 || k == 7) dir = "left";
  if(k == 6 || k == 8) dir = "right";
  if(k < 5 && k > 2) dir = "down";
  if(k < 3) dir = "up";
  if(k == 9) dir = "northwest";
  if(k == 10) dir = "northeast";
  
  if(dir == str)
  {
   if(k==10)
    {
	 message_vision(HIR + "\n$N終於走出了枯\木林。\n" + NOR,me);
	 me->move(__DIR__"path01");
	 me->delete_temp("break-sun/maze");
	 return 0;
	}
   else
   {
    me->add_temp("break-sun/maze",1);
    message_vision(HIY + "\n$N感覺空氣似乎更加灼熱了，看來往這方向應該是正確的。\n" + NOR,me);
   }
  }
  return 1;
}
