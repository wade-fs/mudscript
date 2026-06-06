///open/prayer/room/hole/20.c
//更正錯字與調整顏色為ansi by blazakira 2010/9/30

#include <ansi.h>
inherit ROOM;
void create ()
{
  seteuid(getuid());    
  set ("short", "囹圄池");
  set ("long", @LONG

        你的面前是一座腥臭無比的血池，並且傳來陣陣的邪氣!!血池中
        有一隻野獸在那裡翻滾，不過別怕，牠身上有數條的鐵鏈禁錮著
        牠，咬不到你的，不過你可以試著放牠自由(free)!!但是至於你
        的安全問題，可就沒有人保證了.....

LONG);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"18",
  "south" : __DIR__"19",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/kylin-statue" : 1,
]));

        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
  setup();
}
void init()
{
 add_action("free_kylin","free");
 add_action("search_here", "search");
}

int search_here(string str)
{
    if( (this_player()->query("combat_exp",1) > 100000)  )
    {
    write("你扯了扯鐵鍊之後，發現鐵鍊是可以順沿而下的，可是血麒麟在下面耶!!\n");
      set("exits/down",__DIR__"21");
      call_out("do_close",10);
   }
    else
    {
    write("也許\是你經驗不足，你什麼也沒發現...\n");
    }    
return 1;
}

void do_close()
{
        if(!query("exits/down"))
                return;
        delete("exits/down");
        tell_room(this_object(),"鐵鍊被血麒麟拉扯後將這條出路覆蓋\了。\n");
}

int free_kylin(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("kylin",environment(ob)))
    return notify_fail("血麒麟都被放走了，你想要怎樣呢？\n");
  if( str!="kylin")
    return notify_fail("吼~~~~~~~~~~!!!!\n");
  message_vision(CYN"你運勁將牠身上的鐵鏈震斷..."NOR,ob);
  write("\n\n\n");
     ob1=present("kylin",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
}   

int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("血麒麟開始在血池中劇烈的翻攪....\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  message("mud",YEL"血麒麟被放出來了........大家小心呀!!\n"NOR,users());
  call_out("msg3",3,ob);
  return 1;
}

int msg3(object ob)
{
  new("/open/prayer/npc/kylin")->move("/open/gsword/room/su3");

  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
  message("mud",CYN"血麒麟大吼一聲～～\n

     "+ ob->query("name")+""CYN"笑道：\n\n


     呵呵呵呵....是我把牠放出來的!!玩家要倒大楣了\n\n"NOR,users());
  
  return 1;
}                      
