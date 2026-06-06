inherit ROOM;

void create ()
{
set("short","殺手地下訓練場 A 區");
  set ("long", @LONG
這裡是殺手總壇的地下迷宮，也是由機關手諸岡渡所精心設置。
尋常人並無法輕易的離開此處，或許應該小心一點，
因為四周傳來的殺氣，正訴說著此處所佈滿的危機。
但是這裡也是頂尖殺手自我訓練的好地方。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"sdr6.c",
"south" : __DIR__"sdr3.c",
"north" : __DIR__"sdr1.c",
]));
set("objects",([
"/open/killer/npc/sdkilla.c":3,
]));
  setup();
}

void init()
{
 add_action("do_search",({"search"}));
}

int do_search (string arg)
{
 object me,ob;
 
 me=this_player();
 if ( me->query_temp("mission3") != 3)
   return 0;
 if (!arg)
 {
   message_vision("$N仔細的找了一下，發現了一個按鈕，按下之後，出現一條往下的通道。\n", me);
   set("exits/down", __DIR__"sdr17.c");
   me->set_temp("mission3",4);
   return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
  if (dir != "down") 
  {
    this_object()->delete("exits/tree");
    return 1;
  }
  if (me->query_temp("mission3") != 4)
    return 0;
  this_object()->delete("exits/tree");  //只可進去一次
  return 1;
}
