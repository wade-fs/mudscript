#include <ansi.h>
inherit ROOM;

void create()
{
	set( "short", "七星陣門-"HIW"天樞"NOR );
	set( "long", @long

    附近雲霧繚繞，一片霧茫茫的景色。完全無法看清楚四周的景物，似乎是有人
故意擺陣於此，防止旁人隨意經過。旁邊還有一個奇怪的石頭(stone)。

long );
	set("item_desc", ([ /* sizeof() == 1 */
	"stone" : "上面刻著:       \n"+
		  "\n誤入此陣者，可拍(touch)石而出。\n\n",
	]));
	set("light_up",1);
	setup();
}

void init()
{
	object ob;

	ob = this_player();
	remove_call_out("greeting");
	call_out( "greeting", 0, ob );
	add_action( "do_touch", "touch" );
}

int do_touch()
{
	object who = this_player();
	tell_room( this_object(), who->query("name") + "呼的一聲消失無蹤了。\n", who );
	who->move(__DIR__"m8");
	if( who->query("food") > 200 )
		who->add( "food", -10 );
	return 1;
}

int greeting(object who)
{
  object room = this_object();
  object mob;
  int i;
  int edir=1+random(2);
  int wdir=1+random(2);
//  int ndir=1+random(2);
  int sdir=1+random(2);

  if(wdir!=2&&edir!=2&&sdir!=2)
    wdir=2;

  room->set("exits/west",__DIR__"c"+wdir);
  room->set("exits/east",__DIR__"c"+edir);
	room->set("exits/north",__DIR__"c0");
  room->set("exits/south",__DIR__"c"+sdir);

  if(!who) return 1;
  if( who->query("bellicosity") > 500 ) {
    message_vision("	陣中雲霧感到邪氣逼近，瞬間匯聚成形...\n",who);
    message_vision(HIR"\n\n	一聲狂吼，數條狂暴的雲龍奔騰而出，向$N衝來！！！\n"NOR,who);
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
