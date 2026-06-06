// /open/center/npc/vendor.c
// 加入銀針解謎物件-by nike-
//增加少林廚藝學院的quest相關 by blazakira 2010/9/6
//調整銀針門save_die解謎線索 by blazakira 2011/3/19

#include <ansi.h>
inherit NPC;

string ask_wine();
string ask_cup();
string ask_liqueur();
            
void create()
{
  set_name("賣酒的老頭", ({ "oldman"}) );
  set("gender", "男性" );
  set("age", 81);
  set("long", @LONG
一個賣酒的老頭，看他紅紅的鼻子，就知道他平時也喜歡來兩杯。
LONG);
  set("attitude", "friendly");
  set("combat_exp",230);
  set("inquiry", ([
    "冰清冽酒"    :  (: ask_wine :),
    "十錦琺瑯杯"  :  (: ask_cup :),
    "烈酒"        :  (: ask_liqueur :),
  ]) );
  set("greeting_msg", ({
    "老頭說道: 好喝的酒喔!\n",
    "老頭說道: 來盤花生下酒如何?\n",
  }) );
  setup();
}

string ask_wine()
{
  object me=this_player();

  if(me->query("doctor/ask_flor")==1)
  {
    command("haha");
    command("say 我猜猜...是任大少爺要你來的吧？");
    command("say 呵呵...每次都找別人來幫他買酒...");
    command("say 更怪的他還一定要用十錦琺瑯杯來喝...");
    command("say 不如這樣，你去找出琺瑯杯...然後我來釀造二鍋頭...");
    command("say 咱們分頭進行如何...好！既然沒異議，那就這樣說定囉！");
    me->delete("doctor/ask_flor");
    me->set("doctor/ask_cup",1);
    return "";
  }
}

string ask_cup()
{
  object me=this_player();

  if(me->query("doctor/ask_cup")==1)
  {
    command("think");
    command("say 這...我是有聽說在王家有不少十錦琺瑯杯...");
    command("say 但我不知道在哪就是了...");
    command("hoho");
    me->delete("doctor/ask_cup");
    me->set("doctor/find_cup",1);
    return "";
  }
}

int accept_object(object me, object ob)
{
  if(me->query("doctor/get_cup") && ob->query("id")=="ten-cup")
  {
    destruct(ob);
    command("nod "+me->query("id"));
    command("say 沒錯！就是這玩意兒...");
    command("say 我酒也好了...你等等，我來去斟酒...");
    command("say 偌！拿去...");
    command("say 別讓任大少爺久候了...快去...");
    ob=new("/open/doctor/obj/wine");
    ob->move(me);
    me->delete("doctor/get_cup");
    me->set("doctor/get_wine",1);
    return 1;
  }
}

string ask_liqueur()
{
  object me = this_player(),ob;
  if(!me->query_temp("quests/bonze/food/start")) return "你在問什麼我怎麼聽不懂。"; //食材任務判斷失敗時
  if (!me->query_temp("quests/bonze/food/liqueur")) //未領烈酒時
  {
    command("say 呵呵，竟然還有人知道我這老傢伙釀的酒呀。");
    command("say 今天我很高興，這瓶就讓你嘗鮮吧。");
    message_vision("紅鼻子老人硬是將手中喝了一半的烈酒塞在$N懷裡。\n",me);
    ob=new("/open/bonze/food_quest/liqueur");
    ob->set_temp("quests/bonze/food",1); //為使道具不可離線=限制玩家無限儲存道具在倉庫(離線角色)的作法
    ob->move(me);
    me->set_temp("quests/bonze/food/liqueur",1); //限制玩家此階段只能領取一次
  }
  else {
    command("say 我今天太高興了，改天你有空再來找我喝酒吧。");
  }
  return"";
}
