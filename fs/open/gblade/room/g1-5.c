// 加入銀針解謎物件-by nike-
//調整銀針門save_die解謎線索與調整判斷邏輯 by blazakira 2011/3/19

inherit ROOM;
#include <ansi.h>
int i=0;
void create ()
{
  set ("short", "宴客廳");
  set ("long", @LONG

廳中有幾個僕役正忙著準備宴席，看樣子今天金刀門又有重要的客人要來
了，你走近桌子一看，乖乖！桌子是花梨大理石所做，上頭擺著四楞象牙
鑲金筷、烏銀斟壺、十錦琺瑯杯(cup)，極盡奢豪。你想要是能拿(take)
走兩三樣拿去賣，不就發了嗎？

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"gblade.c",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/gblade/npc/wang-fu" : 1,
  ]));
  set("light_up", 1);
  setup();
}

void init()
{
  add_action("do_take","take");
}

int do_take(string str)
{
  object me, who;
  me=this_player();
  who=present("wang fu", environment(me));

//  if(!me->query("doctor/find_cup")==1) //不是很懂 暫時先用下列判斷 by blazakira
  if(me->query("doctor/find_cup")!=1) //沒接任務當然不能拿
    return notify_fail("你想拿什麼東西？\n");
  if(me->query("doctor/get_cup")==1) //拿過也不能拿
    return notify_fail("你想拿什麼東西？\n");
  if(!str || str!="cup")
    return notify_fail("你想拿什麼東西？\n");
  if(i>=1)
    return notify_fail("可惜桌子上空空如也 \n");
/*
  if(!who)
  {
    message_vision(sprintf("$N偷偷走了過去，摸走了一隻"+HIC+"十錦琺瑯杯" + NOR + "。\n"),me);
    new("/open/gblade/obj/cup")->move(me);
    i=i+1;
  }
  else if(who && random(100) < 50)
  {
    message_vision(sprintf("$N偷偷走了過去，摸走了一隻"+HIC+"十錦琺瑯杯" + NOR + "。\n"),me);
    new("/open/gblade/obj/cup")->move(me);
    i=i+1;
  }
  else if(who)
  {
    message_vision("$N正要到手時，王福突然轉過臉來，發現$N的異狀！\n",me);
    message_vision("王福對$N大喝：我宰了你!!\n",me);
    who->kill_ob(me);
    return 1;
  }
  message_vision(sprintf("$N趁著沒人注意，幹走了一隻"+HIC + "十錦琺瑯杯" + NOR + "。\n"),me);
  new("/open/gblade/obj/cup")->move(me);
*/
  if(who && random(100) > 50)
  {
    message_vision(sprintf("$N偷偷走了過去，正當要摸走了一隻"+HIC+"十錦琺瑯杯" + NOR + "時。\n"),me);
    message_vision("王福突然心有靈犀轉過頭來，恰好發現$N的異狀！\n",me);
    message_vision("王福對$N大喝：我宰了你!!\n",me);
    who->kill_ob(me);
    return 1;
  }
  message_vision(sprintf("$N趁著沒人注意，偷偷走了過去，幹走了一隻"+HIC + "十錦琺瑯杯" + NOR + "。\n"),me);
  new("/open/gblade/obj/cup")->move(me);
  me->delete("doctor/find_cup");
  me->set("doctor/get_cup",1);
  set("doctor/get_cup",me->query("id")); //紀錄當下取走的玩家id by blazakira
  i=i+1;
  return 1;
}
