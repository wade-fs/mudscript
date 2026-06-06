//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "七星陣門-" + HIW + "天樞" + NOR);
	set("long", @LONG
附近雲霧繚繞，一片霧茫茫的景色。完全無法看清楚四周的景物，似乎是有人
故意擺陣於此，防止旁人隨意經過。旁邊還有一個奇怪的石頭(stone)。

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
	"stone" : "上面刻著:       \n"+
		  "\n誤入此陣者，可拍(touch)石而出。\n\n",
	]));
	set("exits", ([ /* sizeof() == 3 */
]));
	
	set("light_up",1);
	setup();
}

void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
      remove_call_out("greeting");
	call_out("greeting", 0, ob);
   }

	add_action("do_touch","touch");
}

int do_touch()
{
  object who=this_player();
  
  who->move(__DIR__"c0");
  tell_room(this_object(),who->query("name")+"呼的一聲消失無蹤了。\n");
  return 1;
}

int greeting (object who)
{
  object room=this_object();
  object mob;
  int i;
  int edir=8-random(2);
  int wdir=8-random(2);
  int ndir=8-random(2);
  int sdir=8-random(2);

  if(wdir!=8&&edir!=8&&ndir!=8&&sdir!=8)
    edir=8;

  room->set("exits/west",__DIR__"d"+wdir);
  room->set("exits/east",__DIR__"d"+edir);
  room->set("exits/north",__DIR__"d"+ndir);
  room->set("exits/south",__DIR__"d"+sdir);

  if(who->query("bellicosity") > 500+random(100)) {
    message_vision("	陣中雲霧感到邪氣逼近，瞬間匯聚成形...\n",who);
    message_vision(HIR + "\n\n	一聲狂吼，數條狂暴的雲龍奔騰而出，向$N衝來！！！\n" + NOR,who);
    seteuid(getuid());
    i=random(3)+1;
    while(i--) {
      mob=new(__DIR__"npc/cl_dragon");
      mob->move(room);
      mob->callset(who);
      mob->kill_ob(who);
    }
  }

  return 1;

}
