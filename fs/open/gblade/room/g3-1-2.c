inherit ROOM;
int counter = 10;
void create ()
{
  set ("short", "疊翠軒");
  set ("long", @LONG

從房裡的小門走出來，是一個小小的後院，有千百竿翠柳遮映，有大株梨
花，闊葉芭蕉，又有兩間小小退步；後院牆下忽開一隙，得泉一脈，開溝
尺許，灌入牆內，然後灌入牆內，繞階緣屋至前院盤旋竹下而出。如此幽
雅的環境不禁讓你想要在樹下小睡(sleep)一番。

LONG);

   set("light_up", 1);
   set("exits", ([ /* sizeof() == 1 */
   "south" :__DIR__"g3-1-1.c",
]));

  setup();
}

void init()
{
        add_action("do_sleep","sleep");
}


int do_sleep(string arg)
{
   int _gin;
   message_vision("$N在樹下漸漸睡著了.Zzzz\n",this_player());
   if( (counter + random(10)) > 10 )
   {
     message_vision("$N醒了過來，看起來精神好多了。\n\n",this_player());
     this_player()->add("sen",20);
     counter --;
     return 1;
   } else {
      _gin = this_player()->query("gin");
      message_vision("$N睡得太久有點累.\n\n",this_player());
      if( _gin >5 )
      {
       this_player()->add("gin", -5);
      }else{
       message_vision("$N睡死了!!\n",this_player());
       this_player()->set("gin", 1);
       this_player()->set("kee", 1);
      }
      return 1;
   }
}
