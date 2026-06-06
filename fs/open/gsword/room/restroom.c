// Room: /open/gsword/room/restroom.c

inherit ROOM;
// int picture = 1;

void create ()
{
  set ("short", "客棧");
  set ("long", @LONG
一間樸素的客棧,由於它並不是開在鬧區, 以致於客人不是很多,
老闆對你也是愛理不理的,你真懷疑他是怎麼經營下去而不倒店的.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"su9",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/bandit" : 1,
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{   
   object me;
   me = this_player();
     if( present ("keeper", environment(me)) )
     if(!me->query_temp("have_note"))
   {
     write("老闆說: 人客啊...蜀中城可是有王法的地方耶...
...想搜...拿(搜索令)來...\n");
     return 1;
   }  
/*  if( picture )
  {
     write("你找到一幅畫...\n");
     new("/open/gblade/obj/picture")->move(me);
     picture = 0;
     return 1;
  } 
*/
  if(arg == "地板" && me->query_temp("have_note"))
  {
    write("你在地板上發現一些血跡,你可以叫老闆看看(show keeper blood).\n");
    me->set_temp("see_blood",1);
    return 1;
  }   
  write("你找了老半天，可是看不出有任何特殊之處。\n");
  return 1;
}           
