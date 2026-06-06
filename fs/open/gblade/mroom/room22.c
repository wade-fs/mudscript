// Room: /u/m/moner/room/room22.c
inherit ROOM;

int have = 1;
int time = 0;
void create ()
{
  set ("short", "後院");
  set ("long", @LONG

這裡是魔刀門內栽花植草的地方，因門人多為習刀嗜武之人，鮮少有
愛花惜草之人，所以院內少有人照料，奇花異草和雜花雜草生長在一起
，不仔細看的話是分辨不出來的，彩蝶翩翩的穿梭在花叢間，蜜蜂辛勤
採著蜜。
       清風微微的吹拂著，一隻蝴蝶不小心飛到你身旁了。
LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room21.c",
]));

  setup();
}
void init()
{
    add_action("search_here", "search");
   add_action("pull_straw", "pull");
}
int search_here(string arg)
{
    if( (this_player()->query("combat_exp",1) > 10000)  && have)
   write("你搜了搜四周, 發現腳落了草叢有些奇怪..\n"+
       "你決定拔拔看那堆草 (pull straw)...\n");
    else
      write("也許\是你經驗不足,你什麼也沒發現...\n");
    return 1;
}
  int pull_straw(string arg)
{
    object user,ob;
    user = this_player();
    if( (user->query("combat_exp",1) > 10000)  && have)
    {
    have = 0;
     ob=new("/daemon/class/blademan/npc/butterlfy.c");
     ob->move(__DIR__"room22.c");
    message_vision("當$N正要拔起草的時, 一隻彩蝶飛了出來!!\n", user);
    return 1;
    }
    return 0;
}
void heart_beat()
{
  time++;
  if( time > 300)
  {
    time = 0;
    have = 1;
   }
   return;
}
