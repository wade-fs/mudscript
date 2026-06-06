#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL + "幽冥道" + NOR);
	set( "build", 13 );
        set("long",@LONG
腳底踏的很不實在，彷彿站在稀鬆的土壤上面，
一點厚實感也沒有，四周偶爾總是會傳來陣陣血腥的
惡臭味，你無法搞清楚自己身處何處。
LONG);
        set("exits",([
        "hole":__DIR__"g-s06",
        ]));
        set("no_transmit",1);
        setup();
}
void init()
{
      call_out("do_check",1,this_player()); 
}
void do_check(object me)
{
  
      if(me && !me->query_temp("ghost-quest/cankill-king" ) && userp(me) && living(me)) {
        message_vision(HIW + "\n天神搖搖頭對$N說道：你這個愛用偷吃步的傢伙，滾回家去吧！\n" + NOR,me);
        me->move(me->query("startroom"));
        me->set( "clan/out","/open/center/room/inn");
      }else  if(me)
      {
          me->set_temp("check_ok",1);
      }
}
