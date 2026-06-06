// Room: /u/s/smore/room/suking/suking9.c

inherit ROOM;
int have = 1;
int time = 0;
void create ()
{
  set ("short", "蜀中花園");
  set ("long", @LONG
這裡是蜀中大將軍心愛的花園,種滿了各地收集來的奇花異草,
只見處處馨香,團花僅簇,但卻有那麼一點點的奇異,就是這若大
的花園裡,竟不見蝶飛蜂舞,似忽有些密秘.
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");
  set("exits", ([ /* sizeof() == 2 */
      "east" : "/open/gsword/room/suking10",
      "west" : "/open/gsword/room/suking2",
   "south":__DIR__"itroom.c",
  ]));
set("objects",([
"/open/gblade/obj/smallstone.c":1,
]));
  setup();
  set_heart_beat(1); 
}
void init()
{
    add_action("search_here", "search");
    add_action("pull_it","pull");
} 
int search_here(string arg)
{
    if( (this_player()->query("combat_exp",1) > 30000)  && have)
      write("你找啊找的,終於發現有人用奇門遁甲隱藏了一棵靈芝.\n"+
            "你可以試著拔它(pull it).\n");
    else
       write("也許\是你經驗不足,你什麼也沒發現...\n");
    return 1;
}
int pull_it(string arg)
{
    object user,ob;
    user = this_player();
    if( (user->query("combat_exp",1) > 30000)  && have)
    {
    ob=new("/open/gsword/mob/grass2");
    have = 0;
    ob->move("/open/gsword/room/suking9");
    message_vision("當$N正要拔起靈芝時,只見一隻守藥神獸衝了出來!!\n", user);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
time++;
if(time > 300)
{
time = 0;
have = 1;
}
return;
}
