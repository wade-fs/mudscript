#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIR"火龍王窟"NOR);
	set( "build", 12 );
  set ("long", @LONG
這裡是火龍幻界的統治者--火龍王所居住的地方, 雄雄的火燄好像有
生命一樣燃燒著此地, 你還在遲疑著火龍王的蹤影時, 身旁的火突然瘋狂
亂竄而出, 又集中成一個形體向你直撲來, 你運用深厚的內力勉強支撐了
下來, 你仔細一看, 看來此形體這就是傳說中的火龍王。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"fire1.c",
]));
  set("no_transmit",1);
  set("no_chome",1);
  setup();
}
void init()
{
  object room = this_object();
   if(!present("dragon king"))      this_player()->delete_temp("fight_dking");
  if(room->query_temp("ko_b") && room->query_temp("ko_p") && room->query_temp("ko_g") &&
     room->query_temp("ko_y") && room->query_temp("ko_w") && room->query_temp("ko_r"))
  if(!present("dragon king"))
  {
   message_vision(HIR"\n六光龍魂的悲泣引發了火之王者的怒意，從熊熊烈火中飛躍而出，誓要血洗人間。\n\n"NOR,this_player());
   new("open/fire-hole/npc/fire-dragon")->move(room);
   this_player()->delete_temp("fight_dking");
  }
}

