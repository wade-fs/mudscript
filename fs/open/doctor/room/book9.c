//修正下方enter函數裡的邏輯錯誤 與增加save_die quest判斷
//以避免解doctor_book quest同時的誤入 by blazakira 2011/1/20
#include <ansi.h>
inherit ROOM;
inherit __DIR__"bookmsg.c";
string *exit = ({
  __DIR__"book1",__DIR__"book2",__DIR__"book3",
  __DIR__"book4",__DIR__"book5",__DIR__"book6",
  __DIR__"book7",__DIR__"book8",__DIR__"book9",});

void create()
{
  set("short", YEL + "藏經閣" + NOR);
  set("long",
    (: print_book_msg :),
  );
  set("exits", ([
    "south" : exit[random(sizeof(exit))],
    "north" : exit[random(sizeof(exit))],
    "east" : exit[random(sizeof(exit))],
    "west" : exit[random(sizeof(exit))],
  ]));
  set("no_transmit",1);
  setup();
}

void init()
{
  object me = this_player();
  if(me->query("doctor/get_mark")==1 && present("book_mark",me)
     && me->query("doctor/start_quest")==1) //多加一個判斷 以免被另個quest所影響導致bug解quest捷徑
  {
    add_action("do_search","search");
    add_action("do_look","look");
    add_action("do_enter","enter");
  }
}

int do_search()
{
  object me = this_player();

  if(present("book_mark",me))
  {
    write("你開始仔細的搜尋這房間的每一個角落！\n");
    if(random(100) < 50)
    {
      write("突然「啪喳！」的一聲，你似乎發現了一個暗道(road)！\n");
      me->set("doctor/find_door",1);
      return 1;
    }else{
      write("你發覺這個房間似乎並沒有什麼特別之處！\n");
      return 1;
    }
  }
}

int do_look(string arg)
{
  object me = this_player();

  if(!arg || arg != "road") return 0;
  if(me->query("doctor/find_door")==1)
  {
    write("你發覺這個暗道似乎可以進入(enter)！\n");
    return 1;
  }
}

int do_enter(string arg)
{
  object me = this_player();
  int kar = (int)me->query("kar")+random(20); //使用原始值較小來判斷即可

  if(!arg || arg != "road") return 0;
  if(me->query("doctor/find_door")==1)
  {
    write("你緩緩的走進這個暗道之中......\n");
    me->delete("doctor/find_door");
    if(random(100) < kar) {
      write(HIR + "突然間！你一腳踩了個空，向暗道內直滾而去....\n" + NOR);
      call_out("bad1",3,me);
      return 1;
    }else{
      write("你慢慢的向傾斜的暗道內走去...\n");
      call_out("good1",4,me);
      return 1;
    }
  }
}

int bad1(object me)
{
  int kee = (int)me->query("kee")/5;

  write(HIR + "你滾啊滾啊滾...你跌跌撞撞...撞得滿身是傷...\n" + NOR);
  me->add("kee",-kee);
  call_out("bad2",3,me);
}

int bad2(object me)
{
  int kee = (int)me->query("kee")/5;

  write(HIR + "你滾啊滾啊滾...你跌跌撞撞...撞得滿身是傷...\n" + NOR);
  me->add("kee",-kee);
  call_out("bad3",3,me);
}

int bad3(object me)
{
  int kee = (int)me->query("kee")/5;

  write(HIR + "你滾啊滾啊滾...你跌跌撞撞...撞得滿身是傷...\n" + NOR);
  me->add("kee",-kee);
  call_out("bad4",3,me);
}

int bad4(object me)
{
  int kee = (int)me->query("kee")/5;

  write(HIR + "你滾啊滾啊滾...你跌跌撞撞...撞得滿身是傷...\n" + NOR);
  me->add("kee",-kee);
  write(HIW + "你好不容易停了下來，發現自己已落在平坦的地面上頭...\n" + NOR);
  me->move("/open/doctor/room/yf-room");
  return 1;
}

int good1(object me)
{
  write("你慢慢的走著走著...四周盡是一片漆黑...伸手不見五指...\n");
  call_out("good2",4,me);
}

int good2(object me)
{
  write("你慢慢的走著走著...四周盡是一片漆黑...伸手不見五指...\n");
  call_out("good3",4,me);
}

int good3(object me)
{
  write("你慢慢的走著走著...四周盡是一片漆黑...伸手不見五指...\n");
  write("你終於到了一塊平坦的地面，但四周始終是一片漆黑...\n\n");
  me->move("/open/doctor/room/yf-room");
  return 1;
}
