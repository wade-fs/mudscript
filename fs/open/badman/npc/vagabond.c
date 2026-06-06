// vagabond.c by oda
//更新天賦的判斷、道具的路徑與顏色語法的調整 by blazakira 2010/11/8

#include "/open/open.h"
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("市井無賴", ({ "vagabond" }) );
  set("gender", "男性");
  set("age", 20);
  set("attitude", "badman");
  set("long", "他全身髒兮兮的，還是別太靠近比較好。\n");
  set("combat_exp", 500);
  set_skill("dodge", 10);

  set("chat_chance", 4);
  set("chat_msg", ({
    }));

  setup();
  carry_object("/open/badman/obj/short_sword")->wield();
}

void greeting(object who)
{
  object ob = this_object();
  if( !who || environment(who)!=environment() ) return;

  tell_object(who, "市井無賴跌跌撞撞的向你走來，像是沒長眼睛似的撞了你一下。\n");
  tell_room(environment(ob),"市井無賴一不小心在$N的身上撞了一下。\n",who);
  command("say 對不起，對不起！"+RANK_D->query_respect(who)+"請您原諒。");
  if( random(5)>2 ) {
    if( who->can_afford(1000) ) {
      who->pay_money(1000);
      message_vision("市井無賴慌慌張張的躲到一旁去。\n", who);
      ob->pay_player(1000);
    }
  }
  if (who->query("quests/steal",1)) //遇過公會老大後 強運(kar >= 30)或有解謎成功就拿的到
  {
    if (!present("lucky-neck",who))
    {
      new("/autoload/badman/ste.c")->move(who);
      message_vision(HIC + "市井無賴說道﹕哎呀，你是"+who->query("name")+"吧？
　　　　　　　有個少年說你掉了這鍊條，叫我拿給你！\n" + NOR,who);
    }
  }
/*//已更新天賦的判斷 與物件幸運鍊條(lucky-neck)並未開啟 加上前述判斷優先於本判斷 所以本段判斷暫時忽略 by blazakira
  if (who->query("marks/kardie",1))
  {
    if(present("lucky-neck",who)) return ;
    message_vision(HIC + "哎呀，你是"+who->query("name")+"吧？
有個少年說你掉了東西，要我把這鍊條還給你！" + NOR,who);
    new("/autoload/badman/ste.c")->move(who);
    who->delete("marks/kardie");
  }*/
/*//查不到who->query("marks/fish",1)所代表的意義 所以暫時關閉 by blazakira 2010/11/8
  if (who->query("kar")==30 && who->query("quests/steal",1))
  {
    if (who->query("marks/fish",1))
    {
    }
    else {
      message_vision(HIC + "唉呀!你是"+who->query("name")+"吧?
有個少年叫我把這東西給你." + NOR,who);
      new("/autoload/badman/ste.c")->move(who);
      who->set("marks/fish",1);
    }
  }*/
}
